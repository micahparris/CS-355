#ifndef H_BP
#define H_BP

#include "Player.h"


class BasicPlayer : public Player
{
public:
    BasicPlayer();
    int isGameOver();
    void resetPlayerStats();
    void reportStats();
    void consume(Map* mapptr);
    void use(Map* mapptr);
};


BasicPlayer::BasicPlayer()
{
    cout << "CREATING BASIC PLAYER" << endl;
}


int BasicPlayer::isGameOver()
{
    if (currentLocation->info.getID() == 1) {
        return 2;
    }
    else if(currentLocation->info.getGoal() == 1) {
        return 1;
    }
    else {
        return 0;
    }
}

void BasicPlayer::resetPlayerStats()
{
    cout << "NO STATS TO RESET" << endl;
};


void BasicPlayer::reportStats() 
{
    cout << "NO STATS TO REPORT" << endl;
}


void BasicPlayer::consume(Map* mapptr)
{
    cout << "NO ITEMS TO CONSUME" << endl;
}


void BasicPlayer::use(Map* mapptr)
{
    cout << "NO ITEMS TO USE" << endl;
}

#endif