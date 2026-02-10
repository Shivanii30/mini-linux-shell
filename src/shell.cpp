#include "shell.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <sys/wait.h>
#include <unistd.h>
#include <cstring>
#include <csignal>

using namespace std;

void handle_sigint(int sig){
    (void)sig;
    cout << endl;
}

void Shell::run(){

    signal(SIGINT, handle_sigint);

    std::string input;
    
    while(true){
        cout << "mini-shell> ";

        getline(cin, input);

        if(input.empty()){
            continue;
        }

        last_command = input;


        //Exit command
        if(input == "exit"){
            cout <<" Exiting mini-shell." << endl;
            last_exit_code = 0;
            break;
        }

        //Built-in command: cd
        if(input.rfind("cd",0) == 0){
            string path = input.substr(3);

            if(path.empty()){
                cerr << "cd : missing argument\n";
                last_exit_code = 1;
            }
            else if(chdir(path.c_str()) != 0){
                perror("cd failed");
                last_exit_code = 1;
            } else {
                last_exit_code = 0;
            }
            continue;
        }

        //parse input into arguments

        stringstream ss(input);

        vector<string> tokens;

        string token;

        while(ss >> token){
            tokens.push_back(token);
        }

        vector<char*> args;
        for(auto& t : tokens){
            args.push_back(const_cast<char*>(t.c_str()));
        }
        args.push_back(nullptr);

        pid_t pid = fork();
        if(pid < 0){
            perror("Fork failed");
        }
        else if(pid == 0){

            signal(SIGINT, SIG_DFL);

            //Child process

            execvp(args[0], args.data());
            perror("Execution failed");
            exit(1);
        }
        else{
            //parent process
            int status;
            waitpid(pid, &status, 0);
            signal(SIGINT, handle_sigint);

            if (WIFEXITED(status)){
                last_exit_code = WEXITSTATUS(status);
            } else {
                last_exit_code = -1;
            }
        }
    }

}

// ====MCP getters (context exposure) ==== 

string Shell ::get_last_command() const {
    return last_command;
}

int Shell ::get_last_exit_code() const {
    return last_exit_code;
}
