#pragma once
#include <string>

class Shell {
public:
    void run();

    // MCP-visible context
    std::string get_last_command() const;
    int get_last_exit_code() const;

private:
    std::string last_command;
    int last_exit_code = 0;
};
