#pragma once

#include "entity.h"

class Pipe : public Entity
{
public:
	using Entity::Entity;
	void start() override;
	void update() override;
};