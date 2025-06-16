public class StmtNode extends ASTNode {
    ASTNode lhs, rhs;;

    public StmtNode(ASTNode lhs, ASTNode rhs) {
        this.lhs = lhs;
        this.rhs = rhs;
    }

    public void print() {
        System.out.println(" ".repeat(ASTNode.current_indent) + "ASSIGN");
        ASTNode.current_indent += ASTNode.INDENT;
        lhs.print();
        rhs.print();
        ASTNode.current_indent -= ASTNode.INDENT;
    }

    public void dump() { }
}
