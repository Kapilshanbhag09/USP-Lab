/*
Write a C/C++ program to avoid zombie process by forking twice.
*/
#include<unistd.h>
#include<sys/types.h>
#include<iostream>
#include<sys/wait.h>
using namespace std;
int main()
{
pid_t cid,gcid;
cid=fork();
if(cid==0)
{
cout << "child id " <<getpid()<<endl;
gcid=fork();
if(gcid==0)
{
cout << "grandchild " <<getpid()<<endl;
sleep(20);
system("ps -o stat,pid,ppid,command");
}
else
{
exit(0);
}
}
else
{
    cout << "parent " <<getpid()<<endl;
wait(NULL);
}
}
//done