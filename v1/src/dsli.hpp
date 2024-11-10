#pragma once

namespace dsli {
    class DSLI {
    public:
        DSLI();
        ~DSLI();

        void run_prompt();
        void run_script(char *filename);

    private:
        bool had_error;
        void run(const std::string &script);
    };

    void error(int line, const std::string &message);
    void report(int line, const std::string &where, const std::string &message);
} // namespace dsli

