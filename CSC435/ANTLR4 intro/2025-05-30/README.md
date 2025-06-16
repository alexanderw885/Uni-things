#### Some ANTLR4 notes connected to `SmallLang`

##### `ANTLR4` care and feeding

Everything below assumes ANTLR4.13 and Java 21

* ANTLR4.13: Find Java binaries jar here -- `https://www.antlr.org/download.html`

* JAR file must be in your classpath.
`https://stackoverflow.com/questions/8084926/including-jar-files-in-class-path`

* If you are using Visual Studio Code, then ensure `CLASSPATH` is
properly configured in the `JAVA PROJECTS` panel.

* ANTLR tool: `java org.antlr.v4.Tool` -- alias this to `antlr4`

* ANTLR testrig: `java org.antlr.v4.gui.TestRig` -- alias this to
`grun`


##### Write `SmallLang.g4`

* Ensure that `#<annotation>` is used with productions to ensure that
customer visitors are created, i.e., avoids the tedium of writing
code to figure out which of the RHS productions was chosen when the
LHS non-terminal was parsed.)


##### Create the parser, default visitor

`antlr4 SmallLang.g4 -visitor -no-listener`

(Note: `antlr4 SmallLang.g4` -- that is, no further arguments -- would
generate the lexer/parser with listeners and no visitors.)


##### Compile all the Javas

`javac *.java`


##### Test the parser

`grun SmallLang prog -tokens tests/test00.ex`
`grun SmallLang prog -gui tests/test00.ex`

Note that:
* `SmallLang` is the grammar
* `prog` is the non-terminal with which the parser will start
* `-tokens` produces a detailed line-by-line report of parse 
productions, including line numbers from the input file (plus column
numbers).
* `-gui` produces a visualization of the parse tree
* `tests/test00.ex` is the text to be parsed; if no file is provided,
then input from `stdin` is used (i.e., the console/keyboard), so use
`<ctrl-D>` to end the input (i.e. `EOF`).


##### Write the AST node classes

Tedious, but doable. The node classes I've written here are:
* `ExprAddNode`
* `ExprIdentNode`
* `ExprIntegerNode`
* `ExprMultNode`
* `IdentNode`
* `StmtNode`

Well might you wonder why there is an `IdentNode` and an
`ExprIdentNode`. This is done to recognize that an identifer on the
left-hand side of an assignment is actually a different kind of beast
the one on the right-hand side. That is, a LHS identifier is meant to
refer to a location at which to **write**, while the RHS identifier is
meant to refer to a location from which to **read**.  These are two
distinctly different means of `IDENT` and this semantic is captured by
the two different kinds of nodes.

Also: The `print` method of each AST subclass outputs a representation
of what the node represents (from the program) with suitable levels of
indentation.


##### Test out a construction of the AST node classes

In this directory, `TestASTNode.java` explicitly builds up the AST for
the following `SmallLang` program:
```
a <- 3
b <- 4
c <- 5
d <- a + b * c
```


##### Write the customer visitor class

Here this is `MakeASTVisitor` whose sole purpose is to -- you guessed
it -- create the AST for programs in `SmallLang`.

There is ***a lot** going on in this Java class, and for too much for
this `README.md`. Hopefully you took good notes during the lecture.



##### Write the standalone program pulling together all threats

`ParseAndDump` creates the lexer and parser for `SmallLang` and
connects input (i.e., file or `stdin`) for processing.

The program then uses `MakeASTVisitor` to make an AST. The root of
that AST is returned from `build.visit(tree)` (where the parse tree is
constructed by ANTLR4). 
