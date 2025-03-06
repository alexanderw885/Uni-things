function makeList() {
    var vs = [ "from East", "to West", "at Home", "is Best" ];

    d3.select( "body" )
        .append( "ul" ).selectAll( "li" ) // appends unordered list, then selects all ordered lists. this selection is empty
        .data( vs ).enter() // the enter() is saying "make the following for each item in data without a list tag"
        .append( "li" ).text( function(d) { return d } ); // create a list tag, give it the text in vs

        /* `d => d` is identical to `function(d) { return d }` */
}
