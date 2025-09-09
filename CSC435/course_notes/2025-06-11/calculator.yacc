%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
void yyerror(const char *s);
%}

%union {
    int ival;
}

%token <ival> number
%type <ival> Expr

%left '+' '-'
%left '*' '/'
%right UMINUS
%%
Goal:
    Expr { printf("value = %d\n", $1); }
    ;
Expr:
      Expr '+' Expr       { $$ = $1 + $3; }
    | Expr '-' Expr       { $$ = $1 - $3; }
    | Expr '*' Expr       { $$ = $1 * $3; }
    | Expr '/' Expr       { $$ = $1 / $3; }
    | '(' Expr ')'        { $$ = $2; }
    | '-' Expr %prec UMINUS { $$ = -$2; }
    | number              { $$ = $1; }
    ;
%%
int main(void) {
    return yyparse();
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
