#include "stdafx.h"
#include "SpriteTilemap.h"
#include "Sprite.h"
#include "Tilemap.h"
#include "Transform.h"

SpriteTilemap::SpriteTilemap(Beta::Mesh* mesh_, const SpriteSource* spriteSource_, const Tilemap* map_)
	: Sprite(mesh_, spriteSource_), map(map_)
{
}

Component* SpriteTilemap::Clone() const
{
	return new SpriteTilemap(*this);
}

void SpriteTilemap::Draw()
{
	using namespace Beta;

	unsigned int width = map->GetWidth();
	unsigned int height = map->GetHeight();
	Vector2D scale = transform->GetScale();

	for (unsigned int x = 0; x < width; x++)
	{
		for (unsigned int y = 0; y < height; y++)
		{
			int cellValue = map->GetCellValue(x, y);
			if (cellValue == 0)
				continue;
			SetFrame(cellValue - 1);
			Vector2D offset = Vector2D((x * scale.x), -(y * scale.y));
			Sprite::Draw(offset);
		}
	}
}

void SpriteTilemap::SetTilemap(const Tilemap* map_)
{
	map = map_;
}
