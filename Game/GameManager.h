#pragma once
#include "EntityManager.h"
#include "StageManager.h"

/// @brief EntityManager, StageManagerを保持し、ゲームの進行を管理する。
class GameManager {
private:
	RenderTexture entityRenderTexture{ 640, 720 };
	Vec2 entityRenderPos{ 128, 0 };

	const Font scoreFont{ 56 };
	int32 score = 0;
public:
	GameManager();

	void Update();
	void Draw() const;

	/// @brief エンティティ描画領域を取得する
	/// @return 描画領域
	RectF GetEntityRenderArea() const;

	/// @brief エンティティの生存エリア範囲内かどうか
	/// @param pos チェック対象の座標
	/// @return 範囲内ならtrue
	bool IsInAliveArea(Vec2 pos) const;

	/// @brief スコアを加算する
	/// @param amount 加算量
	void IncScore(int32 amount);

	EntityManager em;
	StageManager sm;
};
