#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#include "../shell.h"

using json = nlohmann::json;

void handle_initialize(int id) {
    json response = {
        {"jsonrpc", "2.0"},
        {"id", id},
        {"result", {
            {"protocolVersion", "0.1"},
            {"capabilities", json::object()}
        }}
    };
    std::cout << response.dump() << std::endl;
}

void handle_tools_list(int id) {
    json response = {
        {"jsonrpc", "2.0"},
        {"id", id},
        {"result", {
            {"tools", {{
                {"name", "get_last_shell_command"},
                {"description", "Returns the most recently executed shell command and its exit code"},
                {"input_schema", json::object()}
            }}}
        }}
    };
    std::cout << response.dump() << std::endl;
}

void handle_tools_call(int id, const Shell &shell) {
    json response = {
        {"jsonrpc", "2.0"},
        {"id", id},
        {"result", {
            {"command", shell.get_last_command()},
            {"exit_code", shell.get_last_exit_code()}
        }}
    };
    std::cout << response.dump() << std::endl;
}

void run_mcp_server(Shell &shell) {
    std::string line;
    while (std::getline(std::cin, line)) {

    if (line.empty()) {
        continue; // ignore empty input
    }

    json request;
    try {
        request = json::parse(line);
    } catch (const json::parse_error& e) {
        // Ignore malformed input (best practice from talk)
        continue;
    }

    std::string method = request.value("method", "");
    int id = request.value("id", -1);

    if (method == "initialize") {
        handle_initialize(id);
    }
    else if (method == "tools/list") {
        handle_tools_list(id);
    }
    else if (method == "tools/call") {
        handle_tools_call(id, shell);
    }
}

}
