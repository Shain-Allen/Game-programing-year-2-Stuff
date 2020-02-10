#include "stdafx.h"
#include "ColorChange.h"
#include "Component.h"
#include "GameObject.h"
#include "Sprite.h"
#include "Collider.h"


void ColorChangeCollisionHandler(GameObject& object, GameObject& other);

ColorChange::ColorChange(const Beta::Color& normalColor, const Beta::Color& collidedColor, float collidedColorTime)
	: Component("ColorChange"), sprite(nullptr), normalColor(normalColor), collidedColor(collidedColor), collidedColorTime(collidedColorTime), collided(false), timer(0.0f)
{
}

Component* ColorChange::Clone() const
{
	return new ColorChange(*this);
}

void ColorChange::Initialize()
{
	sprite = M_GetOwnerComponent(Sprite);
	M_GetOwnerComponent(Collider)->SetCollisionHandler(ColorChangeCollisionHandler);
}

void ColorChange::Update(float dt)
{
	if (collided == true)
	{
		sprite->SetColor(collidedColor);
		collided = false;
		timer = collidedColorTime;
	}

	if (collided == false && timer <= 0.0f)
	{
		sprite->SetColor(normalColor);
	}

	timer -= dt;
}

void ColorChangeCollisionHandler(GameObject& object, GameObject& other)
{
	UNREFERENCED_PARAMETER(other);

	M_GetComponent((&object), ColorChange)->collided = true;
	M_GetComponent((&object), ColorChange)->timer = M_GetComponent((&object), ColorChange)->collidedColorTime;
}
