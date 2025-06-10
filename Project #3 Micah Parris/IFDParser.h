#ifndef H_IFDParser
#define H_IFDParser


#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

class IFDParser{
	public:
        IFDParser();
        void tokenIt();
        void eatToken();
        string getNext();
        void trim(string& s);
        void printTokens();

	private:
		int pos;
		string gameFile;
        vector<string> tokenVec;
};

#endif