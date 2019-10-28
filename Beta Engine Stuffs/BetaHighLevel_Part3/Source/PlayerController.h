#pragma once

#include <Component.h>

class PlayerController : public Beta::Component
{
public:
	// Constructor
	PlayerController();

	// Game loop functions
	void Initialize() override;
	void Update(float dt) override;

	//serialization
	//Note: Serialize - write to file, deserialize - read from file
	void Serialize(Beta::FileStream& stream) const override;
	void Deserialize(Beta::FileStream& stream) override;

private:
	// Component dependencies
	Beta::Transform* transform;

	//properties
	float speed;

	// Extra engine stuff - DO NOT REMOVE
	COMPONENT_SUBCLASS_DECLARATION(PlayerController)
};