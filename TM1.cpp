/*
1. Write a C/C++ POSIX compliant program to check the following limits:
(i) No. of clock ticks
(ii) Max. no. of child processes
(iii) Max. path length
(iv) Max. no. of characters in a file name
(v) Max. no. of open files/ process
*/
#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<unistd.h>
#include<iostream>
#include<limits.h>
using namespace std;
int main(){
	int res;
	//No of clock ticks
	res=sysconf(_SC_CLK_TCK);
	if(res==-1){
	cout<<"Clock tick not supported"<<endl;
	}
	else{
		cout<<"No of clock ticks :"<<res<<endl;
	}
	//Max no of child process
	res=sysconf(_SC_CHILD_MAX);
	if (res==-1){
		cout<<"Child max not supported"<<endl;
	}
	else{
		cout<<"No of child process that can be created simultaneously :"<<res<<" and Min value :"<<_POSIX_CHILD_MAX<<endl;
	}
	//Max path length
	res=pathconf("/",_PC_PATH_MAX);
	if(res==-1){
		cout<<"Path max not supported"<<endl;
	}
	else{
		cout<<"Max Path length is :"<<res<<endl;
	}
	//Max no of characters in a file name
	res=pathconf("/",_PC_NAME_MAX);
	if(res==-1){
		cout<<"Name max not supported"<<endl;
	}
	else{
		cout<<"Max length of file name is :"<<res<<endl;
	}
	//Max no of file open
	res=sysconf(_SC_OPEN_MAX);
	if(res==-1){
		cout<<"Max file not supported"<<endl;
	}
	else{
		cout<<"Max no of file/process open :"<<res<<endl;
	}
return 0;
}
//done