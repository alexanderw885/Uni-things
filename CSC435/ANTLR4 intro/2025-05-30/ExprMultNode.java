public class ExprMultNode extends ASTNode {
    ASTNode e_left, e_right;

    public ExprMultNode(ASTNode e_left, ASTNode e_right) {
        this.e_left = e_left;
        this.e_right = e_right;
    }

    public void print() {
        System.out.println(" ".repeat(ASTNode.current_indent) + "MULTOP");
        ASTNode.current_indent += ASTNode.INDENT;
        e_left.print();
        e_right.print();
        ASTNode.current_indent -= ASTNode.INDENT;
    }

    public void dump() { }
}
