// ---------------------------------------------------------------------------
// Name: Micah Parris
// Course-Section: CS355-section 1
// Assignment: Assignment #9
// Date due: 4/30/2025
// Description: This is the header file for the weighted graph type
// ---------------------------------------------------------------------------


#ifndef H_weightedGraph
#define H_weightedGraph

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cfloat>
#include "graphType.h"

using namespace std;

class weightedGraphType: public graphType
{
public:
    void createWeightedGraph();
      //Function to create the graph and the weight matrix.
      //Postcondition: The graph using adjacency lists and
      //               its weight matrix is created.

    void shortestPath(int vertex);
      //Function to determine the weight of a shortest path
      //from vertex, that is, source, to every other vertex
      //in the graph.
      //Postcondition: The weight of the shortest path from
      //               vertex to every other vertex in the
      //               graph is determined.

    void printShortestDistance(int vertex);
      //Function to print the shortest weight from vertex
      //to the other vertex in the graph.
      //Postcondition: The weight of the shortest path from
      //               vertex to every other vertex in the
      //               graph is printed.

    void allShortestPathWeights();
      //Function to call printShortestDistance for all vertexes

    void printWgraph();
      //Function to call to print out the weighted graph.

    weightedGraphType(int size = 0);
      //Constructor
      //Postcondition: gSize = 0; maxSize = size;
      //               graph is an array of pointers to linked
      //               lists.
      //               weights is a two-dimensional array to
      //               store the weights of the edges.
      //               smallestWeight is an array to store the
      //               smallest weight from source to vertices.

    ~weightedGraphType();
      //Destructor
      //The storage occupied by the vertices and the arrays
      //weights and smallestWeight is deallocated.

protected:
    double **weights;   //pointer to create weight matrix
    double *smallestWeight;	//pointer to create the array to
                            //store the smallest weight from
                            //source to vertices
};

//---------------------------------------------------------------------------
/* The createWeightedGraph will create the graph and the weight matrix
* INCOMING DATA: None
* OUTGOING DATA: None
*/
// NOTE: I just created the graph inside this method since the createGraph
//       in the base class just reads in the vertex and adjavent vertex and not the weight
void weightedGraphType::createWeightedGraph()
{
    //createGraph();

    ifstream weightFile;
    string weightFileName;
    int vertex;
    int adjVertex;
    int weight;

    if (gSize != 0) 
    {
        clearGraph();
    }

        // prompt for the file name
    cout << "Enter file for weighted graph: ";
    cin >> weightFileName;

    // open file
    weightFile.open(weightFileName);

    // if file cannot be opened then output error message and stop 
    if (!weightFile.is_open())
    {
        cout << "ERROR OPENING WEIGHT FILE" << endl;
        exit(1);
    } 

    // gett the size of the weight matrix
    weightFile >> gSize;

    // while not at the end of the file
    while (!weightFile.eof())
    {
        // get input
        weightFile >> vertex >> adjVertex >> weight;
        // insert into graph at vertex and insert the adjacent vertices
        graph[vertex].insertLast(adjVertex);
        // in the matrix insert the adjacent vertex
        weights[vertex][adjVertex] = weight;
    }

    // close file
    weightFile.close();
} //createWeightedGraph

//---------------------------------------------------------------------------
/* The allShortestPathWeights finds the shortest path on all vertices and prints it
* INCOMING DATA: None
* OUTGOING DATA: None
*/
void weightedGraphType::allShortestPathWeights()
{
    for (int i = 0; i < gSize; i++) 
    {
        shortestPath(i);
        printShortestDistance(i);
    }
}

void weightedGraphType::printWgraph()
{
    printGraph();
     cout<<"::Weight Matrix::"<<endl;
     for(int i=0; i<gSize; i++)
     {
         for(int j=0; j<gSize; j++)
         {
             if(weights[i][j] < DBL_MAX)
             {
                 cout<<weights[i][j]<< " ";
             }
             else
             {
                 cout<<"UN "; //UN stands for undefined (treated in code as infinity)
             }

         }
         cout<<endl;
     }
     cout<<":::::::::::::"<<endl;
}

void weightedGraphType::shortestPath(int vertex)
{
    for (int j = 0; j < gSize; j++)
        smallestWeight[j] = weights[vertex][j];

    bool *weightFound;
    weightFound = new bool[gSize];

    for (int j = 0; j < gSize; j++)
        weightFound[j] = false;

    weightFound[vertex] = true;
    smallestWeight[vertex] = 0;

    for (int i = 0; i < gSize - 1; i++)
    {
        double minWeight = DBL_MAX;
        int v;

        for (int j = 0; j < gSize; j++)
            if (!weightFound[j])
                if (smallestWeight[j] < minWeight)
                {
                    v = j;
                    minWeight = smallestWeight[v];
                }

        weightFound[v] = true;

        for (int j = 0; j < gSize; j++)
            if (!weightFound[j])
                if (minWeight + weights[v][j] < smallestWeight[j])
                    smallestWeight[j] = minWeight + weights[v][j];
    } //end for
} //end shortestPath

void weightedGraphType::printShortestDistance(int vertex)
{
    cout << "Source Vertex: " << vertex << endl;
    cout << "Shortest Distance from Source to each Vertex."
         << endl;
    cout << "Vertex Shortest_Distance" << endl;

    for (int j = 0; j < gSize; j++){
        if(smallestWeight[j]<DBL_MAX)
        {
            cout << setw(4) << j << setw(12) << smallestWeight[j]<< endl;
        }
        else
        {
            cout << setw(4) << j << setw(12) << "UN"<< endl;
        }

    }
    cout << endl;
} //end printShortestDistance

    //Constructor
weightedGraphType::weightedGraphType(int size)
                  :graphType(size)
{
    weights = new double*[size];

    for (int i = 0; i < size; i++)
        weights[i] = new double[size];

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++)
        {
            weights[i][j] = DBL_MAX;
        }
    }

    smallestWeight = new double[size];
}

    //Destructor
weightedGraphType::~weightedGraphType()
{
    for (int i = 0; i < gSize; i++)
       delete [] weights[i];

    delete [] weights;
    delete smallestWeight;
}

#endif
