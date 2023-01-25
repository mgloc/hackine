
#include <HX711_ADC.h>
#include "Plotter.h"
#if defined(ESP8266) || defined(ESP32) || defined(AVR)
#include <EEPROM.h>
#endif

// pins cell left
const int left_cell_dout = 3;
const int left_cell_sck = 2;
// pins cell left
const int right_cell_dout = 5;
const int right_cell_sck = 4;

// HX711 constructor:
HX711_ADC LeftCell(left_cell_dout, left_cell_sck);
HX711_ADC RightCell(right_cell_dout, right_cell_sck);

// calibration
float LeftCalibrationValue;
float RightCalibrationValue;

unsigned long t = 0;
unsigned long stabilizingtime = 2000;

void calibrate()
{
    Serial.println("***");
    Serial.println("Start calibration:");

    LeftCell.tare();
    RightCell.tare();
    if (LeftCell.getTareStatus() && RightCell.getTareStatus())
    {
        Serial.println("Tared");
    }
    else
    {
        Serial.println("Tare failed");
        exit(0);
    }

    Serial.println("MASS");
    float known_mass = 0;
    boolean _resume = false;
    while (!_resume)
    {
        LeftCell.update();
        if (Serial.available() > 0)
        {
            known_mass = Serial.parseFloat();
            if (known_mass != 0)
            {
                Serial.println("OK");
                _resume = true;
            }
        }
    }
    Serial.println("Mass entered: " + String(known_mass));
    Serial.println("LEFT");
    _resume = false;
    while (!_resume)
    {
        LeftCell.update();
        if (Serial.available() > 0)
        {
            if (Serial.available() > 0)
            {
                char inByte = Serial.read();
                if (inByte == '\n')
                {
                    LeftCell.refreshDataSet();                                     // refresh the dataset to be sure that the known mass is measured correct
                    LeftCalibrationValue = LeftCell.getNewCalibration(known_mass); // get the new calibration value
                    _resume = true;
                }
            }
        }
    }
    Serial.println("RIGHT");
    _resume = false;
    while (!_resume)
    {
        RightCell.update();
        if (Serial.available() > 0)
        {
            if (Serial.available() > 0)
            {
                char inByte = Serial.read();
                if (inByte == '\n')
                {
                    RightCell.refreshDataSet();                                      // refresh the dataset to be sure that the known mass is measured correct
                    RightCalibrationValue = RightCell.getNewCalibration(known_mass); // get the new calibration value
                    _resume = true;
                }
            }
        }
    }

    Serial.println("End calibration");
}

void setup()
{

    Serial.begin(9600);
    delay(10);
    Serial.println();
    Serial.println("Starting...");

    LeftCell.begin();
    RightCell.begin();

    // LeftCell.setReverseOutput();
    LeftCell.start(stabilizingtime, true);
    RightCell.start(stabilizingtime, true);

    if (LeftCell.getTareTimeoutFlag() || LeftCell.getSignalTimeoutFlag())
    {
        Serial.println("[LEFT] Timeout, check MCU>HX711 wiring and pin designations");
        exit(1);
    }
    else if (RightCell.getTareTimeoutFlag() || RightCell.getSignalTimeoutFlag())
    {
        Serial.println("[RIGH] Timeout, check MCU>HX711 wiring and pin designations");
        exit(1);
    }
    else
    {
        // default calibration value is 1.0
        LeftCell.setCalFactor(1.0);
        RightCell.setCalFactor(1.0);
        Serial.println("Startup is complete");
    }
    while (!LeftCell.update() || !RightCell.update())
        ;
    calibrate(); // start calibration procedure
}

void sendData(float left, float right)
{

    Serial.print("D:");
    Serial.print(left);
    Serial.print(":");
    Serial.println(right);
}

void loop()
{
    const int serialPrintInterval = 0; // increase value to slow down serial print activity

    if (LeftCell.update() || RightCell.update())
    {
        if (millis() > t + serialPrintInterval)
        {
            float left = LeftCell.getData();
            float right = RightCell.getData();
            sendData(left, right);
            t = millis();
        }
    }
}
