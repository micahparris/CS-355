// ---------------------------------------------------------------------------
// Name: Micah Parris
// Course-Section: CS355-section 1
// Assignment: Assignment #9
// Date due: 4/30/2025
// Description: This is the driver file which tests the weighted graph
// ---------------------------------------------------------------------------


#include <iostream>
#include <fstream>
#include "weightedGraph.h"

using namespace std;

int main()
{
    weightedGraphType wG(20);
    wG.createWeightedGraph();

    wG.printWgraph();

    wG.shortestPath(0);
    wG.printShortestDistance(0);
    cout<<"++++++++++++++"<<endl<<endl;

    wG.allShortestPathWeights();

	return 0;
}
