/*
Write a C/C++ POSIX compliant program that prints the POSIX defined configuration
options supported on any given system using feature test macros.
*/
#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<unistd.h>
#include<iostream>
using namespace std;
int main()
{
#ifdef _POSIX_JOB_CONTROL
cout << "Job control is supported" <<endl;
#else
cout << "Job control is not supported" << endl;
#endif
#ifdef _POSIX_SAVED_IDS
cout << "Saved Ids is supported" <<endl;
#else
cout << "Saved Ids is not supported" << endl;
#endif
#ifdef _POSIX_CHOWN_RESTRICTED
cout << "Change of ownership is supported and value is "<<
_POSIX_CHOWN_RESTRICTED<<endl;
#else
cout << "Change of ownership is not supported"<<endl;
#endif
#ifdef _POSIX_NO_TRUNC
cout << "No truncation is supported and value is "<<
_POSIX_NO_TRUNC<<endl;
#else
cout << "No truncation is not supported"<<endl;
#endif
#ifdef _POSIX_VDISABLE
cout << "Disabling is supported and disabling char is"<<
_POSIX_VDISABLE<<endl;
#else
cout << "Disabling is not supported"<<endl;
#endif
}
//done