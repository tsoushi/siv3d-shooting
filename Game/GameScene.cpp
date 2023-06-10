#include "GameScene.h"

GameScene::GameScene(const InitData& init)
	: IScene{ init }
{
}

void GameScene::update() {
	gameManager.Update();
}

void GameScene::draw() const {
	gameManager.Draw();
}
