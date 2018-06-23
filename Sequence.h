#ifndef SEQUENCE_H
#define SEQUENCE_H


#include<cstring>
#include<fstream>

using namespace std;

class Sequence
{
    public:
	Sequence(string);
	int length();
	int numberOf(char);
	string longestConsecutive();
	string longestRepeated();
    private:
	string dna;
        int l;
};



#endif
