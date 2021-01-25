/*Write a C/C++ program to set up a real-time clock interval timer using
the alarm API*/
#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
using namespace std;
void callme(int signo)
{
	cout<<"Hello!\n";
}

int main()
{
	struct sigaction action;
	action.sa_handler=(void(*)(int))callme;
	sigaction(SIGALRM,&action,0);
	alarm(2);
	sleep(2);
	return 0;
}