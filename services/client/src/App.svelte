<script>
	import Gauge from "./components/Gauge/Gauge.svelte";
	import StatusBox from "./components/StatusBox/StatusBox.svelte";
	import SettingsBox from "./components/SettingsBox/SettingsBox.svelte";

	import ioClient, { io } from "socket.io-client";
	import { onMount } from "svelte";

	const endpoint = "http://localhost:5000";

	const socket = ioClient(endpoint);

	// Foot variables
	let maxLeft = 100;
	let maxRight = 15;

	let marginLeft = 20;
	let marginRight = 5;

	let massRight = 0;
	let massLeft = 0;

	let patientWeight = 60;
	$: notNullPatientWeight = patientWeight > 0 ? patientWeight : 1;

	$: leftPercentage =
		(massLeft / notNullPatientWeight) * 100 > 100
			? 100
			: Math.round((massLeft / notNullPatientWeight) * 100);
	$: rightPercentage =
		(massRight / notNullPatientWeight) * 100 > 100
			? 100
			: Math.round((massRight / notNullPatientWeight) * 100);

	let isStarted = false;

	function start() {
		isStarted = true;
		socket.on("leftWeight", (p) => {
			p = p >= 0 ? p : 0;
			massLeft = Math.round(p / 1000);
		});
		socket.on("rightWeight", (p) => {
			p = p >= 0 ? p : 0;
			massRight = Math.round(p / 1000);
		});
	}

	function end() {
		isStarted = false;
		socket.removeAllListeners();
	}
</script>

<div style="margin: 0 5% 0 5%;">
	<h1>Walk x <span style="color:#679289">Nantes</span></h1>

	<div
		style="display:flex;justify-content:space-between;margin:auto;margin-top:50px;"
	>
		<StatusBox connexionOk={true} balancesOk={true} balancesMainsOk={false} />
		<SettingsBox title="CIBLAGE" bind:left={maxLeft} bind:right={maxRight} />
		<SettingsBox
			title="MARGE"
			bind:left={marginLeft}
			bind:right={marginRight}
		/>
	</div>
	<div style="display:flex;justify-content: center;margin:0">
		<div style="display:flex;flex-direction: column;align-items: center;">
			<h3 style="font-weight:400;">Patient weight :</h3>
			<div style="display:flex;flex-direction: row;gap:10px">
				<input
					style="width:60px;text-align: center;"
					type="number"
					min="1"
					max="999"
					bind:value={patientWeight}
				/>
				<h3 style="font-weight:400;">kg</h3>
			</div>
		</div>
	</div>

	<div style="display:flex;justify-content:center;margin-top:10px">
		<div style="text-align:center;">
			<img
				src="./images/LeftHand.png"
				style="height: 90px;"
				alt="Pied gauche"
			/>
			<Gauge />
		</div>
		<div style="text-align:center;">
			<img
				src="./images/LeftFoot.png"
				style="height: 100px;"
				alt="Pied gauche"
			/>
			<Gauge
				percentage={leftPercentage}
				max={maxLeft}
				bottomMargin={Math.max(maxLeft - marginLeft, 0)}
				highMargin={Math.min(maxLeft + marginLeft, 100)}
			/>
		</div>
		<div style="text-align:center;">
			<img
				src="./images/RightFoot.png"
				alt="Pied droit"
				style="height: 100px;"
			/>
			<Gauge
				percentage={rightPercentage}
				max={maxRight}
				bottomMargin={Math.max(maxRight - marginRight, 0)}
				highMargin={Math.min(maxRight + marginRight, 100)}
			/>
		</div>
		<div style="text-align:center;">
			<img
				src="./images/RightHand.png"
				style="height: 90px;"
				alt="Pied gauche"
			/>
			<Gauge />
		</div>
	</div>

	<div style="text-align:center;margin-top:20px">
		{#if isStarted}
			<button style="background-color:#A10202" on:click={() => end()}
				>Stop</button
			>
		{:else}
			<button style="background-color:#679289" on:click={() => start()}
				>Start</button
			>
		{/if}
	</div>
</div>

<style>
	@import url("https://fonts.googleapis.com/css2?family=Montserrat:wght@400;700&display=swap");

	:global(*) {
		font-family: "Montserrat", sans-serif;
	}

	button {
		border: none;
		color: white;
		padding-left: 25px;
		padding-right: 25px;
		padding-top: 10px;
		padding-bottom: 10px;
		border-radius: 10px;
		font-size: 15pt;
	}
</style>
