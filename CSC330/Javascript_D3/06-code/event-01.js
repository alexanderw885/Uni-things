window.addEventListener( "load", makeCoordinates );


function makeCoordinates() {
    var text = d3.select( "#coords" ).append( "text" );
    var svg = d3.select( "#coords" ).attr( "cursor", "crosshair" )
        .on( "mousemove", function(event) {
            var pt = d3.pointer(event, svg.node() );
            text.attr( "x", 18+pt[0] ).attr( "y", 6+pt[1] )
                .text( "(" + pt[0] + ", " + pt[1] + ")" );
        } );
}


