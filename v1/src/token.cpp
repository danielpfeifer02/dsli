#include <iostream>
#include <fstream>

#include "token.hpp"

namespace dsli {

    Token::Token(const dsli::TOKEN_TYPE &type, const std::string &lexeme, int line, Literal literal) : type{type}, lexeme{lexeme}, line{line}, literal{literal} {
        // Initialize the token
    }

    Token::~Token() {
        // Clean up the token
        if (this->type == STRING) {
        std::cout << "Cleaning up token..." << std::endl;
            // delete this->literal.string; // TODO: why is it deleting too early?
        }
    }

    void Token::print() const {
        // Get the type of the token
        std::cout   << this->to_string() << " " << this->lexeme; 
        switch(this->type) {
            case STRING: std::cout << " " << *this->literal.string; break;
            default: break;
        }
        std::cout << std::endl;
    }

    std::string Token::to_string() const {
        switch(type) {
            // Single-character tokens
            case LEFT_PAREN: return "LEFT_PAREN";
            case RIGHT_PAREN: return "RIGHT_PAREN";
            case LEFT_BRACE: return "LEFT_BRACE";
            case RIGHT_BRACE: return "RIGHT_BRACE";
            case COMMA: return "COMMA";
            case DOT: return "DOT";
            case MINUS: return "MINUS";
            case PLUS: return "PLUS";
            case SEMICOLON: return "SEMICOLON";
            case SLASH: return "SLASH";
            case STAR: return "STAR";

            // One or more character tokens
            case BANG: return "BANG";
            case BANG_EQUAL: return "BANG_EQUAL";
            case EQUAL: return "EQUAL";
            case EQUAL_EQUAL: return "EQUAL_EQUAL";
            case GREATER: return "GREATER";
            case GREATER_EQUAL: return "GREATER_EQUAL";
            case LESS: return "LESS";
            case LESS_EQUAL: return "LESS_EQUAL";

            // Literals
            case IDENTIFIER: return "IDENTIFIER";
            case STRING: return "STRING";
            case NUMBER: return "NUMBER";

            // Keywords
            case AND: return "AND";
            case CLASS: return "CLASS";
            case ELSE: return "ELSE";
            case FALSE: return "FALSE";
            case FUN: return "FUN";
            case FOR: return "FOR";
            case IF: return "IF";
            case NIL: return "NIL";
            case OR: return "OR";
            case PRINT: return "PRINT";
            case RETURN: return "RETURN";
            case SUPER: return "SUPER";
            case THIS: return "THIS";
            case TRUE: return "TRUE";
            case VAR: return "VAR";
            case WHILE: return "WHILE";

            // End token
            case END: return "END";

            // Default case to handle unexpected values
            default: return "UNKNOWN";

        }
    }

} // namespace dsli