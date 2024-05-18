#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>
#include <vector>

/**
 * Represents a game event.
 */
class Event {
    private:
        int id;
        std::string name;
        std::string prompt;
        std::vector<int> eventIds;

    public:
        Event();
        ~Event();
        
        int getId() const;
        void setId(int id);
        
        std::string getName() const;
        void setName(const std::string& name);
        
        std::string getPrompt() const;
        void setPrompt(const std::string& prompt);
        
        std::vector<int> getEventIds();
        void setEventIds(const std::vector<int>& prompt);
};

#endif