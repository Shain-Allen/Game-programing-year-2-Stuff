#include "stdafx.h"
#include "ScreenWrap.h"
#include "RigidBody.h"
#include "GameObject.h"
#include "Transform.h"
#include "RigidBody.h"

using namespace Beta;
using std::cout;
using std::endl;

// STUDENT CODE GOES HERE

ScreenWrap::ScreenWrap()
	: Component("ScreenWrap"), transform(nullptr), rigidBody(nullptr)
{
}

Component* ScreenWrap::Clone() const
{
	return new ScreenWrap(*this);
}

void ScreenWrap::Initialize()
{
	cout << "ScreenWrap" << endl;

	transform = static_cast<Transform*>(GetOwner()->GetComponent("Transform"));
	rigidBody = static_cast<RigidBody*>(GetOwner()->GetComponent("Rigidbody"));
}

void ScreenWrap::Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);

	GraphicsEngine* graphics = EngineGetModule(GraphicsEngine);

	BoundingRectangle worldsize = graphics->GetDefaultCamera().GetScreenWorldDimensions();

	if (transform->GetTranslation().x > worldsize.right + transform->GetScale().x)
	{
		transform->SetTranslationX(worldsize.left - transform->GetScale().x);
	}

	if (transform->GetTranslation().x < worldsize.left - transform->GetScale().x)
	{
		transform->SetTranslationX(worldsize.right + transform->GetScale().x);
	}

	if (transform->GetTranslation().y > worldsize.top + transform->GetScale().y)
	{
		transform->SetTranslationY(worldsize.bottom - transform->GetScale().y);
	}

	if (transform->GetTranslation().y < worldsize.bottom - transform->GetScale().y)
	{
		transform->SetTranslationY(worldsize.top + transform->GetScale().y);
	}
}
