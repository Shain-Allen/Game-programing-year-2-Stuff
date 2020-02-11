#include "stdafx.h"
#include "Level3.h"
#include "MeshHelper.h"
#include "Level.h"
#include "Archetypes.h"
#include "SpriteSource.h"
#include "Sprite.h"
#include "Transform.h"
#include "GameObject.h"
#include "GameObjectManager.h"
#include "RigidBody.h"
#include "Space.h"
#include "Level1.h"
#include "Level2.h"

using namespace Beta;
using std::cout;
using std::endl;

Level3::Level3()
	:Level("Level3"), meshQuad(nullptr), spriteSourceCircle(nullptr), textureCircle(nullptr), circleSpeed(0), pointSpeed(0)
{
}

void Level3::Load()
{
	cout << "Level3::Load" << endl;

	meshQuad = CreateQuadMesh(Vector2D(1.0f, 1.0f), Vector2D(0.5f, 0.5f));

	textureCircle = Texture::CreateTextureFromFile("Circle.png");

	spriteSourceCircle = new SpriteSource(textureCircle, "Circle");
}

void Level3::Initialize()
{
	cout << "Level3::Initialize" << endl;

	GameObject* circle = Archetypes::CreateCircle(meshQuad, spriteSourceCircle);
	GameObject* point = Archetypes::CreatePoint(meshQuad, spriteSourceCircle);

	M_GetComponent(point, Transform)->SetTranslation(Vector2D(0.0f, 1.0f));
	
	M_GetComponent(point, RigidBody)->SetVelocity(Vector2D(0.0f, 0.5f));

	GameObject* rectangle = Archetypes::CreateRectangle(meshQuad);
	M_GetComponent(rectangle, Transform)->SetTranslation(Vector2D(-2.5f, 2.5f));
	M_GetComponent(rectangle, RigidBody)->SetVelocity(Vector2D(0.5f, -0.5f));

	GetSpace()->GetObjectManager().AddObject(*rectangle);
	GetSpace()->GetObjectManager().AddObject(*circle);
	GetSpace()->GetObjectManager().AddObject(*point);

}

void Level3::Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);
	Beta::Input& input = *EngineGetModule(Beta::Input);

	if (input.CheckTriggered('1'))
	{
		GetSpace()->SetLevel(new Level1);
	}

	if (input.CheckTriggered('2'))
	{
		GetSpace()->SetLevel(new Level2);
	}

	if (input.CheckTriggered('3'))
	{
		GetSpace()->RestartLevel();
	}


}

void Level3::Unload()
{
	cout << "Level3::Unload" << endl;

	delete spriteSourceCircle;
}
