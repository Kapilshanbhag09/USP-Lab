/*
Consider the last 100 bytes as a region. Write a C/C++ program to check whether the
region is locked or not. If the region is locked, print pid of the process which has locked. If
the region is not locked, lock the region with an exclusive lock, read the last 50 bytes and
unlock the region.
*/
#include<fcntl.h>
#include<iostream>
#include<stdlib.h>
#include<unistd.h>
using namespace std;
int main()
{
    char buf[50];
    int fd=open("b.txt",O_RDWR);
    struct flock f1;
    f1.l_type=F_WRLCK;
    f1.l_whence=SEEK_END;
    f1.l_start=0;
    f1.l_len=100;
    fcntl(fd,F_GETLK,&f1);
    if(f1.l_type==F_RDLCK)
    {
        cout<< f1.l_pid << " has put read lock" << endl;
    // exit(0);
    }
    if(f1.l_type==F_WRLCK)
    {
        cout<< f1.l_pid << " has put write lock" << endl;
    //exit(0);
    }
    f1.l_type=F_WRLCK;
    f1.l_pid=getpid();
    cout<<getpid()<<endl;
    fcntl(fd,F_SETLKW,&f1);
    lseek(fd,-50,SEEK_END);
    read(fd,buf,50);
    cout<< buf<<endl;
    f1.l_type=F_UNLCK;
    fcntl(fd,F_SETLK,&f1);
    cout<<"File unlocked unsuccessfully"<<endl;
}
//done