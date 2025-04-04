window.addEventListener("load", makeDebugOutput);


function makeDebugOutput() {
    d3.json("languages.json").then( data => {
        data.paradigms.forEach( paradigm => {
            console.log(paradigm);
        }); 
    }).catch( error => {
        console.error("Error loading JSON:", error);
    });
}
