#pragma once

#include "entity.h"

class Bird : public Entity
{
public:
	using Entity::Entity;
	void start() override;
	void update() override;
};