#include<iostream>
#include<unistd.h>
using namespace std;
int main(int argc, char *argv[]){
    if(argc!=3){
        cout<<"Hello end"<<endl;
        return(0);
    }
    if(link(argv[1],argv[2])==-1){
        cout<<"Cant link"<<endl;
    }
    else{
        cout<<"Files have been linked"<<endl;
    }
}