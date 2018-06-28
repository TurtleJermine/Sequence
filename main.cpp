#include<iostream>
#include<stdio.h>
#include<cstring>
#include<time.h>
#include"Sequence.h"

using namespace std;

int main()
{
//    clock_t st,et;
    string name;
    cout<<"Enter the file name:"<<endl;
    cin>>name;
    Sequence test(name);
    cout<<"The length:"<<test.length()<<endl;
    cout<<"The number of A:"<<test.numberOf('A')<<endl;
    cout<<"The number of C:"<<test.numberOf('C')<<endl;
    cout<<"The number of T:"<<test.numberOf('T')<<endl;
    cout<<"The number of G:"<<test.numberOf('G')<<endl;
//    st=clock();
    cout<<"The longest consecutive:"<<test.longestConsecutive()<<endl;
//    et=clock();
//    cout<<(double)(et-st)/CLOCKS_PER_SEC<<endl;
    cout<<"The longest repeated:"<<test.longestRepeated()<<endl;
    return 0;

}
