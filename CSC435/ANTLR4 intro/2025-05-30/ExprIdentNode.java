public class ExprIdentNode extends ASTNode {
    String ident;

    public ExprIdentNode(String ident) {
        this.ident = ident;
    }

    public void print() {
        System.out.println(" ".repeat(ASTNode.current_indent) + "IDENT " + ident);
    }

    public void dump() { }
}
