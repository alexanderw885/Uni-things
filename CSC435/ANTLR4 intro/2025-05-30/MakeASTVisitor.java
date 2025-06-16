public class MakeASTVisitor extends SmallLangBaseVisitor<ASTNode> {
    ASTNode root = null;

    public ASTNode visitProg(SmallLangParser.ProgContext ctx) {
        ProgramNode top_node = new ProgramNode();
        for (SmallLangParser.StatContext stat : ctx.stat()) {
            ASTNode node = visit(stat);
            top_node.addStmt(node);
        }
        return top_node;
    }

    public ASTNode visitStatementAssign(SmallLangParser.StatementAssignContext ctx) {
        ASTNode lhs = new IdentNode(ctx.IDENT().getText());
        ASTNode rhs = visit(ctx.expr());
        return new StmtNode(lhs, rhs);
    }

    public ASTNode visitExprAdd(SmallLangParser.ExprAddContext ctx) {
        ASTNode e1 = visit(ctx.expr(0));
        ASTNode e2 = visit(ctx.expr(1));
        return new ExprAddNode(e1, e2);
    }

    public ASTNode visitExprMult(SmallLangParser.ExprMultContext ctx) {
        ASTNode e1 = visit(ctx.expr(0));
        ASTNode e2 = visit(ctx.expr(1));
        return new ExprMultNode(e1, e2);
    }

    public ASTNode visitExprBracketed(SmallLangParser.ExprBracketedContext ctx) {
        return visit(ctx.expr());
    }

    public ASTNode visitExprId(SmallLangParser.ExprIdContext ctx) {
        String ident = ctx.IDENT().getText();
        return new ExprIdentNode(ident);
    }  

    public ASTNode visitExprInt(SmallLangParser.ExprIntContext ctx) {
        String s = ctx.INTEGER().getText();
        int number = 0;
        try {
            number = Integer.parseInt(s);
        } catch(NumberFormatException e) {  
            // This should not happen, given REGEX for INTEGER ...
            // If it does happen, ignore for now and use the
            // value of zero.
        }   
        return new ExprIntegerNode(number);
    }  
}
