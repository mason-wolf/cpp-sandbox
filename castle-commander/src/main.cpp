#include <iostream>
#include <vector>
#include "unit.h"
#include "army.h"
#include "commander.h"
#include "battle.h"

int main() {	
	Army playerArmy;
	playerArmy.SetNumInfantry(8);
	playerArmy.SetNumArchers(8);
	playerArmy.SetNumCavalry(8);

	Army opponentArmy;
	opponentArmy.SetNumInfantry(80);
	opponentArmy.SetNumArchers(80);
	opponentArmy.SetNumCavalry(80);
	
	Commander player;
	player.SetArmy(playerArmy);
	
	Commander opponent;
	opponent.SetArmy(opponentArmy);
	
	Battle battle;
	battle.SetPlayer(player);
	battle.SetOpponent(opponent);
	battle.Start();
}

