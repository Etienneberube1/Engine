#include <Tilemap.h>
#include <Engine.h>


#include <fstream>
#include <sstream>
#include <iostream>
#include "RectI.h"
#include "RectF.h"

project::Tilemap::Tilemap() : Tilemap(nullptr)
{
}

project::Tilemap::Tilemap(Entity* parent) : Component(parent)
{
}

void project::Tilemap::Load(const std::string& filename, int tileW, int tileH, int col, int count)
{
	m_TilesetId = Graphics().LoadTexture(filename);
	if (!m_TilesetId) return;
	for (int i = 0; i < count; i++)
	{
		int y = i / col;
		int x = i - y * col;


		RectI tile;
		
		tile.x = x * tileW;
		tile.y = y * tileH;
		tile.w = tileW;
		tile.h = tileH;

		m_Tileset.push_back(tile);
	}
	m_TileWidth = tileW;
	m_TileHeight = tileH;
}

void project::Tilemap::AddLayer(const std::string& layerName, TLayer layerTiles)
{
	for (auto it = m_Tilemap.begin(); it != m_Tilemap.end(); it++)
	{
		if ((it)->first == layerName) return;
	}
	m_Tilemap.emplace(std::pair<std::string, TLayer>(layerName, layerTiles));
}

project::TLayer project::Tilemap::GetLayer(const std::string& name)
{
	if (m_Tilemap.count(name) > 0)
	{
		return m_Tilemap[name];
	}

	return TLayer{};
}

int Clamp(int value, const int min, const int max)
{
	if (value < min)
	{
		value = min;
	}
	else if (value > max)
	{
		value = max;
	}

	return value;
}

bool project::Tilemap::IsColliding(const RectF& entityRect, RectF* collidingTileRect) {
	const TLayer& collisionLayer = m_Tilemap["ground"]; 
	for (int i = 0; i < m_Height; i++) {
		for (int j = 0; j < m_Width; j++) {
			int tileIndex = collisionLayer[i][j];
			if (tileIndex != -1) { // Check if the tile is not -1 (collidable)
				RectF tileRect{ j * m_TileWidth, i * m_TileHeight, m_TileWidth, m_TileHeight };
				if (Engine::Get().Physics().CheckRects(entityRect, tileRect)) {
					if (collidingTileRect) {
						*collidingTileRect = tileRect;
					}
					return true;
				}
			}
		}
	}
	return false;
}
//project::TLayer project::Tilemap::CreateLayer(const std::string& filename)
//{
//	TLayer newLayer = TLayer();
//
//	std::ifstream myFile(filename);
//
//	
//	std::string line;
//	int temp;
//
//	while (std::getline(myFile, line))
//	{
//		std::stringstream file(line);
//		int colIdx = 0;
//
//		std::vector<int> row;
//		while (file >> temp)
//		{
//			row.push_back(temp + 1);
//
//			if (file.peek() == ',') file.ignore();
//
//			colIdx++;
//		}
//		newLayer.push_back(row);
//	}
//	myFile.close();
//
//	return newLayer;
//}

project::TLayer project::Tilemap::CreateLayer(const std::string& filename) {
	TLayer newLayer = TLayer();
	std::ifstream myFile(filename);
	std::string line;
	int temp, rowCount = 0, colCount = 0;

	while (std::getline(myFile, line)) {
		std::stringstream file(line);
		std::vector<int> row;
		colCount = 0; // Reset column count for each row

		while (file >> temp) {
			row.push_back(temp + 1);
			if (file.peek() == ',') file.ignore();
			colCount++;
		}

		rowCount++; // Increase row count
		newLayer.push_back(row);
	}

	myFile.close();

	// Update the tilemap's dimensions if this layer is larger
	m_Width = std::max(m_Width, colCount);
	m_Height = std::max(m_Height, rowCount);

	return newLayer;
}


void project::Tilemap::Draw()
{
	for (auto layer : m_Tilemap)
	{
		for (int y = 0; y < layer.second.size(); y++)
		{
			for (int x = 0; x < layer.second[y].size(); x++)
			{
				int _index = layer.second[y][x] - 1;
				if (_index >= 0)
				{
					RectI _src = m_Tileset[_index];
					RectF _dst{
					x * m_TileWidth,
					y * m_TileHeight,
					m_TileWidth,
					m_TileHeight
					};
					Graphics().DrawTexture(m_TilesetId, _src, _dst, 0.0, Flip(), Color::WHITE);
				}
			}
		}
	}
}