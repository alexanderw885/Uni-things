`IRPlay.java`
---
This program attempts to make concrete (and to illustrate) some of the ideas in lecture slides concerning the generation of an intermediate representation (IR).

The syntax of the program also attempts to hew closely to the style of the slides. There is, however, one significant difference.
* **Where the slides refer to `getStmt`, the code refers to both `getStmt` and `getStmts`**
* `getStmt` works with an individual statements
* `getStmts` works with a sequence a one or more statements such as would be encountered in a block (i.e., for `while` or for `if-then-else`).d

In order to get this work work without a parser, however, an AST has to be hardcoded -- which is a tedious and error-prone process. Therefore I have provided the ASTs for only two Mogensen-ish programs. The first is made using `build_program_1`:
```
f := 1
n := 7
while n > 0
    f := f * n
    n := n - 1
```
and the second is made using `build_program_2`:
```
x := 2 + y
if x < y then
   x := x + y
   y := y - 1
else
    x := x - 1
    y := y + 1
y := y * x
```

Each of `build_program_1()` and `build_program_2()` are given a `HashSet<String, String>` as a single parameter -- this acts as a symbol table. To help make control-flow a bit more readable, only `int` types are used for now. Maybe in a future version I'll write some code to work with not only `floats` but to also provide the necessary code for conversion from `int` to `float` as would be needed by some arithmetic instructions.

And a few further comments:
* Not all conditions are implemented, nor all binops. I really should implement the NOT condition because it is so funky, but that can be an exercise for you.
* The `AST` class is constructed in a rather haywire-and-baling-twine manner, especially the constructors. However, hopefully the comments help indicate to you which does what. You're encouraged to create your own ASTs for exploration of the kind of IR described in the text.
* The `IR` class is not really explained at all in the lecture slides, so hopefully the code here serves to provide some of that explanation.