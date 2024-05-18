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
        std::vector<Event> events;

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

        std::vector<Event> getEvents();
        void addEvent(const Event& event);
};