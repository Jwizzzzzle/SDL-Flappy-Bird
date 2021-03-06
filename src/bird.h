#pragma once

#include "entity.h"

class Bird : public Entity
{
private:
	float delta = 0.0f;
public:
	bool isSpace = false;
public:
	using Entity::Entity;
	void start() override;
	void update() override;
};