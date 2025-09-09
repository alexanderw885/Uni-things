#### Compiling the calculator.

**Assumptions**
* `lex` is installed
* `yacc` is installed
* (If the pair of utilities is `flex` and `bison`, that should work as
well.)
* And, of course, assuming `gcc` or `clang` is installed.


**Building the calculator**
```
lex lexer.l
yacc -d calculator.yacc
gcc lex.yy.c y.tab.c -o calculator
```

**Running the calculator**
Just use `./calculator` and type in the integer expression at the
command line. Press `<ctrl>-d` to end input.

```
./calculator
29 / 2 + 5
^D
value = 19
```
