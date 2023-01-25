<script>
    import Gauge from "../components/Gauge/Gauge.svelte";
    import StatusBox from "../components/StatusBox/StatusBox.svelte";
    import SettingsBox from "../components/SettingsBox/SettingsBox.svelte";

    import RightFoot from "$lib/RightFoot.png"
    import LeftFoot from "$lib/LeftFoot.png"

    let maxLeft = 0
    let maxRight = 0

    let marginLeft = 0
    let marginRight = 0

    let isStarted = false

</script>

<style>

    @import url('https://fonts.googleapis.com/css2?family=Montserrat:wght@400;700&display=swap');
    
    :global(*) {
        font-family: 'Montserrat', sans-serif;
    }

    button {
        border:none;
        color:white;
        padding-left:25px;
        padding-right:25px;
        padding-top:10px;
        padding-bottom:10px;
        border-radius:10px;
        font-size:15pt;
    }
</style>

<h1>Walk x Nantes</h1>

<div style="width:80%;display:flex;justify-content:space-between;margin:auto;margin-top:50px;">
    <StatusBox connexionOk={false} balancesOk={false}/>
    <SettingsBox title="CIBLAGE" bind:left={maxLeft} bind:right={maxRight}/>
    <SettingsBox title="MARGE" />
</div>

<div style="display:flex;justify-content:center;margin-top:50px">
    <div style="text-align:center">
        <img src={LeftFoot} alt="Pied gauche"/>
        <Gauge percentage={15} max={maxLeft}/>
    </div>
    <div style="text-align:center">
        <img src={RightFoot} alt="Pied droit"/>
        <Gauge percentage={90} max={maxRight}/>
    </div>
</div>

<div style="text-align:center;margin-top:20px">
    {#if isStarted}
        <button style="background-color:#A10202" on:click={() => isStarted = false}>Stop</button>
    {:else}
        <button style="background-color:#679289" on:click={() => isStarted = true}>Start</button>
    {/if}
</div>