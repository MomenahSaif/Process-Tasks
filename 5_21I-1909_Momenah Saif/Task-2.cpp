#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main() 
{
    int a,b,c,d,e,f,r,r1,r2,r3;
    cout << "Enter the values of a, b, c, d, e, and f: ";
    cin >> a >> b >> c >> d >> e >> f;

    pid_t child_pid1, child_pid2, child_pid3;

    if ((child_pid1 = fork()) == 0) 
    {
         r1 = a * b;
        cout << "Child 1: a * b = " << r1 << endl;
        exit(r1);
        
    } 
    else if ((child_pid2 = fork()) == 0) {
        
         r2 = c / d;
        cout << "Child 2: c / d = " << r2 << endl;
        exit(r2);
    } 
    else if ((child_pid3 = fork()) == 0) {
        
        r3 = e - f;
        cout << "Child 3: e - f = " << r3 << endl;
        exit(r3);
    } 
    else {
        
        int status1, status2, status3;
        
        waitpid(child_pid1, &status1, 0);
        waitpid(child_pid2, &status2, 0);
        waitpid(child_pid3, &status3, 0);

        // retrive exit status of child 1,2,3 to get the results and add them
        int r1 = WEXITSTATUS(status1);
        int r2 = WEXITSTATUS(status2);
        int r3 = WEXITSTATUS(status3);

        r = r1 + r2 + r3;

        cout << "Parent: x= " << r << endl;
    }

    return 0;
}
