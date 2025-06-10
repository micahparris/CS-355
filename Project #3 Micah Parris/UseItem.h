#ifndef H_UI
#define H_UI

#include "Item.h"


class UseItem : public Item 
{
public:
    vector<Rule*> rules;

    UseItem() 
    {
        type = "use";
    }

    void setActiveMessage(string s){
        //cout<<"DEBUG WARNING: DEBUG FOR USE ITEM."<<endl;
        activeMessage = s;
    }

    string getActiveMessage(){
        //Objects of the Item (basic items) class don't have active messages.
        return activeMessage;
    }
    
    void setActiveArea(int i){
        activeArea = i;
        //cout<<"DEBUG WARNING: Objects of the Item (basic items) class don't have active areas."<<endl;
    }

    int getActiveArea(){
        //as this is a basic item, it doesn't have an active area
        return activeArea;
    }

    void addRule(Rule* temp){
        rules.push_back(temp);
    }

    vector<Rule*> getItemUseRules(){
        //shouldn't ever call this method directly
        return rules;
    }

    void addEffect(Effect* temp){
        //cout<<"DEBUG WARNING: Objects of the Item (basic items) class don't have associated effects."<<endl;
    }

    vector<Effect*> getItemConsumeEffects(){
        //shouldn't ever call this method directly
        vector<Effect*> blank;
        return blank;
    }



};


#endif