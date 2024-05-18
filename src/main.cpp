/**
 * Author: Mason Wolf
 * Date: May 18, 2024
 * https://github.com/mason-wolf/cpp-sandbox
 * 
 * A simple text-based game.
 * Failed project, but lots of lessons learned.
 * Some useful tidbits here include file IO, hashmaps, spliting strings.
 * Data structure in the game_data.txt just doesn't work correctly.
 * Should've thought it through better before writing all the parsing logic.
*/
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