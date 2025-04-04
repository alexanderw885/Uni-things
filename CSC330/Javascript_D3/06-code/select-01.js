window.addEventListener("load", setup);


function setup() {
    d3.select( "#trigger" )
        .on( "click", makeSelectExample);
}


function makeSelectExample() {
    /*
    d3.selectAll( "p" ).selectAll( "b" )
        .style("color", "blue");
        */
    d3.selectAll( "b" ).style("color", "green");

    d3.select( "#id123" ).select( "circle" )
        .attr( "r", function() { return +d3.select(this).attr("r") + 10; } );
}
