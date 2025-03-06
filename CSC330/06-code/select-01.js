window.addEventListener("load", setup);


function setup() {
    d3.select( "#trigger" )
        .on( "click", makeSelectExample);
}


function makeSelectExample() {
    d3.selectAll("b").style("color", "red") // Makes all bold tagged objects red

    d3.selectAll( "p" ).select( "b" ) // for all objects with <p>, select the first with <b>
        .style("color", "blue"); // make them blue

    // Note the order of operations, the second line overwrites the first line

    d3.select( "#id456" ).selectAll( "circle" ) // in the object with id456, select all the circles
        .attr( "r", function() { return +d3.select(this).attr("r") + 10; } ); // increases radius r by 10
}
