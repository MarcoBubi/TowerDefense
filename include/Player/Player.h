#pragma once

#include "Data/PlayerData.h"

class Player
{
public:
	Player(PlayerData& pD);

	bool HasEnoughCurrency(int targetCurrency);

	void GetCurrency(int value);
	void DamagePlayer(int damage);
	bool IsAlive();

private:
	int health;
	int currency;
};
