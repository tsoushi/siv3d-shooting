#pragma once
#include "Stage/IFStage.h"

class GameManager;

/// @brief ステージの更新、描画、遷移を管理する
class StageManager {
private:
	GameManager* gm;
	IFStage* currentStage = nullptr;
	IFStage* nextStage = nullptr;
public:
	StageManager(GameManager* gameManager);
	void Update();
	void Draw() const;

	/// @brief ステージを遷移する。実際の遷移は次回Update呼び出し時に行われる。
	/// @param stage 次のステージ
	void ChangeStage(IFStage* stage);
};
