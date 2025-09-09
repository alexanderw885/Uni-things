public class IdentNode extends ASTNode {
    String ident;

    public IdentNode(String ident) {
        this.ident = ident;
    }

    public void print() {
        System.out.println(" ".repeat(ASTNode.current_indent) + "IDENT-LHS " + ident);
    }

    public void dump() { }
}
