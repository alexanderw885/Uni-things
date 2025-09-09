import java.util.*;

public class IRPlay {
    public static void main(String args[]) {
        System.out.println("Playground for IR generation ideas");

        HashMap<String, String>vtable1 = new HashMap<String, String>();
        vtable1.put("f", "int");
        vtable1.put("n", "int");
        IR ir1 = new IR(vtable1);
        AST program1 = build_program_1(vtable1);
        genStmts(program1, ir1);
        System.out.println();
        System.out.println("Mappings from globals to temps:");
        System.out.println(ir1.getVarsToTempsMappings());

        System.out.println("\n\n\n");
        HashMap<String, String>vtable2 = new HashMap<String, String>();
        vtable2.put("x", "int");
        vtable2.put("y", "int");
        IR ir2 = new IR(vtable2);
        AST program2 = build_program_2(vtable2);
        genStmts(program2, ir2);
        System.out.println();
        System.out.println("Mappings from globals to temps:");
        System.out.println(ir2.getVarsToTempsMappings());
        
    }

    public static AST build_program_1(HashMap<String, String>vtable) {
        AST program = new AST(Tags.Stmts);
        AST nextStmt;

        program.Stmts = new ArrayList<AST>();

        // f := 1
        nextStmt = new AST(Tags.Assign,
            new AST(Tags.Ident, "f"),
            new AST(Tags.Number, "1", Types.Int)
        );
        program.Stmts.add(nextStmt);

        // n := 7
        nextStmt = new AST(Tags.Assign,
            new AST(Tags.Ident, "n"),
            new AST(Tags.Number, "7", Types.Int)
        );
        program.Stmts.add(nextStmt);

        // f := f * n
        nextStmt =
            new AST(Tags.Assign,
                new AST(Tags.Ident, "f"),
                new AST(Tags.Multiply,
                    new AST(Tags.Ident, "f"),
                    new AST(Tags.Ident, "n")
                )
            );
        program.Stmts.add(nextStmt);

        // Body of while: f := f * n; n := n - 1;
        AST whileBody = new AST(Tags.Stmts);
        whileBody.Stmts = new ArrayList<AST>();
        // f := f * n
        nextStmt =
            new AST(Tags.Assign,
                new AST(Tags.Ident, "f"),
                new AST(Tags.Multiply,
                    new AST(Tags.Ident, "f"),
                    new AST(Tags.Ident, "n")
                )
            );
        whileBody.Stmts.add(nextStmt);
        nextStmt =
            new AST(Tags.Assign,
                new AST(Tags.Ident, "n"),
                new AST(Tags.Subtract,
                    new AST(Tags.Ident, "n"),
                    new AST(Tags.Number, "1", Types.Int)
                )
            );
        whileBody.Stmts.add(nextStmt);

        // while n > 0 ... do the body just immediately above.
        nextStmt =
            new AST(Tags.WhileLoop,
                new AST(Tags.GreaterThan,
                    new AST(Tags.Ident, "n"),
                    new AST(Tags.Number, "0", Types.Int)
                ),
                whileBody
            );

        program.Stmts.add(nextStmt);

        return program;
    }


public static AST build_program_2(HashMap<String, String>vtable) {
        AST program = new AST(Tags.Stmts);
        AST nextStmt;

        program.Stmts = new ArrayList<AST>();

        // x := 2 + y
        nextStmt =
            new AST(Tags.Assign,
                new AST(Tags.Ident, "x"),
                new AST(Tags.Multiply,
                    new AST(Tags.Number, "2", Types.Int),
                    new AST(Tags.Ident, "y")
                )
            );
        program.Stmts.add(nextStmt);

        // True body of if: x := x + y; y = y - 1;
        AST trueBody = new AST(Tags.Stmts);
        trueBody.Stmts = new ArrayList<AST>();
        // f := f * n
        nextStmt =
            new AST(Tags.Assign,
                new AST(Tags.Ident, "x"),
                new AST(Tags.Add,
                    new AST(Tags.Ident, "x"),
                    new AST(Tags.Ident, "y")
                )
            );
        trueBody.Stmts.add(nextStmt);
        nextStmt =
            new AST(Tags.Assign,
                new AST(Tags.Ident, "y"),
                new AST(Tags.Subtract,
                    new AST(Tags.Ident, "y"),
                    new AST(Tags.Number, "1", Types.Int)
                )
            );
        trueBody.Stmts.add(nextStmt);

        // False body of if: x := x - 1; y = y + 1;
        AST falseBody = new AST(Tags.Stmts);
        falseBody.Stmts = new ArrayList<AST>();
        nextStmt =
            new AST(Tags.Assign,
                new AST(Tags.Ident, "x"),
                new AST(Tags.Subtract,
                    new AST(Tags.Ident, "x"),
                    new AST(Tags.Number, "1", Types.Int)
                )
            );
        falseBody.Stmts.add(nextStmt);
        nextStmt =
            new AST(Tags.Assign,
                new AST(Tags.Ident, "y"),
                new AST(Tags.Add,
                    new AST(Tags.Ident, "y"),
                    new AST(Tags.Number, "1", Types.Int)
                )
            );
        falseBody.Stmts.add(nextStmt);

        // if x < y then trueBody else falseBody
        nextStmt =
            new AST(Tags.IfStmt,
                new AST(Tags.LessThan,
                    new AST(Tags.Ident, "x"),
                    new AST(Tags.Ident, "y")
                ),
                trueBody,
                falseBody
            );
        program.Stmts.add(nextStmt);

        // y := y * x
        nextStmt =
            new AST(Tags.Assign,
                new AST(Tags.Ident, "y"),
                new AST(Tags.Multiply,
                    new AST(Tags.Ident, "y"),
                    new AST(Tags.Ident, "x")
                )
            );
        program.Stmts.add(nextStmt);

        return program;
    }

