#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;


void printID(const string& name);

int main() {
    
    printID("P1");

    pid_t child_pid2, child_pid3;

    if ((child_pid2 = fork()) == 0) 
    {
        printID("P2");
        pid_t child_pid4;

        if ((child_pid4 = fork()) == 0) 
            printID("P4");
       
        else 
            wait(nullptr); 
        
    }
    else if ((child_pid3 = fork()) == 0)
        printID("P3");
        
    else
        wait(nullptr); 

    return 0;
}
void printID(const string& name) {
    cout << name << ": ID = " << getpid() << ", Parent ID = " << getppid() << endl;
}
