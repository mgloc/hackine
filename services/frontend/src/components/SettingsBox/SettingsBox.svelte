<script>
	export let left = 0
	export let right = 0 
    export let title = ""

</script>

<div class="main">
	<h2>{title}</h2>
	<div class="content">
		<div class="el">
			<h3>Jambe droite</h3>
            <div class="settings">
                <button on:click={() => {if(left > 0) left -= 5}}>-</button>
                {left}%
                <button on:click={() => {if(left < 100) left += 5}}>+</button>
            </div>
		</div>
		
		<div class="el">
			<h3>Jambe gauche</h3>
            <div class="settings">
                <button on:click={() => {if(right > 0) right -= 5}}>-</button>
                {right}%
                <button on:click={() => {if(right < 100) right += 5}}>+</button>
            </div>
		</div>
	</div>
</div>

<style>
	.main {
		width:300px;
		text-align: center;
		background: linear-gradient(180deg, rgba(217, 217, 217, 0.2) 0%, rgba(217, 217, 217, 0) 100%);
		border-radius: 39px;
		padding-top:10px;
		padding-bottom:10px
	}

	h2 {
		letter-spacing: 8pt;
		font-size:16pt
	}

	.content {
		margin:auto;
		margin-top:10px;
		width:80%;
	}

	.el {
		display:flex;
		justify-content: space-between;
	}

	.el h3 {
		margin-top:0;
		font-weight:400
	}
    
    button {
        border:none;
        background-color: transparent;
        font-weight:800;
        font-size:15pt
    }
</style>
