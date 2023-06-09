#pragma once
#include "../GameCommon.h"

class IFUnit;

/// @brief 弾丸
class IFBullet {
public:
	virtual ~IFBullet() {};

	virtual void Update() = 0;
	virtual void Draw() const = 0;

	/// @brief 当たり判定の範囲を取得する
	/// @return 当たり判定の範囲
	virtual RectF GetBody() const = 0;

	/// @brief 所属
	/// @return 所属
	virtual Region GetRegion() const = 0;

	/// @brief オブジェクトがアクティブか
	virtual bool IsActive() const = 0;

	/// @brief unitに対して攻撃を行う
	/// @param unit 攻撃対象のunit
	virtual void Attack(IFUnit* unit) = 0;
};
