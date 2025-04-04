
window.addEventListener("load", makeKeys);

function makeKeys() {
    var ds1 = [["Mary", 1], ["Jane", 4], ["Anne", 2], ["Bob", 4]];
    var ds2 = [["Anne", 5, "yellow"], ["Jane", 3, "purple"]];

    var scX = d3.scaleLinear().domain([0, 6]).range([50, 300]);
    var scY = d3.scaleLinear().domain([0, 3]).range([50, 150]);

    var j = -1, k = -1;

    var svg = d3.select( "#key" );

    svg.selectAll( "text" )
        .data(ds1).enter().append( "text" )
        .attr( "x", 20).attr( "y", d=>scY(++j) ).text( d=>d[0] );

    svg.selectAll("circle").data(ds1).enter().append( "circle" )
        .attr( "r", 5).attr( "fill", "red")
        .attr( "cx", d=>scX(d[1]) ).attr( "cy" , d=>scY(++k)-5 );

    svg.on( "click", function() {
        var cs = svg.selectAll( "circle" ).data( ds2, d=>d[0] );

        // cs.transition().duration(2000).attr("fill", d=>d[2])
        cs.transition().duration(1000)
            .attr("cx", d=>scX(d[1]) )
            .attr("fill", d=>d[2]);
        cs.exit().attr( "fill", "blue" );
    });
}