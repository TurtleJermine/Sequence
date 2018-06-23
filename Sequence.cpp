#include<iostream>
#include<stdio.h>
#include<cstring>
#include<fstream>
#include"Sequence.h"



using namespace std;


Sequence::Sequence(string filename)
{
    char b[20];
    strcpy(b,filename.c_str());
    fstream DNA(b);
    if(!DNA.is_open())
    {
        cout<<"Could not find the file."<<endl;
    }
    string line;
    getline(DNA,line);
    dna=line;
    while(getline(DNA,line))
    {
	dna+=line;
    }
    l=dna.length();
    DNA.clear();
    DNA.seekg(0);
    DNA.close();
}


int Sequence::length()
{
    return l;
}


int Sequence::numberOf(char base)
{
    int num=0,count=0;
    while(num<l)
    {
	if(dna[num]==base)
	{
	    count++;
	}
	num++;
    }
    return count;
}


string Sequence::longestConsecutive()
{
    string longest;
    int thislen=0;
    int nextlen=1;
    char t,n;
    t='a';
    n='b';
    int num=0;
    while(num<l)
    {
	if(dna[num]!=n)
	{
	    if(nextlen>thislen)
	    {
		thislen=nextlen;
		longest.assign(nextlen,n);
		t=n;	
	    }
	    nextlen=1;
	    n=dna[num];
	}
	else
	{
	    nextlen++;
	}
	num++;
    }
    return longest;
    
}


string Sequence::longestRepeated()
{
    string longest;
    
    return longest;
}



