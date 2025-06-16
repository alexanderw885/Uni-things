grammar SmallLang;

prog:   stat+ ;

stat:   IDENT '<-' expr NL  #statementAssign
    |   NL                  #statementBlank
    ;

expr:   expr '*' expr       #exprMult
    |   expr '+' expr       #exprAdd
    |   '(' expr ')'        #exprBracketed
    |   INTEGER             #exprInt
    |   IDENT               #exprId
    ;

IDENT : [a-z]+ ;         // Only lower-case permitted for identifiers
INTEGER : ('-')?[0-9]+ ; // Negative ints possible
NL : '\r'? '\n' ;        // Include possibility of Windows text files
WS : [ \t]+ -> skip ;    // Ignore whitespace