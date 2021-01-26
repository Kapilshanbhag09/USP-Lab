#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<iostream>
#define MAX_BUF 1024
using namespace std;
int main(){
	int fd;
	char *myfifo="/tmp/myfifo";
	char buf[MAX_BUF];
	fd=open(myfifo, O_RDWR);
	read(fd,buf,MAX_BUF);
	cout<<"Writer"<<buf<<endl;
	close(fd);
	return(0);
}
