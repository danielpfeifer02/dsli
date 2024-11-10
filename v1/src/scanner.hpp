#pragma once

#include <string>

#include "token.hpp"

namespace dsli {
    template <template<typename, typename> class Container>
    class Scanner {
    public:
        Scanner(const std::string &source) : source{source}, start{0}, current{0}, line{1} {
            // Initialize the scanner
            std::cout << "Initializing scanner..." << std::endl;
            tokens = Container<Token, std::allocator<Token>>();
        };
        ~Scanner() {
            // Clean up the scanner
            std::cout << "Cleaning up scanner..." << std::endl;
        };

        void scan_tokens() {
        
            std::cout << "Scanning tokens..." << std::endl;
            
            while (!is_at_end()) {
                // We are at the beginning of the next lexeme.
                start = current;
                scan_token();
            }

            tokens.push_back(Token(END, "", line, {}));            
        };

        const Container<Token, std::allocator<Token>>& get_tokens() {
            std::cout << "Getting tokens..." << std::endl;
            return tokens;
        };
    
    private: 
        
        bool is_at_end() {
            return current >= source.length();
        };
        char advance() {
            return source.at(current++);
        };
        char peek() {
            if (is_at_end()) return '\0';
            return source.at(current);
        };
        void add_token(const TOKEN_TYPE &type, Literal literal = {}) {
            std::cout << "Adding token..." << std::endl;
            std::string text = source.substr(start, current - start);
            tokens.push_back(Token(type, text, line, literal));
        };
        bool match(char expected) {
            if (is_at_end()) return false;
            if (source.at(current) != expected) return false;

            current++;
            return true;
        }
        void string() {
            while (peek() != '"' && !is_at_end()) {
                if (peek() == '\n') line++;
                advance();
            }
            if (is_at_end()) {
                dsli::error(line, "Unterminated string.");
                return;
            }
            advance();
            Literal literal = {new std::string(source.substr(start + 1, current - start - 2))};
            add_token(STRING, literal);
        }
        void scan_token() {
            std::cout << "Scanning token..." << std::endl;

            char c = advance();

            switch(c) {
                case '(': add_token(LEFT_PAREN); break;
                case ')': add_token(RIGHT_PAREN); break;
                case '{': add_token(LEFT_BRACE); break;
                case '}': add_token(RIGHT_BRACE); break;
                case ',': add_token(COMMA); break;
                case '.': add_token(DOT); break;
                case '-': add_token(MINUS); break;
                case '+': add_token(PLUS); break;
                case ';': add_token(SEMICOLON); break;
                case '*': add_token(STAR); break;
                case '!': add_token(match('=') ? BANG_EQUAL : BANG); break;
                case '=': add_token(match('=') ? EQUAL_EQUAL : EQUAL); break;
                case '<': add_token(match('=') ? LESS_EQUAL : LESS); break;
                case '>': add_token(match('=') ? GREATER_EQUAL : GREATER); break;
                case '"': string(); break;
                case '\n': line++; break;
                case ' ': [[fallthrough]];
                case '\r': [[fallthrough]];
                case '\t': break;
                case '/': 
                        if (match('/')) {
                            while(peek() != '\n' && !is_at_end()) advance();
                        } else {
                            add_token(SLASH);
                        }
                        break;
                default:
                    error(line, "Unexpected character '" + std::string(1, c) + "'");
                    break;
            }

        };

        std::string source;
        Container<Token, std::allocator<Token>> tokens;

        size_t start;
        size_t current;
        size_t line;
    };
} // namespace dsli