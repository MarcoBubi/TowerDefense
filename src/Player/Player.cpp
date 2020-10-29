#pragma once

#include "Player/Player.h"

Player::Player(int startingHealth, int startingCurrency) :
	health(startingHealth),
	currency(startingCurrency)
{

}

Player::Player(PlayerData& pD)
{
	Player(pD.startingHealth, pD.startingCurrency);
}

bool Player::HasEnoughCurrency(int targetCurrency)
{
	return currency > targetCurrency;
}

void Player::DamagePlayer(int damage)
{
	health -= damage;
}

bool Player::IsAlive()
{
	return health > 0;
}
