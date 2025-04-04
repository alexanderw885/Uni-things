function makeList() {
    var vs = [ "from East", "to West", "at Home", "is Best" ];

    d3.select( "body" )
        .append( "ul" ).selectAll( "li" )
        .data( vs ).enter()
        .append( "li" ).text( function(d) { return d } );

        /* `d => d` is identical to `function(d) { return d }` */
}
