#include <iostream>

#include "dsli.hpp"

using namespace dsli;

DSLI::DSLI() {
    // Initialize the interpreter
}

DSLI::~DSLI() {
    // Clean up the interpreter
}

void DSLI::run_prompt() {
    // Run the interactive prompt
    std::cout << "Running interactive prompt..." << std::endl;
}

void DSLI::run_script(char *filename) {
    // Run the script from the given filename
    std::cout << "Running script: " << filename << std::endl;
}