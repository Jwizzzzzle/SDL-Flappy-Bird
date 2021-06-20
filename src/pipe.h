#pragma once

#include "entity.h"
#include "bird.h"

class Pipe : public Entity
{
private:
	Bird* player;
public:
	using Entity::Entity;
	void start() override;
	void update() override;
	bool Collision();
	void setBird(Bird* bird);
};