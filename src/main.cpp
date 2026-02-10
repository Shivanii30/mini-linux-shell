#include "shell.h"
#include "mcp/mcp_server.h"

Shell shell;  // shared instance

int main(int argc, char* argv[]) {
    if (argc > 1 && std::string(argv[1]) == "--mcp") {
        run_mcp_server(shell);
        return 0;
    }

    shell.run();
}
