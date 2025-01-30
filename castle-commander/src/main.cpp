#include <iostream>
#include <vector>
#include "unit.h"
#include "army.h"
#include "commander.h"
#include "battle.h"

int main() {	
	Army playerArmy;
	playerArmy.set_num_infantry(8);
	playerArmy.set_num_archers(8);
	playerArmy.set_num_cavalry(8);

	Army opponentArmy;
	opponentArmy.set_num_infantry(80);
	opponentArmy.set_num_archers(80);
	opponentArmy.set_num_cavalry(80);
	
	Commander player;
	player.set_army(playerArmy);
	
	Commander opponent;
	opponent.set_army(opponentArmy);
	
	Battle battle;
	battle.set_player(player);
	battle.set_opponent(opponent);
	battle.start();
}

