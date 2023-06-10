#include "EntityManager.h"

EntityManager::EntityManager(GameManager* gameManager)
	: gm(gameManager) {}

void EntityManager::Update() {
	// 新規追加のエンティティをマージ
	playerUnits.insert(playerUnits.end(), prePlayerUnits.begin(), prePlayerUnits.end());
	enemyUnits.insert(enemyUnits.end(), preEnemyUnits.begin(), preEnemyUnits.end());
	playerBullets.insert(playerBullets.end(), prePlayerBullets.begin(), prePlayerBullets.end());
	enemyBullets.insert(enemyBullets.end(), preEnemyBullets.begin(), preEnemyBullets.end());
	prePlayerUnits.clear();
	preEnemyUnits.clear();
	prePlayerBullets.clear();
	preEnemyBullets.clear();

	// 機体の挙動更新
	for (auto e : playerUnits) {
		if (!e->IsActive()) continue;
		e->Update();
	}
	for (auto e : enemyUnits) {
		if (!e->IsActive()) continue;
		e->Update();
	}
	
	// 弾丸の挙動更新
	for (auto e : playerBullets) {
		if (!e->IsActive()) continue;
		e->Update();

		for (auto t : enemyUnits) {
			if (!t->IsActive()) continue;
			// 当たり判定
			if (e->GetBody().intersects(t->GetBody())) {
				// 衝突していた場合
				e->Attack(t);
			}
		}
	}
	for (auto e : enemyBullets) {
		if (!e->IsActive()) continue;
		e->Update();

		for (auto t : playerUnits) {
			if (!t->IsActive()) continue;
			// 当たり判定
			if (e->GetBody().intersects(t->GetBody())) {
				// 衝突していた場合
				e->Attack(t);
			}
		}
	}

	// 非アクティブなエンティティを削除
	for (auto e = playerUnits.begin(); e != playerUnits.end();) {
		if (!(*e)->IsActive()) {
			delete *e;
			e = playerUnits.erase(e);
			continue;
		}
		e++;
	}
	for (auto e = enemyUnits.begin(); e != enemyUnits.end();) {
		if (!(*e)->IsActive()) {
			delete* e;
			e = enemyUnits.erase(e);
			continue;
		}
		e++;
	}
	for (auto e = playerBullets.begin(); e != playerBullets.end();) {
		if (!(*e)->IsActive()) {
			delete* e;
			e = playerBullets.erase(e);
			continue;
		}
		e++;
	}
	for (auto e = enemyBullets.begin(); e != enemyBullets.end();) {
		if (!(*e)->IsActive()) {
			delete* e;
			e = enemyBullets.erase(e);
			continue;
		}
		e++;
	}
}

void EntityManager::Draw() const {
	// 機体の挙動更新
	for (auto e : playerUnits) {
		if (!e->IsActive()) continue;
		e->Draw();
	}
	for (auto e : enemyUnits) {
		if (!e->IsActive()) continue;
		e->Draw();
	}

	// 弾丸の挙動更新
	for (auto e : playerBullets) {
		if (!e->IsActive()) continue;
		e->Draw();
	}
	for (auto e : enemyBullets) {
		if (!e->IsActive()) continue;
		e->Draw();
	}

}

void EntityManager::DebugDraw() const {
	static Font font{ 10 };
	font(playerUnits.size(), U" : ", enemyBullets.size()).draw(Vec2{ 0, 0 });
}

void EntityManager::Add(IFUnit* unit) {
	unit->SetGameManager(gm);

	switch (unit->GetRegion()) {
	case Region::Player:
		prePlayerUnits << unit;
		break;
	case Region::Enemy:
		preEnemyUnits << unit;
		break;
	}
}

void EntityManager::Add(IFBullet* bullet) {
	bullet->SetGameManager(gm);

	switch (bullet->GetRegion()) {
	case Region::Player:
		prePlayerBullets << bullet;
		break;
	case Region::Enemy:
		preEnemyBullets << bullet;
		break;
	}
}
