/*
Write a C/C++ program that creates a zombie and then calls system to execute the ps
command to verify that the process is zombie.
*/
#include<unistd.h>
#include<sys/types.h>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
pid_t pid;
pid=fork();
if(pid==0)
{
cout << "child" <<endl;
exit(0);
}
else
{
char str[100],b[10];
//system("ps -o stat,pid,ppid,command");
strcpy(str,"ps -o stat,pid,ppid,command --pid ");
sprintf(b,"%d",pid);
strcat(str,b);
system(str);
sleep(5);
cout << "parent"<<endl;
}
}
//done