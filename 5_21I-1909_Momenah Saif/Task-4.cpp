#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
using namespace std;

int main() {
    //getenv= search environment variables and return their pointers1
    const char* user = getenv("USER");
    const char* term = getenv("TERM");
    const char* path = getenv("PATH");

    cout << "USER= " << user << endl;
    cout << "TERM= " << term << endl;
    cout << "PATH= " << path << endl;

    // arguments for execve
    //char* script = (char*)"script.sh";
    char* arg1 = (char*)user;
    char* arg2 = (char*)term;
    char* arg3 = (char*)path;
    char* vectorArg[] = {"script.sh", arg1, arg2, arg3, nullptr};

    
    char* vectorEnv[] = {"OS2022=5ma32zw", nullptr};

    // Execute the script with execve
    execve("script.sh", vectorArg, vectorEnv);

   

    return 1;
}
