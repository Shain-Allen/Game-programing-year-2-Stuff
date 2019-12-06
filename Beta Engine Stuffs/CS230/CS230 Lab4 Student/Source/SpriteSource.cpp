#include "stdafx.h"
#include "SpriteSource.h"

SpriteSource::SpriteSource(const Beta::Texture* texture, std::string name, unsigned numCols, unsigned numRows)
	: texture(texture), name(name), numCols(numCols), numRows(numRows)
{
}

void SpriteSource::UseTexture(unsigned frameIndex_, bool flipX_, bool flipY_) const
{
	using namespace Beta;

	Vector2D uvOffset = GetUV(frameIndex_);

	texture->Use(1, 1, flipX_, flipY_, uvOffset);
}

unsigned SpriteSource::GetFrameCount() const
{
	return numCols * numRows;
}

const std::string& SpriteSource::GetName() const
{
	return name;
}

const Beta::Vector2D SpriteSource::GetTextureDimensions() const
{
	return Beta::Vector2D(numRows, numCols);
}

const Beta::Vector2D SpriteSource::GetUV(unsigned int frameIndex_) const
{
	float colsSize = 1.0f / static_cast<float>(numCols);
	float rowSize = 1.0f / static_cast<float>(numRows);
	
	unsigned int cols = numCols % frameIndex_;
	unsigned int rows = numRows / frameIndex_;

	using namespace Beta;

	Vector2D uv(cols * colsSize, rows * rowSize);

	return uv;
}
