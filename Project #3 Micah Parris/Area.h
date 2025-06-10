#ifndef H_area
#define H_area

#include <string>
#include <iostream>
#include <vector>


#include "ull.h"


#include "Item.h"



using namespace std;

class Area{
  public:
    uLList<Item*> areaItems;
    void search();
    void setDescription (string);
    void setGoal(bool);
    void setID(bool);
    string getDescription();
    bool getID();
    bool getGoal();
    void displayArea();
  private:
     string description;
     bool instadeath;
     bool goal;
};

#endif // H_area
