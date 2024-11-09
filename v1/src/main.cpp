#include <iostream>

#include "dsli.hpp"

int main(int argc, char *argv[]) {
    if (argc > 2) {
        std::cerr << "Usage: " << argv[0] << " <dsl-script>" << std::endl;
        return 1;
    }
    
    dsli::DSLI interpreter;
    
    if (argc == 2) {
        interpreter.run_script(argv[1]);
    }
    else {
        interpreter.run_prompt();
    }
}