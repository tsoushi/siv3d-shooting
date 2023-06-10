#include "GameManager.h"

GameManager::GameManager()
	: sm(this), em(this)
{

}

void GameManager::Update() {
	em.Update();
	sm.Update();
}

void GameManager::Draw() const {
	em.Draw();
	em.DebugDraw();
	sm.Draw();
}
