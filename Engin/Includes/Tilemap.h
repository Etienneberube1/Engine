#pragma once
#include <vector>
#include <map>
#include <string>
#include <RectI.h>
#include <Component.h>
#include <IDrawable.h>
#include "RectF.h"

namespace project
{
    // Type definitions for tilemap layers and tilesets.
    typedef std::vector<std::vector<int>> TLayer;
    typedef std::map<std::string, TLayer> TTilemap;
    typedef std::vector<RectI> TTileset;

    // Class representing a tile-based map.
    class Tilemap : public Component, public IDrawable
    {
    public:
        // Destructor.
        virtual ~Tilemap() = default;

        // Constructors.
        Tilemap();
        Tilemap(Entity* parent);

        // Draws the tilemap.
        virtual void Draw() override;

        // Loads a tilemap from a file and sets its dimensions and tile size.
        void Load(const std::string& filename, int mapW, int mapH, int tileW, int tileH);

        // Adds a layer to the tilemap.
        void AddLayer(const std::string& layer, TLayer tiles);

        // Retrieves a layer by name.
        TLayer GetLayer(const std::string& name);

        // Checks for collisions between the tilemap and an entity's rectangle.
        bool IsColliding(const RectF& entityRect, RectF* collidingTileRect, const std::string& layerName);

        // Creates a layer from a file.
        TLayer CreateLayer(const std::string& filename);

    private:
        // Tilemap layers.
        TTilemap m_Tilemap;

        // Dimensions of the tilemap.
        int m_Width = 0;
        int m_Height = 0;

        // ID of the tileset texture.
        size_t m_TilesetId = 0;

        // Dimensions of each tile.
        int m_TileWidth = 0;
        int m_TileHeight = 0;

        // Tileset definition.
        TTileset m_Tileset;

        // Scaling factor for rendering tiles.
        int m_ScaleFactor = 1;
    };
}
