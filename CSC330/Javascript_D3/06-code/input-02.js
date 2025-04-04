window.addEventListener("load", makeDebugOutput);


function makeDebugOutput() {
    d3.json("languages.json").then( data => {
        const sortedLanguages = data.languages.sort( (a, b) => a.year - b.year );

        sortedLanguages.forEach(language => {
            console.log(`${language.name}: ${language.year}`);
        });
    });
}
