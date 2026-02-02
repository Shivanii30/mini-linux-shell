#include "shell.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <sys/wait.h>
#include <unistd.h>
#include <cstring>

using namespace std;

void Shell::run(){
    std::string input;

    while(true){
        cout << "mini-shell> ";

        getline(cin, input);

        if(input.empty()){
            continue;
        }

        //Exit command
        if(input == "exit"){
            cout <<" Exiting mini-shell." << endl;
            break;
        }

        //Built-in command: cd
        if(input.rfind("cd",0) == 0){
            string path = input.substr(3);

            if(path.empty()){
                cerr << "cd : missing argument\n";
            }
            else if(chdir(path.c_str()) != 0){
                perror("cd failed");
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

            //Child process

            execvp(args[0], args.data());
            perror("Execution failed");
            exit(1);
        }
        else{
            //parent process
            wait(nullptr);
        }
    }

}
