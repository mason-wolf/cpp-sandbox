/**
 * Author: Mason Wolf
 * Date: May 18, 2024
 * https://github.com/mason-wolf/cpp-sandbox
 *
 * A simple text-based game.
 * Some useful tidbits here include file IO, hashmaps, splitting strings.
 */
#include <iostream>
#include "game_data.h"
#include "game.h"
#include <string>
#include <csignal>
#include <cstdlib>

void exitHandler(int signal)
{
    if (signal == SIGINT)
    {
        std::cout << "Goodbye! Safe travels brave explorer." << std::endl;
        exit(EXIT_SUCCESS);
    }
}

int main()
{
    std::signal(SIGINT, exitHandler);
    Game game;
    game.start();

    std::string option;

    while (true)
    {
        std::cin >> option;

        try
        {
            int optionInt = std::stoi(option);

            int index = 1;
            for (const auto &o : game.gameData.currentLevel.getOptions())
            {
                if (index == optionInt)
                {
                    game.gameData.loadLevel(std::stoi(o.second));
                    break;
                }
                index++;
            }
        }
        catch (const std::invalid_argument &)
        {
            std::cerr << "Invalid input." << std::endl;
        }
    }
}