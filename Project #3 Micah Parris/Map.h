#ifndef H_M
#define H_M

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>


#include "areaNode.h"
 // H_AREANODE


#include "Area.h"
 // H_AREA


#include "IFDParser.h"
 // H_IFDPARSER


#include "LinkData.h"
// H_LINKDATA

using namespace std;

class Map{
	protected:
		vector<areaNode*> areasVec;
		int areacnt;

		//Here is the instance of IFDParser
	  	IFDParser parser;

		//Some additional class attributes here
        vector<LinkData*> linkVec;
		string nextToken;

		bool ifderr;

	public:
	    Map();
	    void buildMap();
		void makeArea();
		void makeLinks();
		void linkLinks();
		void useLinks(int start, int newRoom, char direction);
		areaNode* getStart();
		//void print();
		int reverseLookUp(areaNode*);

		friend ostream& operator<<(ostream&, Map&);
};

#endif