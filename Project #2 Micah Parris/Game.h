#ifndef H_MAPV2
#define H_MAPV2
    #include "MapV2.h"
#endif // H_MAPV2

#ifndef H_PLAYER
#define H_PLAYER
    #include "Player.h"
#endif // H_PLAYER


class Game{
	private:
		Player player1;
		MapV2 map;

  	public:
		Game();
  		void play();
  		void resetGame();
};
