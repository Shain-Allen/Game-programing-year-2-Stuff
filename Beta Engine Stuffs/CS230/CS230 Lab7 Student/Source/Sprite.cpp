//------------------------------------------------------------------------------
//
// File Name: Sprite.cpp
// Author(s): Shain Allen
// Project: CS230Lab5
// Course: wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "stdafx.h"
#include "Sprite.h"
#include "SpriteSource.h"
#include "Transform.h"
#include "Component.h"
#include "GameObject.h"

Sprite::Sprite(Beta::Mesh* mesh_, const SpriteSource* spriteSource_)
	: Component("Sprite"), transform(nullptr), mesh(mesh_), spriteSource(spriteSource_), flipX(false), flipY(false), frameIndex(0)
{
}

Component* Sprite::Clone() const
{
	return new Sprite(*this);
}

void Sprite::Initialize()
{
	transform = M_GetOwnerComponent(Transform);
}

void Sprite::Draw()
{
	Draw(Beta::Vector2D(0, 0));
}

void Sprite::Draw(const Beta::Vector2D& offset)
{
	if (transform == nullptr)
		return;

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

	CS230::Matrix2D offsetMat = CS230::Matrix2D().TranslationMatrix(offset.x, offset.y);

	CS230::Matrix2D transformMat = offsetMat * transform->GetMatrix();

	graphics.SetTransform(reinterpret_cast<const Beta::Matrix2D&>(transformMat));

	graphics.SetSpriteBlendColor(color);

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
