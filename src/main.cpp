#include <iostream>
#include "game_data.h"
#include "game.h"
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
    Game game;
    game.start();
    
    std::string option;
    
    while(true) {
        std::cin >> option;
        std::cout << option;
        int optionInt = std::stoi(option);
        game.loadNextEvent(optionInt);
    }
}