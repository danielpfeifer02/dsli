#pragma once

namespace dsli {
    class DSLI {
    public:
        DSLI();
        ~DSLI();
        void run_prompt();
        void run_script(char *filename);
    };
} // namespace dsli

