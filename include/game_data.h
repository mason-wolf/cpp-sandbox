#include <iostream>
#include <vector>
#include <event.h>

class GameData {
    public:
        static std::vector<std::string> data;
        static std::vector<Event> events;
    
    public:
        static void load();
        static void init();
};