function makeDemo() {
    d3.tsv("demo_data/examples/examples-multiple.tsv")
    .then(function(data) {
        var pxX = 600
        var pxY = 300

        // Linearly scales X values from 50 to pxX
        // I'm using 10 instead of 0 to make sure the entire point is visible
        var scX = d3.scaleLinear()
          .domain(d3.extent(data, d => d["x"]))
          .range( [10, pxX])

          // Linearly scales Y values in first dataset from 0 to pxY
          // Note how the range is reversed compared to scX.
          // this is because low Y values in svg are on top.
          // to make larger Y values higher up, we need to scale them
          // to smaller values
        var scY1 = d3.scaleLinear()
          .domain(d3.extent(data, d => d["y1"]))
          .range([pxY, 10])

        var scY2 = d3.scaleLinear()
          .domain(d3.extent(data, d => d["y2"]))
          .range([pxY, 10])
        
        // Pairing data with svg
        // Creating the points
        d3.select("svg")
            .append("g").attr("id", "ds1") // give the SVG a group labelled ds1
            .selectAll("circle")
            .data(data).enter().append("circle")
            .attr("r", 5).attr("fill", "green")
            .attr("cx", d => scX(d["x"]))
            .attr("cy", d => scY1(d["y1"]));

        d3.select("svg").append("g").attr("id", "ds2")
          .selectAll("circle")
          .data(data).enter().append("circle")
          .attr("r", 5).attr("fill", "blue")
          .attr("cx", d => scX(d["x"]))
          .attr("cy", d => scY2(d["y2"]));

        var lineMaker = d3.line()
          .x(d => scX(d["x"]))
          .y(d => scY1(d["y1"]));
        d3.select("#ds1")
          .append("path")
          .attr("fill", "none")
          .attr("stroke", "green")
          .attr("d", lineMaker(data))

        // Set line up for second dataset
        lineMaker.y(d => scY2(d["y2"]));
        d3.select("#ds2")
        .append("path")
        .attr("fill", "none")
        .attr("stroke", "blue")
        .attr("d", lineMaker(data))
        

        // Connecting the points

    });
}