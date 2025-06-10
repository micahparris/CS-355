#include <iostream>
#include "Area.h"

void Area::search()
{
    nodeType<Item*> *temp = areaItems.getFirst();

    if (temp == nullptr) 
    {
        cout << "There are not items in this area" << endl;
    }
    else
    {
        cout << "The following items are in this area:" << endl;

        while (temp != nullptr) 
        {
            cout << "\t" << temp->info->getName() << endl;
           
            temp = temp->link;
        }
    }
};

void Area::setDescription (string desc){
    description = desc;
}
void Area::setGoal(bool g){
    goal = g;
}
void Area::setID(bool id){
    instadeath = id;
}
string Area::getDescription(){
    return description;
}
bool Area::getID(){
    return instadeath;
}
bool Area::getGoal(){
    return goal;
}
void Area::displayArea(){
    cout<<description<<endl;
}
