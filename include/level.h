#include <iostream>
#include <string>

class Level {
    private:
        int id;
        std::string name;
        std::string prompt;
        
    public:
        Level();
        ~Level();
        
        int getId() const;
        void setId(int id);
        
        std::string getName() const;
        void setName(const std::string& name);
        
        std::string getPrompt() const;
        void setPrompt(const std::string& prompt);
};