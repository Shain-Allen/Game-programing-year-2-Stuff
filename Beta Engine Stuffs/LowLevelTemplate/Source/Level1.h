#pragma once

#include <BetaObject.h>


class level1 : public Beta::BetaObject
{
public:
	level1();
	void Initialize() override;
	void Update(float dt) override;
	void Shutdown() override;
};