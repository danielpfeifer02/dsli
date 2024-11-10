#pragma once

#include <string>

namespace dsli {

    union Literal {
        std::string *string;
        double decimal;
    };

    enum TOKEN_TYPE {
        // Single-character tokens.
        LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
        COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,
        
        // One or two character tokens.
        BANG, BANG_EQUAL,
        EQUAL, EQUAL_EQUAL,
        GREATER, GREATER_EQUAL,
        LESS, LESS_EQUAL,
        
        // Literals.
        IDENTIFIER, STRING, NUMBER,
        
        // Keywords.
        AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
        PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,
        
        END
    };

    class Token {
    public:
        Token(const dsli::TOKEN_TYPE &type, const std::string &lexeme, int line, Literal literal);
        ~Token();

        void print() const;
        std::string to_string() const;

    private:
        dsli::TOKEN_TYPE type;
        std::string lexeme;
        int line;
        Literal literal;
    };
} // namespace dsli