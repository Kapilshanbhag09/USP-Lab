#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<iostream>
using namespace std;
int main(){
	int fd;
	char buf[1024];
	char *myfifo="/tmp/myfifo";
	mkfifo(myfifo, 0666);
	cout<<"Run reader process to read the file"<<endl;
	fd=open(myfifo, O_WRONLY);
	write(fd,"Hi", sizeof("Hi"));
	close(fd);
	unlink(myfifo);
	return(0);
}
