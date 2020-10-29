#pragma once

#include "Loaders/DataLoader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

DataLoader::DataLoader() :
	playerData(nullptr)
{
	// This parses is shitty and the data is outputed in 2 folders atm 
	//if I'll have time I'll reunite them and parse as one as it should be
}

DataLoader::~DataLoader()
{

}

void DataLoader::LoadData()
{
	LoadEnemyData();
	LoadLevelData();
}

std::vector<EnemyData*> DataLoader::GetEnemyData()
{
	return enemyData;
}

std::vector<TileData*> DataLoader::GetTileData()
{
	return tileData;
}

PlayerData* DataLoader::GetPlayerData()
{
	return playerData;
}

void DataLoader::LoadEnemyData()
{
	std::ifstream file;
	file.open(ENEMY_DATA_PATH);

	if (!file)
	{
		throw std::string("Could not open file!");
	}

	std::string line;
	while (file.is_open())
	{
		while (std::getline(file, line))
		{
			std::vector<std::string> words = SplitByDelimiter(line, COLON_DELIMITER);
			int enemyTypeValue = std::stoi(words[ENEMY_TYPE_INDEX]);
			float enemyStartTime = std::stof(words[ENEMY_TIME_VALUE]);
			enemyData.push_back(new EnemyData(static_cast<EnemyData::EnemyType>(enemyTypeValue), enemyStartTime));
			// Testing only
			std::cout << "Loading line: " << line << std::endl;
		}
		file.close();
	}
}

void DataLoader::LoadLevelData()
{
	std::ifstream file;
	file.open(LEVEL_DATA_PATH);

	if (!file)
	{
		throw std::string("Could not open file!");
	}

	std::string line;
	while (file.is_open())
	{
		std::getline(file, line);
		std::vector<std::string> words = SplitByDelimiter(line, COLON_DELIMITER);
		playerData = new PlayerData(std::stoi(words[PLAYER_HEALTH_INDEX]), std::stoi(words[PLAYER_CURRENCY_INDEX]));

		while (std::getline(file, line))
		{
			for (int i = 0; i < line.length(); ++i)
			{
				std::string letter = line.substr(i, 1);
				tileData.push_back(new TileData(letter));
			}
			std::cout << "Loading line: " << line << std::endl;
		}
		file.close();
	}
}

std::vector<std::string> DataLoader::SplitByDelimiter(std::string content, std::string delimiter)
{
	std::vector<std::string> words;
	while (content.size())
	{
		size_t index = content.find(delimiter);
		if (index != std::string::npos)
		{
			words.push_back(content.substr(0, index));
			content = content.substr(index + delimiter.size());

			if (content.size() == 0) words.push_back(content);
		}
		else
		{
			words.push_back(content);
			content = "";
		}
	}
	
	return words;
}