    public static String genVariable(AST n, IR ir) {
        if (n.Tag != Tags.Ident) {
            n.dump();
            System.err.println("Expected Tags.Ident");
            System.exit(1);
        }

        if (ir.varToTemp.containsKey(n.Name)) {
            return ir.varToTemp.get(n.Name);
        }

        String type = ir.Vtable.get(n.Name);
        String tempVar = "PANIC";

        if (type == "int") {
            tempVar = ir.newIntTemp(n.Name);
        } else {
            tempVar = ir.newFloatTemp(n.Name);
        }

        return tempVar;
    }

    public static void genStmt(AST n, IR ir) {
        switch(n.Tag) {
            case Tags.Assign:
                String lhs = genVariable(n.Child[0], ir);
                String rhs = genExpr(n.Child[1], ir);
                ir.printLine("%s := %s", lhs, rhs);
                break;

            case Tags.WhileLoop:
                String beforeWhile = ir.newLabel();
                String bodyLabel   = ir.newLabel();
                String afterWhile  = ir.newLabel();
                ir.printLine("LABEL %s", beforeWhile);
                genConditional(n.Child[0], bodyLabel, afterWhile, ir);
                ir.printLine("LABEL %s", bodyLabel);
                genStmts(n.Child[1], ir);
                ir.printLine("GOTO %s", beforeWhile);
                ir.printLine("LABEL %s", afterWhile);
                break;

            case Tags.IfStmt:
                String thenLabel  = ir.newLabel();
                String elseLabel  = ir.newLabel();
                String afterLabel = ir.newLabel();
                genConditional(n.Child[0], thenLabel, elseLabel, ir);
                ir.printLine("LABEL %s", thenLabel);
                genStmts(n.Child[1], ir);
                ir.printLine("GOTO %s", afterLabel);
                ir.printLine("LABEL %s", elseLabel);
                genStmts(n.Child[2], ir);
                ir.printLine("LABEL %s", afterLabel);
                break;

            default:
                System.out.println("PANIC!!!");
                System.exit(1);
        }
    }

    public static void genStmts(AST stmt, IR ir) {
        for (AST s : stmt.Stmts) {
            genStmt(s, ir);
        }
    }

    public static String genExpr(AST n, IR ir) {
        String result = "PANIC?!";
        String left = "PANIC-LEFT?";
        String right = "PANIC-RIGHT?";

        switch(n.Tag) {
        case Tags.Number:
            if (n.Type == Types.Int) {
                result = ir.newIntTemp();
            } else {
                result = ir.newFloatTemp();
            }
            ir.printLine("%s := %s", result, n.Value);
            break;

        case Tags.Ident:
            result = ir.getVarToTemp(n.Name);
            if (result == null) {
                result = genVariable(n, ir);
            }
            break;

        case Tags.Add:
            // Assuming just ints for now.
            result = ir.newIntTemp();
            left = genExpr(n.Child[0], ir);
            right = genExpr(n.Child[1], ir);
            ir.printLine("%s := %s + %s", result, left, right);
            break;

        case Tags.Subtract:
            // Assuming just ints for now.
            result = ir.newIntTemp();
            left = genExpr(n.Child[0], ir);
            right = genExpr(n.Child[1], ir);
            ir.printLine("%s := %s - %s", result, left, right);
            break;

        case Tags.Multiply:
            // Assuming just ints for now.
            result = ir.newIntTemp();
            left = genExpr(n.Child[0], ir);
            right = genExpr(n.Child[1], ir);
            ir.printLine("%s := %s * %s", result, left, right);
            break;
        
        }

        return result;
    }

    public static void genConditional(AST n, String TL, String FL, IR ir) {
        String lhs, rhs;

        switch (n.Tag) {
        case Tags.GreaterThan:
            lhs = genExpr(n.Child[0], ir);
            rhs = genExpr(n.Child[1], ir);
            ir.printLine("IF %s>%s THEN %s ELSE %s", lhs, rhs, TL, FL);
            break;

        case Tags.LessThan:
            lhs = genExpr(n.Child[0], ir);
            rhs = genExpr(n.Child[1], ir);
            ir.printLine("IF %s<%s THEN %s ELSE %s", lhs, rhs, TL, FL);
            break;
        }
    }
}


