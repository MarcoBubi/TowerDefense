#pragma once

#include "Data/EnemyData.h"
#include "Data/TileData.h"
#include "Data/PlayerData.h"
#include <string>
#include <vector>

#define ENEMY_DATA_PATH "resources/EnemyData.txt"
#define LEVEL_DATA_PATH "resources/Level_01.txt"

class DataLoader
{
public:
	DataLoader();
	~DataLoader();

	void LoadData();
	std::vector<EnemyData*> GetEnemyData();
	std::vector<TileData*> GetTileData();
	PlayerData* GetPlayerData();

private:
	void LoadEnemyData();
	void LoadLevelData();

	std::vector<std::string> SplitByDelimiter(std::string content, std::string delimiter); // utility function

	std::vector<EnemyData*> enemyData;
	std::vector<TileData*> tileData;
	PlayerData* playerData;

	const std::string COLON_DELIMITER = ":";
	const int ENEMY_TYPE_INDEX = 0;
	const int ENEMY_TIME_VALUE = 1;

	const int PLAYER_HEALTH_INDEX = 0;
	const int PLAYER_CURRENCY_INDEX = 1;
};