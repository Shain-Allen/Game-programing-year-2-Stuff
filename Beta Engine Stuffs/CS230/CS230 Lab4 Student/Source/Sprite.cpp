#include "stdafx.h"
#include "Sprite.h"
#include "SpriteSource.h"

Sprite::Sprite(Beta::Mesh* mesh_, const SpriteSource* spriteSource_)
	: mesh(mesh_), spriteSource(spriteSource_), flipX(false), flipY(false), frameIndex(0)
{
}

void Sprite::Draw()
{
	if (mesh == nullptr)
		return;

	using namespace Beta;

	GraphicsEngine& graphics = *EngineGetModule(GraphicsEngine);
	
	graphics.GetSpriteShader().Use();

	if (spriteSource != nullptr)
	{
		spriteSource->UseTexture(frameIndex, flipX, flipY);
	}
	else
	{
		graphics.GetDefaultTexture().Use();
	}

	graphics.SetTransform(Vector2D(0, 0), Vector2D(1, 1), 0);

	mesh->Draw();
}

void Sprite::SetAlpha(float alpha)
{
	color.a = alpha;
}

float Sprite::GetAlpha() const
{
	return color.a;
}

void Sprite::SetFrame(unsigned int frameIndex_)
{
	std::cout << "Sprite::SetFrame(" << frameIndex_ <<")" << std::endl;

	if (frameIndex_ < spriteSource->GetFrameCount())
	{
		frameIndex = frameIndex_;
	}
}

void Sprite::SetMesh(Beta::Mesh* mesh_)
{
	mesh = mesh_;
}

void Sprite::SetSpriteSource(const SpriteSource* spriteSource_)
{
	spriteSource = spriteSource_;
}

const SpriteSource* Sprite::GetSpriteSource()
{
	return spriteSource;
}

void Sprite::SetColor(Beta::Color color_)
{
	color = color_;
}

const Beta::Color& Sprite::GetColor() const
{
	return color;
}

void Sprite::SetFlipX(bool flipX_)
{
	flipX = flipX_;
}

void Sprite::SetFlipY(bool flipY_)
{
	flipY = flipY_;
}