class IR {
    int Next_label_name;
    int Next_int_name;
    int Next_float_name;
    HashMap<String, String> Vtable;
    HashMap<String, String> varToTemp;

    public IR(HashMap<String, String> vtable) {
        Next_label_name = Next_int_name = Next_float_name = 0;
        this.Vtable = vtable;
        this.varToTemp = new HashMap<String, String>();
    }


    public String getVarToTemp(String var) {
        if (varToTemp.containsKey(var)) {
            return varToTemp.get(var);
        } else {
            return null;
        }
    }

    public String newFloatTemp() {
        String result = "F" + Next_float_name;
        Next_float_name++;
        return result;
    }

    // Used when the temp is actually associated with
    // a variable in the original program text.
    public String newFloatTemp(String var) {
        String result = "F" + Next_float_name;
        Next_float_name++;
        varToTemp.put(var, result);
        return result;
    }

    public String newIntTemp() {
        String result = "T" + Next_int_name;
        Next_int_name++;
        return result;
    }

    // Used when the temp is actually associated with
    // a variable in the original program text.
    public String newIntTemp(String var) {
        String result = "T" + Next_int_name;
        Next_int_name++;
        varToTemp.put(var, result);
        return result;
    }

    public String newLabel() {
        String result = "L" + Next_label_name;
        Next_label_name++;
        return result;
    }

    // Written to deal with printLine being called with a
    // variable number of arguments -- plus it avoids a
    // dreadful list of nearly identical yet overriden methods.
    public void printLine(String format, String... args) {
        System.out.printf(format, (Object[]) args);
        System.out.println();
    }

    // Provided for pedagogical purposes. In the textbook, the
    // mappings from variables to temps is explicitly stated
    // in the text.
    public String getVarsToTempsMappings() {
        String result = "";
        String sep = "";

        for (String var : varToTemp.keySet()) {
            result += sep + var + " =:= " + varToTemp.get(var);
            sep = "\n";
        }

        return result;
    }
}


class Tags {
    public static final int UNKNOWN = 0;
    public static final int Ident = 1;
    public static final int Number = 2;
    public static final int Add = 3;
    public static final int Subtract = 4;
    public static final int Multiply = 5;
    public static final int Assign = 6;
    public static final int IfStmt = 7;
    public static final int WhileLoop = 8;
    public static final int Stmts = 9;
    public static final int LessThan = 10;
    public static final int GreaterThan = 11;
    public static final int AndAnd = 12;
    public static final int Not = 13;
    public static final int Equals = 14;
}

class Types {
    public static final int UNKNOWN = 0;
    public static final int Int = 1;
    public static final int Float = 2;
}


class AST {
    public AST Child[];
    public ArrayList<AST>Stmts;
    public int Tag;
    public String Name;
    public int Type;
    public String Value;

    public void dump() {
        System.out.println("Tag: " + Tag);
        System.out.println("Name: " + Name);
        System.out.println("Type: " + Type);
        System.out.println("Value: " + Value);
    }

    public AST(int Tag) {
        this.Tag = Tag;
    }

    // For AST elements such as a RHS expression in an assignment.
    public AST(int Tag, AST child_left, int Type) {
        this.Tag = Tag;
        this.Child = new AST[3];
        this.Type = Type;
        Child[0] = child_left;
        Child[1] = Child[2] = null;
    }

    // For AST elements such as binop expressions or even
    // a WHILE statement.
    public AST(int Tag, AST child_left, AST child_right) {
        this.Tag = Tag;
        this.Child = new AST[3];
        Child[0] = child_left;
        Child[1] = child_right;
        Child[2] = null;
    }

    // For AST elements such as the IF-THEN-ELSE statement
    public AST(int Tag, AST child_left, AST child_middle, AST child_right) {
        this.Tag = Tag;
        this.Child = new AST[3];
        Child[0] = child_left;
        Child[1] = child_middle;
        Child[2] = child_right;
    }

    // For AST elements such as a Number (int or float).
    // As a convenience the type of the Number is included.
    public AST(int Tag, String value, int type) {
        this.Tag = Tag;
        if (Tag == Tags.Number) {
            this.Value = value;
            this.Type = type;
        } else {
            this.Value = "ERROR";
            this.Type  = Types.UNKNOWN;
        }
    }

    // For AST elements such as an Identifier.
    // The identifier type needs to be determine together with a symbol table.
    public AST(int Tag, String name) {
        this.Tag = Tag;
        if (Tag == Tags.Ident) {
            this.Name = name;
        } else {
            this.Name = "ERROR";
        }
    }
}