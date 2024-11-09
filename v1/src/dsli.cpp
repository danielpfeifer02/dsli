#include <iostream>
#include <fstream>

#include "dsli.hpp"

dsli::DSLI::DSLI() {
    // Initialize the interpreter
}

dsli::DSLI::~DSLI() {
    // Clean up the interpreter
}

void dsli::DSLI::run_prompt() {
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
    }
}

void dsli::DSLI::run_script(char *filename) {
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
}

void dsli::DSLI::run(const std::string &script) {
    // Run the given script
    std::cout << "Running script..." << std::endl;
    std::cout << script << std::endl;
}