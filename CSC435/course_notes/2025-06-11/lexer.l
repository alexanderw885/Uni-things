%option noyywrap
%{
#include "y.tab.h" // Required for token definitions from yacc
#include <stdlib.h>
%}

%%
[0-9]+      { yylval.ival = atoi(yytext); return number; }
[+\-*/()]   { return yytext[0]; }
[ \t\n]     { /* skip whitespace */ }
.           { printf("Unexpected character: %s\n", yytext); }
%%
