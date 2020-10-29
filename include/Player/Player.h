#pragma once

#include "Data/PlayerData.h"

class Player
{
public:
	Player(int startingHealth, int startingCurrency);
	Player(PlayerData& pD);

	bool HasEnoughCurrency(int targetCurrency);
	void DamagePlayer(int damage);
	bool IsAlive();

private:
	int health;
	int currency;
};
