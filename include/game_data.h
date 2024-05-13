#include <iostream>
#include <vector>

class GameData {
    public:
        static std::vector<std::string> data;
    
    public:
        static void load();
        static void initLevels();
};