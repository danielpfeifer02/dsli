#include <iostream>
#include <fstream>
#include <vector>

#include "dsli.hpp"
#include "scanner.hpp"

namespace dsli {

    DSLI::DSLI() : had_error{false} {
        // Initialize the interpreter
    }

    DSLI::~DSLI() {
        // Clean up the interpreter
    }

    void DSLI::run_prompt() {
        // Run the interactive prompt
        std::cout << "Running interactive prompt..." << std::endl;

        std::string input;

        for (;;) {
            std::cout << "> ";
            std::getline(std::cin, input);

            if (input == "exit;") {
                break;
            }

            run(input);
            had_error = false;
        }
    }

    void DSLI::run_script(char *filename) {
        // Run the script from the given filename
        std::cout << "Running script: " << filename << std::endl;

        std::fstream file(filename);

        if (!file.is_open()) {
            std::cerr << "Error: Could not open file " << filename << std::endl;
            return;
        }

        std::string script{std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};

        run(script);

        file.close();

        if (had_error) {
            std::exit(65);
        }
    }

    void DSLI::run(const std::string &script) {
        // Run the given script
        std::cout << "Running script..." << std::endl;
        std::cout << script << std::endl;

        Scanner<std::vector> scanner{script};
        scanner.scan_tokens();
        auto tokens = scanner.get_tokens();

        for (const auto &token : tokens) {
            token.print();
        }
    }

    void error(int line, const std::string &message) {
        // Report an error
        report(line, "", message);
    }

    void report(int line, const std::string &where, const std::string &message) {
        // Report a message
        std::cerr << "[line " << line << "] Error" << where << ": " << message << std::endl;
    }

} // namespace dsli