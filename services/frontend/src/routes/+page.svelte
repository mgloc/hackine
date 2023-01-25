<script>
    import Gauge from "../components/Gauge/Gauge.svelte";
</script>

<style>

    @import url('https://fonts.googleapis.com/css2?family=Montserrat:wght@400;700&display=swap');
    
    :global(h1) {
        font-family: 'Montserrat', sans-serif;
    }
</style>

<h1>Welcome to SvelteKit</h1>
<p>Visit <a href="https://kit.svelte.dev">kit.svelte.dev</a> to read the documentation</p>


<Gauge percentage={35} max={50}/>
<Gauge percentage={90} max={50}/>