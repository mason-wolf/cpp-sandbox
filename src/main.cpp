#include <iostream>
#include "game_data.h"
#include <string>
#include <csignal> 
#include <cstdlib> 

void exitHandler(int signal) {
    if (signal == SIGINT) {
        std::cout << "Goodbye! Safe travels brave warrior." << std::endl;
        exit(EXIT_SUCCESS);
    }
}

int main() {
    std::signal(SIGINT, exitHandler);
    GameData gameData;
    gameData.load();
    gameData.initLevels();
    
    std::string option;
    
    while(true) {
        std::cin >> option;
    }
}