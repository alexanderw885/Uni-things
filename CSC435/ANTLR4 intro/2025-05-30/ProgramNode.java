import java.util.ArrayList;
import java.util.List;


public class ProgramNode extends ASTNode {
    List<ASTNode> stmts;

    public ProgramNode() {
        stmts = new ArrayList<>();
    }

    public void addStmt(ASTNode stmt) {
        stmts.add(stmt);
    }

    public void print() {
        String sep = "";

        for (ASTNode stmt : stmts) {
            System.out.print(sep);
            stmt.print();
            sep = "\n";
        }
    }

    public void dump() { }
}
