#ifndef GAME_DATA_H
#define GAME_DATA_H

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
        static void startEvent(int eventId);
        static void startChildEvent(int childEventId);
        static Event getEventById(int eventId);
};

#endif 