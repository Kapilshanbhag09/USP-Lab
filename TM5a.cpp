//Write a C/C++ program that outputs the contents of its Environment list.
#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
using namespace std;
extern char **environ;
int main()
{
    extern char **environ;
    for(int i=0;environ[i]!=(char *)0;i++){
        cout << environ[i] << endl;
    }
}
