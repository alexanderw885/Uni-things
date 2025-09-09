public class ExprIntegerNode extends ASTNode {
    int val;

    public ExprIntegerNode(int val) {
        this.val = val;
    }

    public void print() {
        System.out.println(" ".repeat(ASTNode.current_indent) + "INTEGER " + val);
    }

    public void dump() { }
}
