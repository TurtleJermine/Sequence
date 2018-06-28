#include<iostream>
#include<stdio.h>
#include<cstring>
#include<fstream>
#include<stdlib.h>
#include"Sequence.h"



using namespace std;



int comlen( char *p, char *q )
{
    int i = 0;
    while(*p&&(*p++==*q++))
    {
	i++;
    }
    return i;
}
/* 
int pstrcmp(const void *p1, const void *p2)
{
    return strcmp(*(char* const *)p1,*(char* const*)p2);
}*/

int pstrcmp(const void *p1, const void *p2)
{
    return strcmp(*(char**)p1,*(char**)p2);
}


/*int pstrcmp(char **p,char **q)
{
    return strcmp(*p,*q);
}*/



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
    char *c=new char[l+1];
    char **a=new char*[l];
    for(int i=0;i<l;i++)
    {
	c[i]=dna[i];
    }
    c[l]='\0';
    for(int j=0;j<l;j++)
    {
	a[j]=c+j;
    }
    qsort(a,l,sizeof(char*),pstrcmp);
    int maxlen=0,temp,maxp=0;
    for(int k=0;k<l-1;k++)
    {
	temp=comlen(a[k],a[k+1]);
	if(temp>maxlen)
	{
	    maxlen=temp;
	    maxp=k;
	}
    }
    longest.assign(a[maxp],maxlen);
    delete c;
    delete a;
    return longest;
}




/*
string Sequence::longestRepeated()
{
	string longest;
	char *c=new char[l];
	char *a[l];
	int n=0;
	int i,temp;
	int maxlen=0,maxi=0;
	strcpy(c,dna.c_str());
	for(;n<l;n++)
	{
		a[n]=&c[n];
	}
	c[n]='\0';
	qsort(a,n,sizeof(char*),pstrcmp);
	for(i=0;i<l-1;i++)
	{
		temp=comlen(a[i],a[i+1]);
		if(temp>maxlen)
		{
			maxlen=temp;
			maxi=i;
		}
	}
	longest.assign(a[maxi],maxlen);
	delete []c;
	return longest;
	
}*/


/*
string Sequence::longestRepeated()
{
    string longest;
    int pos;
    int length=l/2;
    string a;
    for(int i=0;i<(l/2);i++)
    {
    	for(int j=0;j<l-2*length;j++)
    	{
    		longest.assign(dna,j,length);
			a.assign(dna,length+j,l-length-j);
			pos=a.find(longest,0);
			if(pos!=-1)
			return longest;
		}
	length--;
	}    
    return longest;
}*/



