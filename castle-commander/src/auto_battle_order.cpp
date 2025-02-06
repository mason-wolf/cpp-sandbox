#include "auto_battle_order.h"
#include <cmath>
#include <iostream>


AutoBattleOrder::AutoBattleOrder(const Army& opponentArmy)
	: opponentArmy(opponentArmy) {}

void AutoBattleOrder::Execute() {
	std::cout << opponentArmy.GetInfantry().size() << std::endl;
	
	double trainingLevel = opponentArmy.GetTrainingLevel();
	double equipmentLevel = opponentArmy.GetEquipmentLevel();
	double moraleLevel = opponentArmy.GetMoraleLevel();

	std::cout << "Training Level: " << opponentArmy.GetTrainingLevel() << std::endl;
	std::cout << "Equipment Level: " << opponentArmy.GetEquipmentLevel() << std::endl;
	std::cout << "Morale Level: " << opponentArmy.GetMoraleLevel() << std::endl;

	double lethality = ((trainingLevel + equipmentLevel + moraleLevel) / 3) * 0.10;
	std::cout << "Lethality Score: " << std::round(lethality) << std::endl;
	std::cout << "Executing auto battle.." << std::endl;
}
