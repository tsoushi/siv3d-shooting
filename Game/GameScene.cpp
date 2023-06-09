#include "GameScene.h"
#include "Unit/TestUnit.h"

GameScene::GameScene(const InitData& init)
	: IScene{ init }
{
	entityManager.Add(new TestUnit(&entityManager));
}

void GameScene::update() {
	if (KeyP.pressed()) entityManager.Add(new TestUnit(&entityManager));
	entityManager.Update();
}

void GameScene::draw() const {
	entityManager.Draw();
	entityManager.DebugDraw();
}
