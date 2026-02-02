# mini-linux-shell
Mini Linux Shell in C++ using fork–exec–wait, built for learning system-level processes and command execution.

This is a minimal Linux shell implemented in C++ to explore how commands are executed
and processes are managed behind the scenes.  

### Features
- Execute system commands (`ls`, `pwd`, `date`)  
- Command arguments support (`ls -l`)  
- Built-in `cd` command handled in parent process  
- Error handling for invalid commands

  
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
./mini-shell
