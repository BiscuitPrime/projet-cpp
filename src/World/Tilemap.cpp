#include "Tilemap.h"

#include <iostream>

Tilemap::Tilemap(std::string fileName)
{
	/*pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("../../../../resources/images/tilemap/" + fileName);
	if (!result)
	{
		std::cerr << "Could not open file visage.xml because " << result.description() << std::endl;
		return 1;
	}*/
}

int Tilemap::buildTilemap(std::string fileName) {
	return 0;
}

int Tilemap::setTile(Tile* tile)
{
	// sets ptr to a tile at its corresponding coordinate in the tilemap;
	/*float x = tile.getX();
	float y = tile.getY();
	if (x < 0 || x >= columns) {
		std::cout << "Could not set tile: x coordinate out of bounds\n";
		return -1;
	}
	if (y < 0 || y >= lines) {
		std::cout << "Could not set tile: y coordinate out of bounds\n";
		return -1;
	}
	if (tilemap[y][x] != nullptr) {
		std::cout << "Warning tile (" << x << ", " << y << ") is being rewritten\n";
	}
	tilemap[y][x] = tile;*/
	return 0;
}