#pragma once

namespace dsli {
    class DSLI {
    public:
        DSLI();
        ~DSLI();
        void run_prompt();
        void run_script(char *filename);

    private:
        void run(const std::string &script);
    };
} // namespace dsli

