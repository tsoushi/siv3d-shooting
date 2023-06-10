#include "StageManager.h"
#include "Stage/Stages.h"

StageManager::StageManager(GameManager* gameManager)
	: gm(gameManager)
{
	nextStage = new Stage1_1(gm);
}

void StageManager::Update() {
	// ステージ変更反映
	if (nextStage != nullptr) {
		if (currentStage != nullptr) delete currentStage;
		currentStage = nextStage;
		nextStage = nullptr;
		currentStage->Init();
	}

	currentStage->Update();
}

void StageManager::Draw() const {
	if (currentStage != nullptr) currentStage->Draw();
}

void StageManager::ChangeStage(IFStage* stage) {
	nextStage = stage;
}
