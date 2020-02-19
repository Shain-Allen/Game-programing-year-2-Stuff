//------------------------------------------------------------------------------
//
// File Name: Archetypes.cpp
// Author(s): Shain Allen
// Project: CS230Project2
// Course: wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "stdafx.h"
#include "Archetypes.h"
#include "GameObject.h"
#include "Transform.h"
#include "Sprite.h"
#include "RigidBody.h"
#include "TimedDeath.h"
#include "Animator.h"
#include "PlayerShip.h"
#include "MonkeyMovement.h"
#include "ColliderPoint.h"
#include "ColliderCircle.h"
#include "ColliderRectangle.h"
#include "Collider.h"
#include "ScreenWrap.h"
#include "ColorChange.h"
#include "SpriteTilemap.h"
#include "ColliderTilemap.h"

using namespace Beta;

GameObject* Archetypes::CreateShip(Beta::Mesh* mesh)
{
	GameObject* ship = new GameObject("Ship");

	Transform* transform = new Transform();
	transform->SetScale(Vector2D(0.5, 0.5));
	ship->AddComponent(transform);

	Sprite* sprite = new Sprite(mesh);
	ship->AddComponent(sprite);

	RigidBody* rigidBody = new RigidBody();
	ship->AddComponent(rigidBody);

	PlayerShip* playerShip = new PlayerShip();
	ship->AddComponent(playerShip);

	return ship;
}

GameObject* Archetypes::CreateBulletArchetype(Beta::Mesh* mesh)
{
	GameObject* bullet = new GameObject("Bullet");

	Transform* transform = new Transform();
	transform->SetScale(Vector2D(0.07f, 0.07f));
	bullet->AddComponent(transform);

	Sprite* sprite = new Sprite(mesh);
	bullet->AddComponent(sprite);

	RigidBody* rigidBody = new RigidBody();
	bullet->AddComponent(rigidBody);

	TimedDeath* timedDeath = new TimedDeath();
	bullet->AddComponent(timedDeath);

	return bullet;
}

GameObject* Archetypes::CreateMonkey(Beta::Mesh* mesh, SpriteSource* spriteSource, Animation* animation)
{
	GameObject* monkey = new GameObject("Monkey");

	Transform* transform = new Transform();
	transform->SetScale(Vector2D(1.0f, 1.0f));
	monkey->AddComponent(transform);

	Sprite* sprite = new Sprite(mesh, spriteSource);
	monkey->AddComponent(sprite);

	Animator* animator = new Animator();
	animator->AddAnimation(animation);
	monkey->AddComponent(animator);

	RigidBody* rigidBody = new RigidBody();
	monkey->AddComponent(rigidBody);

	MonkeyMovement* monkeyMovement = new MonkeyMovement();
	monkey->AddComponent(monkeyMovement);

	return monkey;
}

GameObject* Archetypes::CreatePoint(Beta::Mesh* mesh, SpriteSource* spriteSource)
{
	GameObject* point = new GameObject("Point");

	Transform* transform = new Transform();
	transform->SetScale(Vector2D(0.2f, 0.2f));
	point->AddComponent(transform);
	
	Sprite* sprite = new Sprite(mesh, spriteSource);
	point->AddComponent(sprite);

	RigidBody* rigidbody = new RigidBody();
	point->AddComponent(rigidbody);

	ColliderPoint* colliderPoint = new ColliderPoint();
	point->AddComponent(colliderPoint);

	ColorChange* colorChange = new ColorChange(Beta::Colors::Blue, Beta::Colors::Red);
	point->AddComponent(colorChange);
	
	ScreenWrap* screenWrap = new ScreenWrap();
	point->AddComponent(screenWrap);
	
	return point;
}

GameObject* Archetypes::CreateCircle(Beta::Mesh* mesh, SpriteSource* spriteSource)
{
	GameObject* Circle = new GameObject("Circle");

	Transform* transform = new Transform();
	transform->SetScale(Vector2D(1.0f, 1.0f));
	Circle->AddComponent(transform);

	Sprite* sprite = new Sprite(mesh, spriteSource);
	Circle->AddComponent(sprite);

	RigidBody* rigidbody = new RigidBody();
	Circle->AddComponent(rigidbody);

	ColliderCircle* colliderCircle = new ColliderCircle();
	Circle->AddComponent(colliderCircle);

	ColorChange* colorChange = new ColorChange(Colors::Yellow, Colors::Red);
	Circle->AddComponent(colorChange);

	ScreenWrap* screenWrap = new ScreenWrap();
	Circle->AddComponent(screenWrap);

	return Circle;
}

GameObject* Archetypes::CreateRectangle(Beta::Mesh* mesh)
{
	GameObject* rectangle = new GameObject("rectangle");

	Transform* transform = new Transform();
	transform->SetScale(Vector2D(2.5f, 1.0f));
	rectangle->AddComponent(transform);

	Sprite* sprite = new Sprite(mesh);
	rectangle->AddComponent(sprite);

	RigidBody* rigidbody = new RigidBody();
	rectangle->AddComponent(rigidbody);

	ColliderRectangle* colliderRectangle = new ColliderRectangle(transform->GetScale() / 2.0f);
	rectangle->AddComponent(colliderRectangle);

	ColorChange* colorChange = new ColorChange(Colors::Green, Colors::Red);
	rectangle->AddComponent(colorChange);

	ScreenWrap* screenWrap = new ScreenWrap();
	rectangle->AddComponent(screenWrap);

	return rectangle;
}

GameObject* Archetypes::CreateTilemapObject(Beta::Mesh* mesh, SpriteSource* spriteSource, Tilemap* map)
{
	GameObject* tilemap = new GameObject("Tilemap");

	Transform* transform = new Transform();
	transform->SetTranslation(Vector2D(-3.5f, 2.5f));
	tilemap->AddComponent(transform);

	SpriteTilemap* spriteTileMap = new SpriteTilemap(mesh, spriteSource, map);
	tilemap->AddComponent(spriteTileMap);

	/*ColliderTilemap* colliderTilemap = new ColliderTilemap();
	tilemap->AddComponent(colliderTilemap);*/

	return tilemap;
}
