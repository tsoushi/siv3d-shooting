#pragma once
#include "../Common.h"
#include "EntityManager.h"

class GameScene : public App::Scene {
private:
	EntityManager entityManager;
public:
	GameScene(const InitData& init);
	void update() override;
	void draw() const override;
};
