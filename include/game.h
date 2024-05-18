#ifndef GAME_H
#define GAME_H

#include <game_data.h>

class Game {
    public:
        Game();
        ~Game();
        GameData gameData;

        void setGameData(GameData gameData);
        void loadNextEvent(int eventId);
        void start();
};

#endif