
<script>
    export let percentage = 0;
    export let max = 0;
    export let bottomMargin = 0;
    export let highMargin = 0;

</script>


<div class="main">
    <svg xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="37 -5 140 120" width="280" height="240">
        <defs>
            <marker style="fill:#A10202" id="redArrow" markerWidth="5" markerHeight="3.5" 
            refX="0" refY="1.75" orient="auto">
              <polygon points="0 0, 5 1.75, 0 3.5" />
            </marker>
            <marker style="fill:#679289" id="greenArrow" markerWidth="5" markerHeight="3.5" 
            refX="0" refY="1.75" orient="auto">
              <polygon points="0 0, 5 1.75, 0 3.5" />
            </marker>
        </defs>
        <line style="stroke:{percentage >= bottomMargin && percentage <= highMargin ? "#679289" : "#A10202"}"
            x1="97"
            y1="55"
            x2="{97 - 20 * (Math.cos(Math.PI * 1.5 * (percentage / 100) - Math.PI/4))}"
            y2="{55 - 20 * (Math.sin(Math.PI * 1.5 * (percentage / 100) - Math.PI/4))}"
            stroke="#000"
            stroke-width="3"
            marker-end="url(#{percentage >= bottomMargin && percentage <= highMargin ? "greenArrow" : "redArrow"})" />

        <path class="grey" d="M55,90 A55,55 0 1,1 140,90" style="fill:none;"/>
        <path class="inner" d="M55,90 A55,55 0 1,1 140,90" style="fill:none;stroke-dashoffset:{248 * (1 - percentage / 100)};stroke:{percentage >= bottomMargin && percentage <= highMargin ? "#679289" : "#A10202"}"/>
        <line stroke="black"
            x1="{97 - 50 * (Math.cos(Math.PI * 1.5 * (bottomMargin / 100) - Math.PI/4))}"
            y1="{55 - 50 * (Math.sin(Math.PI * 1.5 * (bottomMargin / 100) - Math.PI/4))}"
            x2="{97 - 60 * (Math.cos(Math.PI * 1.5 * (bottomMargin / 100) - Math.PI/4))}"
            y2="{55 - 60 * (Math.sin(Math.PI * 1.5 * (bottomMargin / 100) - Math.PI/4))}"/>
        <line stroke="black"
            x1="{97 - 50 * (Math.cos(Math.PI * 1.5 * (highMargin / 100) - Math.PI/4))}"
            y1="{55 - 50 * (Math.sin(Math.PI * 1.5 * (highMargin / 100) - Math.PI/4))}"
            x2="{97 - 60 * (Math.cos(Math.PI * 1.5 * (highMargin / 100) - Math.PI/4))}"
            y2="{55 - 60 * (Math.sin(Math.PI * 1.5 * (highMargin / 100) - Math.PI/4))}"/>
        
        <circle fill="{percentage >= bottomMargin && percentage <= highMargin ? "#679289" : "#A10202"}"cx="97" cy="55" r="5"/>

        <text
            x="{95 - 40 * (Math.cos(Math.PI * 1.5 * (bottomMargin / 100) - Math.PI/4))}"
            y={55 - 40 * (Math.sin(Math.PI * 1.5 * (bottomMargin / 100) - Math.PI/4))}
            style="font-size:5pt"
            text-anchor="middle"
            dominant-baseline="middle">
            {bottomMargin} %
        </text>
        <text
            x="{95 - 40 * (Math.cos(Math.PI * 1.5 * (highMargin / 100) - Math.PI/4))}"
            y="{55 - 40 * (Math.sin(Math.PI * 1.5 * (highMargin / 100) - Math.PI/4))}"
            style="font-size:5pt"
            text-anchor="middle"
            dominant-baseline="middle">
            {highMargin} %
        </text>
    </svg>
    <h1>{percentage}%</h1>
</div>

<style>
    path {
        stroke-linecap: round;
        stroke-width: 10;
    }
      
    .grey {
        stroke: #A6A6A6;
    }
      
    .inner {
        stroke: #e33800;
        stroke-dasharray: 248;
    }
    
    .main {
        width:400px;
        text-align:center;
    }
</style>

