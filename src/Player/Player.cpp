#pragma once

#include "Player/Player.h"

Player::Player(PlayerData& pD)
{
	health = pD.startingHealth;
	currency = pD.startingCurrency;
}

bool Player::HasEnoughCurrency(int targetCurrency)
{
	return currency > targetCurrency;
}

void Player::GetCurrency(int value)
{
	currency += value;
}

void Player::DamagePlayer(int damage)
{
	health -= damage;
}

bool Player::IsAlive()
{
	return health > 0;
}
