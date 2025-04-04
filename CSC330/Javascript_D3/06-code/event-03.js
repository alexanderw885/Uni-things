window.addEventListener( "load", makeToggleBox );


function makeToggleBox() {
    d3.select("#toggleText")
        .style("cursor", "pointer")
        .style("color", "blue");

    var svg = d3.select("body").append("svg")
        .attr("width", 200)
        .attr("height", 200);

    var rect = svg.append("rect")
        .attr("id", "redBox")
        .attr("x", 50)
        .attr("y", 50)
        .attr("rx", 5)
        .attr("ry", 5)
        .attr("width", 100)
        .attr("height", 100)
        .attr("fill", "red")
        .style("visibility", "hidden");

    d3.select("#toggleText").on("click", function() {
        var isVisible = rect.style("visibility") === "visible";
        rect.style("visibility", isVisible ? "hidden" : "visible");
    });
}


