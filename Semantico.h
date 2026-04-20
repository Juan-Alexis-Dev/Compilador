#pragma once
#include <vector>
#include <string>
#include <map>
#include "Token.h"

struct SymbolInfo {
    TokenType type;        
    bool      initialized; 
};

class Semantico {
public:
    std::vector<std::string> errors;
    std::vector<std::string> log;

    Semantico(std::vector<Token> tokens);
    void analyze();

private:
    std::vector<Token> tokens;
    int pos;

    std::map<std::string, SymbolInfo> symbols;

    Token current();
    Token peek(int offset = 0);
    Token consume();
    bool  check(TokenType type);
    bool  match(TokenType type);
    bool  isAtEnd();
    void  synchronize();

    bool      declareVariable(const std::string& name, TokenType type);
    bool      isDeclared(const std::string& name);
    TokenType getType(const std::string& name);
    void      markInitialized(const std::string& name);

    void analyzeProgram();
    void analyzeStatement();
    void analyzeVarDecl(TokenType typeToken);
    void analyzeAssignment();
    void analyzeIfStmt();
    void analyzeForStmt();
    void analyzeMostrarStmt();
    void analyzeBlock();

    TokenType analyzeExpr();
    TokenType analyzeComparison();
    TokenType analyzeTerm();
    TokenType analyzeFactor();
    TokenType analyzeUnary();
    TokenType analyzePrimary();
};