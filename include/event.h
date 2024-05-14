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
        std::vector<int> events;
        
    public:
        Event();
        ~Event();
        
        int getId() const;
        void setId(int id);
        
        std::string getName() const;
        void setName(const std::string& name);
        
        std::string getPrompt() const;
        void setPrompt(const std::string& prompt);
        
        std::vector<int> getEvents();
        void setEvents(const std::vector<int>& prompt);
};