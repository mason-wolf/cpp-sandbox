#include "../include/game_data.h"
#include "iostream"
#include "fstream"
#include "string"
#include <sstream>

std::vector<std::string> GameData::data;
std::vector<Event> GameData::events;
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
            std::cout << e;
            eventIdList.push_back(std::stoi(e));
          //  std::cout << event.getName() << " DEST_ID: " << e << " " << event.getPrompt() << "\n\n";
        }
        event.setEventIds(eventIdList);
        events.push_back(event);
    }

    for (auto &event : events)
    {
        for (int id : event.getEventIds())
        {
            std::cout << id;
          //  std::cout << event.getName() << events[id].getId() << std::endl;
            // if (id == events[id].getId())
            // {
            //     std::cout << id;
            //     event.addEvent(event);
            // }
        }
    }
}
