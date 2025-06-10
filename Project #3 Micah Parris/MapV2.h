#ifndef H_MV
#define H_MV

#include "Map.h"
#include "ull.h"
#include "Area.h"
#include "AreaNode.h"
#include "HPSPPlayer.h"
#include "BasicPlayer.h"
#include "UseItem.h"
#include "consumeItem.h"
#include "Item.h"
#include "structs.h"


class MapV2 : public Map
{
public:
    Player* mainPlayer;
    vector<Item*> mapItems;
    void makeItem();
    void makeConsumeItem();
    void makeUseItem();
    void makeBasicItem();
    void makePlayer();
    Player* getPlayer();
    void buildMap();
    void resetItems();
    void insertItems();
    friend ostream& operator<<(ostream&, MapV2&);
};




#endif
