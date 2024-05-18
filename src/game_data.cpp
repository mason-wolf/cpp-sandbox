#include "../include/game_data.h"
#include "iostream"
#include "fstream"
#include "string"
#include <unordered_map>
#include <sstream>
#include <cstdlib> 
#if defined(_WIN32) || defined(_WIN64)
    #define CLEAR "CLS"
#else
    #define CLEAR "clear"
#endif

std::vector<std::string> GameData::data;
std::vector<Event> GameData::events;
std::unordered_map<int, int> eventOptions;
int currentEvent = 0;

/**
 * Handles comma-delimited file reading line by line.
 */
std::vector<std::string> splitString(const std::string &s, char delimiter)
{
    std::vector<std::string> tokens;
    std::stringstream ss(s);
    std::string token;

    while (std::getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}

/**
 * Loads the game data from file.
 */
void GameData::load()
{
    std::ifstream file("game_data.txt");

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            data.push_back(line);
        }
        file.close();
    }
    else
    {
        std::cerr << "Unable to open file.";
    }
}

/**
 * Load events from the game data.
 */
void GameData::init()
{
    for (size_t i = 0; i < data.size(); i++)
    {
        char delimiter = '|';
        std::vector<std::string> lines = splitString(data[i], delimiter);
        // Create event from each line.
        Event event;
        event.setId(std::stoi(lines[1]));
        event.setName(lines[2]);
        event.setPrompt(lines[3]);
        // Get child events.
        std::vector<std::string> eventIds = splitString(lines[4], ',');
        std::vector<int> eventIdList;
        for (auto &e : eventIds)
        {
            eventIdList.push_back(std::stoi(e));
        }
        event.setEventIds(eventIdList);
        events.push_back(event);
    }
    startEvent(0);
}

void GameData::startEvent(int eventId)
{
    system(CLEAR);
    std::cout << "STARTING EVENT" << eventId;
    eventOptions.clear();
    currentEvent = eventId;
    std::cout << "\n"
              << events[eventId].getPrompt() << std::endl;
    int choice = 1;
    Event childEvent;
    for (auto &e : events[eventId].getEventIds())
    {
        childEvent = getEventById(e);
        eventOptions[choice] = e;
        std::cout << "\n"
                  << choice << " " << childEvent.getPrompt();
        choice++;
    }
}

void GameData::startChildEvent(int childEventId) {
    for (const auto &pair : eventOptions)
    {
        std::cout << pair.second;
        if (pair.first == childEventId) {
            startEvent(pair.second);
        }
    }
}

Event GameData::getEventById(int id)
{
    for (auto &e : events)
    {
        if (id == e.getId())
        {
            return e;
        }
    }
}
