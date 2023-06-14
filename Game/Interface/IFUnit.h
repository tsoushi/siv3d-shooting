#pragma once
#include "../GameCommon.h"

class GameManager;

/// @brief 機体
class IFUnit {
public:
	virtual ~IFUnit() {};

	virtual void SetGameManager(GameManager* gameManager) = 0;

	virtual void Update() = 0;
	virtual void Draw() const = 0;
	virtual void Destroy() = 0;

	/// @brief 当たり判定の範囲を取得する
	/// @return 当たり判定の範囲
	virtual RectF GetBody() const = 0;

	/// @brief 所属
	/// @return 所属
	virtual Region GetRegion() const = 0;

	/// @brief オブジェクトがアクティブか
	virtual bool IsActive() const = 0;

	/// @brief ダメージを与える
	/// @param amount 素ダメージ量（攻撃力）
	virtual void Damaged(int32 amount) = 0;
};
