public class TestASTNode {
    public static void main(String args[]) {
        ProgramNode pn = new ProgramNode();

        IdentNode ident_lhs = new IdentNode("a");
        ExprIntegerNode expr = new ExprIntegerNode(3);
        StmtNode s = new StmtNode(ident_lhs, expr);
        pn.addStmt(s);   // a <- 3

        ident_lhs = new IdentNode("b");
        expr = new ExprIntegerNode(4);
        s = new StmtNode(ident_lhs, expr);
        pn.addStmt(s);   // b <- 4

        ident_lhs = new IdentNode("c");
        expr = new ExprIntegerNode(5);
        s = new StmtNode(ident_lhs, expr);
        pn.addStmt(s);   // c <- 5

        ExprIdentNode e_left  = new ExprIdentNode("b");
        ExprIdentNode e_right = new ExprIdentNode("c");
        ExprMultNode e_mult = new ExprMultNode(e_left, e_right); // b * c

        e_left = new ExprIdentNode("a");
        ExprAddNode e_add = new ExprAddNode(e_left, e_mult);  // a + b * c

        ident_lhs = new IdentNode("d");
        s = new StmtNode(ident_lhs, e_add);
        pn.addStmt(s);  // d <- a + b * c

        pn.print();
    }
}
