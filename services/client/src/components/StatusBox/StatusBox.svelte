<script>
	export let connexionOk = true
	export let balancesOk = false 


	const greentickUrl = "./images/greentick.svg"
	const redcrossUrl = "./images/redcross.svg"
</script>

<div class="main">
	<h2>STATUS</h2>
	<div class="content">
		<div class="el">
			<h3>Balances</h3>
			<img src={balancesOk ? greentickUrl : redcrossUrl} alt="OK" width="16px">
		</div>
		
		<div class="el">
			<h3>Connexion</h3>
			<img src={connexionOk ? greentickUrl : redcrossUrl} alt="OK" width="16px">
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
</style>
