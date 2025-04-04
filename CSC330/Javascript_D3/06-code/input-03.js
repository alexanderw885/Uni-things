window.addEventListener("load", makeDebugOutput);


function makeDebugOutput() {
    d3.json("languages.json").then(data => {
        const sortedLanguages = data.languages.sort((a, b) => a.year - b.year);
    
        /*
        const ul = d3.select("body")
            .append("ul");
    
        ul.selectAll("li")
            .data(sortedLanguages)
            .enter()
            .append("li")
            .text(d => `${d.year}: ${d.name}`);
        */
            d3.select("body")
            .append("ul")
            .selectAll("li")
            .data(sortedLanguages)
            .enter()
            .append("li")
            .text(d => `${d.year}: ${d.name}`);
    });
    /* Ignoring for now error case of missing `languages.json` */
}
