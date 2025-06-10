#ifndef H_CI
#define H_CI

#include "Item.h"

class ConsumeItem : public Item
{
public:
    ConsumeItem() 
    {
        type = "consume";
    }

    vector<Effect*> listEffects;

     void setActiveMessage(string s)
    {
        activeMessage = s;
    }

    string getActiveMessage()
    {
        return activeMessage;
    }

    void setActiveArea(int i)
    {
        activeArea = i;
    }

    int getActiveArea()
    {
        //as this is a basic item, it doesn't have an active area
        return activeArea;
    }

    void addRule(Rule* temp)
    {
        //cout<<"DEBUG WARNING: Objects of the Item (basic items) class don't have associated rules."<<endl;
    }

    vector<Rule*> getItemUseRules()
    {
        //shouldn't ever call this method directly
        vector<Rule*> blank;
        return blank;
    }

    void addEffect(Effect* temp)
    {
        listEffects.push_back(temp);
    }

    vector<Effect*> getItemConsumeEffects(){
        //shouldn't ever call this method directly
        //vector<Effect*> blank;
        return listEffects;
    }
};




#endif