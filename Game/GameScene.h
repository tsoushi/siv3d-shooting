#pragma once
#include "../Common.h"
#include "GameManager.h"

class GameScene : public App::Scene {
private:
	GameManager gameManager;
public:
	GameScene(const InitData& init);
	void update() override;
	void draw() const override;
};
