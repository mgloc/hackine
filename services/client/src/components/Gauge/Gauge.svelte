
<script>
    export let percentage = 0;
    export let max = 0;

    const getX = () => {
        return 97 - 30 * (Math.cos(Math.PI * 1.5 * (percentage / 100) - Math.PI/4))
    }

    const getY = () => {
        return 55 - 30 * (Math.sin(Math.PI * 1.5 * (percentage / 100) - Math.PI/4))
    }
</script>


<div class="main">
    <svg xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="37 -5 120 100" width="240" height="200">
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
        <line style="stroke:{percentage > max ? "#A10202" : "#679289"}" x1="97" y1="55" x2="{getX()}" y2="{getY()}" stroke="#000" stroke-width="3" marker-end="url(#{percentage > max ? "redArrow" : "greenArrow"})" />
        <path class="grey" d="M55,90 A55,55 0 1,1 140,90" style="fill:none;"/>
        <path class="inner" d="M55,90 A55,55 0 1,1 140,90" style="fill:none;stroke-dashoffset:{248 * (1 - percentage / 100)};stroke:{percentage > max ? "#A10202" : "#679289"}"/>
        <circle fill="{percentage > max ? "#A10202" : "#679289"}" cx="97" cy="55" r="5"/>
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

