#ifndef H_HPSP
#define H_HPSP

#include "Player.h"
#include "Map.h"
#include "Area.h"
#include "areaNode.h"


class HPSP : public Player
{
private:
    int hitPoints;
    int sanityPoints;
public:
    HPSP();
    int isGameOver();
    void resetPlayerStats();
    void reportStats();
    void consume(Map* mapptr);
    void use(Map* mapptr);
};

HPSP::HPSP()
{
    cout << "CREATING HPSP PLAYER" << endl;
    hitPoints = 100;
    sanityPoints = 100;
}


int HPSP::isGameOver()
{
    if (currentLocation->info.getID() == 1) {
        return 2;
    }
    else if(currentLocation->info.getGoal() == 1) {
        return 1;
    }
    else if(hitPoints == 0)
    {
        cout << "YOU DIED" << endl;
        return 3;
    }
    else if(sanityPoints == 0)
    {
        cout << "YOU HAVE GONE INSANE" << endl;
        return 4;
    }
    else {
        return 0;
    }
}


void HPSP::resetPlayerStats()
{
    hitPoints = 100;
    sanityPoints = 100;
}

void HPSP::reportStats()
{
    cout << "REPORTING STATS" << endl;
    cout << "Hit Points: " << hitPoints << endl;
    cout << "Sanity Points: " << sanityPoints << endl;
}


void HPSP::consume(Map* mapptr)
{
    string consume = " ";
    cout << "Which item to consume: ";
    getline(cin, consume);

    nodeType<Item*>* temp;
    temp = items.getFirst();

    if (temp == NULL) {
        cout << "NO ITEMS IN INVENTORY" << endl;
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->info->getName() == consume&& temp->info->getType() == "consume")
            {

                if(temp->info->getActiveArea() == 0 || temp->info->getActiveArea() == mapptr->reverseLookUp(currentLocation))
                {
                    cout << temp->info->getActiveMessage() << endl;
                    vector<Effect*> tempEffect = temp->info->getItemConsumeEffects();
                    if(tempEffect[0]->effectID == 0)
                    {
                        hitPoints -= tempEffect[0]->effectAmt;
                    }
                    else if(tempEffect[0]->effectID == 1)
                    {
                        hitPoints += tempEffect[0]->effectAmt;
                    }
                    else if(tempEffect[0]->effectID == 2)
                    {
                        sanityPoints -= tempEffect[0]->effectAmt;
                    }
                    else if (tempEffect[0]->effectID == 3)
                    {
                        sanityPoints += tempEffect[0]->effectAmt;
                    }
                }
                else
                {
                    cout << "CANNOT CONSUME THIS ITEM" << endl;
                }
            }

            temp = temp->link;
        }
    }

}


void HPSP::use(Map* mapptr)
{
    string use = " ";
    cout << "Which item to use: ";
    getline(cin, use);

    nodeType<Item*>* temp;
    temp = items.getFirst();

    if (temp == NULL) {
        cout << "NO ITEMS IN INVENTORY" << endl;
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->info->getName() == use && temp->info->getType() == "use")
            {
                
                if(temp->info->getActiveArea() == 0 || temp->info->getActiveArea() == mapptr->reverseLookUp(currentLocation))
                {
                    cout << temp->info->getActiveMessage();
                    vector<Rule*> tempEffect = temp->info->getItemUseRules();

                    for (int i = 0; i < tempEffect.size(); i++)
                    {
                        mapptr->useLinks(tempEffect[i]->beginRm, tempEffect[i]->destRm, tempEffect[i]->direction);
                    }
                }
                
            }
            else
            {
                cout << "CANNOT USE THIS ITEM" << endl;
            }

            temp = temp->link;
        }
    }

}


#endif
