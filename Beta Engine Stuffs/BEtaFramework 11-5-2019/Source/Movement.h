#pragma once

#include <Component.h>

class Movement : public Beta::Component
{
public:
	Movement();

	void Initialize() override;

private:
	void OnMovementInput(const Beta::Event& event)

	//extra componet stuff - DO NOT REMOVE
	COMPONENT_SUBCLASS_DECLARATION(Movement);
};