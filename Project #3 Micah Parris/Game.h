#ifndef H_G
#define H_G


#include "MapV2.h"
#include "Map.h"
#include "Area.h"
#include "areaNode.h"
#include "Player.h"
#include "BasicPlayer.h"
#include "HPSPPlayer.h"

 // H_PLAYER


class Game{
	private:
		Player* player1;
		MapV2* map = new MapV2;

  	public:
		Game();
  		void play();
  		void resetGame();
};

#endif
