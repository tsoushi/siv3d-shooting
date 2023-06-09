#pragma once
#include "Interface/IFUnit.h"
#include "Interface/IFBullet.h"

class EntityManager {
private:
	/// プレイヤーの機体
	Array<IFUnit*> playerUnits;
	/// 敵の機体
	Array<IFUnit*> enemyUnits;
	/// プレイヤーの弾丸
	Array<IFBullet*> playerBullets;
	/// 敵の弾丸
	Array<IFBullet*> enemyBullets;

	/// 追加予定のプレイヤーの機体
	Array<IFUnit*> prePlayerUnits;
	/// 追加予定の敵の機体
	Array<IFUnit*> preEnemyUnits;
	/// 追加予定のプレイヤーの弾丸
	Array<IFBullet*> prePlayerBullets;
	/// 追加予定の敵の弾丸
	Array<IFBullet*> preEnemyBullets;
public:
	void Update();
	void Draw() const;
	void DebugDraw() const;

	/// @brief 機体をゲームに追加する
	/// @param unit 追加する機体
	void Add(IFUnit* unit);
	/// @brief 弾丸をゲームに追加する
	/// @param bullet 追加する弾丸
	void Add(IFBullet* bullet);
};
