﻿#include "EntityManager.h"

void EntityManager::AddEntity(Entity* entity) {
	if (Unit* unit = dynamic_cast<Unit*>(entity)) {
		if (unit->region == EntityRegion::player) AddPlayerUnit(unit);
		if (unit->region == EntityRegion::enemy) AddEnemyUnit(unit);
	}
	else if (Bullet* bullet = dynamic_cast<Bullet*>(entity)) {
		if (bullet->region == EntityRegion::player) AddPlayerBullet(bullet);
		if (bullet->region == EntityRegion::enemy) AddEnemyBullet(bullet);
	}
}

void EntityManager::AddPlayerUnit(Unit *unit) {
	playerUnitsTmp << unit;
}

void EntityManager::AddEnemyUnit(Unit* unit) {
	enemyUnitsTmp << unit;
}

void EntityManager::AddPlayerBullet(Bullet* bullet) {
	playerBulletsTmp << bullet;
}

void EntityManager::AddEnemyBullet(Bullet* bullet) {
	enemyBulletsTmp << bullet;
}



void EntityManager::Update() {
	/* エンティティ追加予定の配列をマージ */
	playerUnits.insert(playerUnits.end(), playerUnitsTmp.begin(), playerUnitsTmp.end());
	enemyUnits.insert(enemyUnits.end(), enemyUnitsTmp.begin(), enemyUnitsTmp.end());
	playerBullets.insert(playerBullets.end(), playerBulletsTmp.begin(), playerBulletsTmp.end());
	enemyBullets.insert(enemyBullets.end(), enemyBulletsTmp.begin(), enemyBulletsTmp.end());
	playerUnitsTmp.clear();
	enemyUnitsTmp.clear();
	playerBulletsTmp.clear();
	enemyBulletsTmp.clear();

	uint64 debugTime = Time::GetMicrosec();
	// プレイヤーユニット
	for (auto unit = playerUnits.begin(); unit != playerUnits.end();) {
		(*unit)->Update();
		if ((*unit)->IsRemoved()) {
			delete *unit;
			unit = playerUnits.erase(unit);
			continue;
		}
		unit++;
	}

	debug.updatePlayerUnitTime = Time::GetMicrosec() - debugTime;
	debugTime = Time::GetMicrosec();

	// 敵ユニット
	for (auto unit = enemyUnits.begin(); unit != enemyUnits.end();) {
		(*unit)->Update();
		if ((*unit)->IsRemoved()) {
			delete* unit;
			unit = enemyUnits.erase(unit);
			continue;
		}
		unit++;
	}

	debug.updateEnemyUnitTime = Time::GetMicrosec() - debugTime;
	debugTime = Time::GetMicrosec();

	// プレイヤー弾
	for (auto bullet = playerBullets.begin(); bullet != playerBullets.end();) {
		(*bullet)->Update();
		if ((*bullet)->IsRemoved()) {
			delete* bullet;
			bullet = playerBullets.erase(bullet);
			continue;
		}
		// 敵ユニットとの当たり判定
		for (auto enemyUnit = enemyUnits.begin(); enemyUnit != enemyUnits.end(); enemyUnit++) {
			if ((*bullet)->IsInCollision((*enemyUnit)->GetDamageableBody())) {
				(*bullet)->ExecuteAttack(**enemyUnit);
			}
		}
		bullet++;
	}
	debug.updatePlayerBulletTime = Time::GetMicrosec() - debugTime;
	debugTime = Time::GetMicrosec();

	// 敵弾
	for (auto bullet = enemyBullets.begin(); bullet != enemyBullets.end();) {
		(*bullet)->Update();
		if ((*bullet)->IsRemoved()) {
			delete* bullet;
			bullet = enemyBullets.erase(bullet);
			continue;
		}
		// プレイヤーユニットとの当たり判定
		for (auto playerUnit = playerUnits.begin(); playerUnit != playerUnits.end(); playerUnit++) {
			if ((*bullet)->IsInCollision((*playerUnit)->GetDamageableBody())) {
				(*bullet)->ExecuteAttack(**playerUnit);
			}
		}
		bullet++;
	}

	debug.updateEnemyBulletTime = Time::GetMicrosec() - debugTime;
}


void EntityManager::Draw() {
	auto debugTime = Time::GetMicrosec();

	// プレイヤーユニット
	for (auto unit = playerUnits.begin(); unit != playerUnits.end(); unit++) {
		(*unit)->Draw();
	}

	debug.drawPlayerUnitTime = Time::GetMicrosec() - debugTime;
	debugTime = Time::GetMicrosec();

	// 敵ユニット
	for (auto unit = enemyUnits.begin(); unit != enemyUnits.end(); unit++) {
		(*unit)->Draw();
	}

	debug.drawEnemyUnitTime = Time::GetMicrosec() - debugTime;
	debugTime = Time::GetMicrosec();

	// プレイヤー弾
	for (auto bullet = playerBullets.begin(); bullet != playerBullets.end(); bullet++) {
		(*bullet)->Draw();
	}

	debug.drawPlayerBulletTime = Time::GetMicrosec() - debugTime;
	debugTime = Time::GetMicrosec();

	// 敵弾
	for (auto bullet = enemyBullets.begin(); bullet != enemyBullets.end(); bullet++) {
		(*bullet)->Draw();
	}

	debug.drawEnemyBulletTime = Time::GetMicrosec() - debugTime;

}
