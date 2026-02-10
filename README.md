# mini-linux-shell
Mini Linux Shell in C++ using fork–exec–wait, built for learning system-level processes and command execution.

This is a minimal Linux shell implemented in C++ to explore how commands are executed
and processes are managed behind the scenes.  

## Features
### Shell
- Execute system commands (`ls`, `pwd`, `date`)  
- Command arguments support (`ls -l`)  
- Built-in `cd` command handled in parent process  
- Error handling for invalid commands

### MCP (Model Context Protocol) - Experimental 
- Minimal MCP server implemented in cpp
- Communicates via **JSON-RPC over stdin/stdout**
- Exposes shell context as a tool :
  - `get_last_shell_command` → returns the most recently executed command and exit code
- Focuses on **tooling & protocol**, not AI logic

  
### Environment
- Ubuntu (WSL2) on Windows, tested with g++ and Makefile

### Future Improvements
- Pipe support (`|`)  
- Input/output redirection (`>` / `<`)  
- Signal handling (`Ctrl+C`)  
- Command history  

This project demonstrates **practical system programming concepts** in C++ in a compact, easy-to-understand way.  

### Run
```bash
make
./mini-shell --mcp
