#pragma once

#include <Component.h> // base class

class DestroyOnCollide : public Beta::Component
{
public:
	DestroyOnCollide();

	void Initialize() override;

private:
	void OnCollisionStarted(const Beta::Event& event);

	//extra componet stuff - DO NOT REMOVE
	COMPONENT_SUBCLASS_DECLARATION(DestroyOnCollide);
};