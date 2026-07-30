#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
    int level;
    int gold;
    int xp;
    int location;

public:
    void setLevel(int level);
    int getLevel();
    void setGold(int gold);
    int getGold();
    void setLocation(int location);
    int getLocation();
};

#endif