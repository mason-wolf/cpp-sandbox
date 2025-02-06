#include <iostream>
#include <vector>
#include "unit.h"
#include "army.h"
#include "commander.h"
#include "battle.h"
#include <random>


int GenerateRandom(int min, int max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(min, max);
	return distr(gen);
}

int main() {	
	Army playerArmy;
	playerArmy.SetNumInfantry(40);
	playerArmy.SetNumArchers(40);
	playerArmy.SetNumCavalry(40);

	Army opponentArmy;
	opponentArmy.SetNumInfantry(GenerateRandom(8, 40));
	opponentArmy.SetNumArchers(GenerateRandom(8, 40));
	opponentArmy.SetNumCavalry(GenerateRandom(8, 40));
	opponentArmy.SetTrainingLevel(GenerateRandom(1, 100));
	opponentArmy.SetEquipmentLevel(GenerateRandom(1, 100));
	opponentArmy.SetMoraleLevel(GenerateRandom(1, 100));
	
	Commander player;
	player.SetArmy(playerArmy);
	
	Commander opponent;
	opponent.SetArmy(opponentArmy);
	
	Battle battle;
	battle.SetPlayer(player);
	battle.SetOpponent(opponent);
	battle.Start();
}

