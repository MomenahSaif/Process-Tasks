#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main() 
{
    pid_t child_pid1, child_pid2;
    
    child_pid1 = fork();
    
    if (child_pid1 == -1) {
        
       cout << "Error: Forking the first child process failed." << endl;
        return 1;
    }
    
    if (child_pid1 == 0) 
    {
       child_pid2 = fork();
        
        if (child_pid2 == -1) 
        {
            cout << "Error: Forking the second child process failed." << endl;
            return 1;
        }
        
        
        
        if (child_pid2 == 0) {
            char* args[] = {(char*)"ls", (char*)"-l", NULL};
            execvp("ls", args);
            cout<< "Error: execvp() failed." << endl;
            return 1;
        } 
        else 
            exit(0);
        
    } 
    
    else 
    {
        int status;
        waitpid(child_pid1, &status, 0);
        
        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) 
            cout << "Parent: Second child successful." << endl;
        
        else 
            cerr << "Parent: Second child failed." << endl;
       
    }
    
    return 0;
}
