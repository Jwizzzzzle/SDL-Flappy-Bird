#pragma once

#include "entity.h"

class BG : public Entity
{
public:
	using Entity::Entity;
	void start() override;
	void update() override;
};