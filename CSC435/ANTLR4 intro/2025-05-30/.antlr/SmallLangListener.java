// Generated from /home/alex/University/uni/CSC435/ANTLR4 intro/2025-05-30/SmallLang.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link SmallLangParser}.
 */
public interface SmallLangListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link SmallLangParser#prog}.
	 * @param ctx the parse tree
	 */
	void enterProg(SmallLangParser.ProgContext ctx);
	/**
	 * Exit a parse tree produced by {@link SmallLangParser#prog}.
	 * @param ctx the parse tree
	 */
	void exitProg(SmallLangParser.ProgContext ctx);
	/**
	 * Enter a parse tree produced by the {@code statementAssign}
	 * labeled alternative in {@link SmallLangParser#stat}.
	 * @param ctx the parse tree
	 */
	void enterStatementAssign(SmallLangParser.StatementAssignContext ctx);
	/**
	 * Exit a parse tree produced by the {@code statementAssign}
	 * labeled alternative in {@link SmallLangParser#stat}.
	 * @param ctx the parse tree
	 */
	void exitStatementAssign(SmallLangParser.StatementAssignContext ctx);
	/**
	 * Enter a parse tree produced by the {@code statementBlank}
	 * labeled alternative in {@link SmallLangParser#stat}.
	 * @param ctx the parse tree
	 */
	void enterStatementBlank(SmallLangParser.StatementBlankContext ctx);
	/**
	 * Exit a parse tree produced by the {@code statementBlank}
	 * labeled alternative in {@link SmallLangParser#stat}.
	 * @param ctx the parse tree
	 */
	void exitStatementBlank(SmallLangParser.StatementBlankContext ctx);
	/**
	 * Enter a parse tree produced by the {@code exprInt}
	 * labeled alternative in {@link SmallLangParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExprInt(SmallLangParser.ExprIntContext ctx);
	/**
	 * Exit a parse tree produced by the {@code exprInt}
	 * labeled alternative in {@link SmallLangParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExprInt(SmallLangParser.ExprIntContext ctx);
	/**
	 * Enter a parse tree produced by the {@code exprBracketed}
	 * labeled alternative in {@link SmallLangParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExprBracketed(SmallLangParser.ExprBracketedContext ctx);
	/**
	 * Exit a parse tree produced by the {@code exprBracketed}
	 * labeled alternative in {@link SmallLangParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExprBracketed(SmallLangParser.ExprBracketedContext ctx);
	/**
	 * Enter a parse tree produced by the {@code exprAdd}
	 * labeled alternative in {@link SmallLangParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExprAdd(SmallLangParser.ExprAddContext ctx);
	/**
	 * Exit a parse tree produced by the {@code exprAdd}
	 * labeled alternative in {@link SmallLangParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExprAdd(SmallLangParser.ExprAddContext ctx);
	/**
	 * Enter a parse tree produced by the {@code exprId}
	 * labeled alternative in {@link SmallLangParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExprId(SmallLangParser.ExprIdContext ctx);
	/**
	 * Exit a parse tree produced by the {@code exprId}
	 * labeled alternative in {@link SmallLangParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExprId(SmallLangParser.ExprIdContext ctx);
	/**
	 * Enter a parse tree produced by the {@code exprMult}
	 * labeled alternative in {@link SmallLangParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExprMult(SmallLangParser.ExprMultContext ctx);
	/**
	 * Exit a parse tree produced by the {@code exprMult}
	 * labeled alternative in {@link SmallLangParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExprMult(SmallLangParser.ExprMultContext ctx);
}