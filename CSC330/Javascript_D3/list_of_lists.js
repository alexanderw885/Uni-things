window.addEventListener("load", makeList2);

function makeList1() {
    // List of svg object methods

    const cols = [["monkey", "red"], ["elephant", "blue"], ["shrimp", "green"]];

    d3.select("body").append("ul").selectAll("li")
    .data(cols).enter()
    .append("svg")
    .attr("width", 400).attr("height", 100)
    .attr("style", "background: lightgrey").attr("id", d => d[0])

    cols.forEach((item, index) => {
        d3.select("#" + item[0]).append("text")
        .attr("x", 10).attr("y", 50)
        .text(item[0]);

        d3.select("#" + item[0]).append("rect")
        .attr("x", 100).attr("y", 15)
        .attr("width", 285).attr("height", 60)
        .attr("fill", item[1]);
    })


}

function makeList2() {
    // groups of data method
    const cols = [["monkey", "red"], ["elephant", "blue"], ["shrimp", "green"]];
    d3.select("body").selectAll("g")
    .data(cols).enter().append("g").attr("id", d => d[0]);

    cols.forEach((item, index) => {
        d3.select("#" + item[0])
        .append("rect")
        .attr("x", 100).attr("y", 20)
        .attr("width", 50).attr("height", 50);
    })
}