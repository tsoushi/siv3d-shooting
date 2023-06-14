#include "Units.h"

EnemyTest::EnemyTest(Vec2 pos) {
	drawer.SetTexture(Texture{ U"resource/texture/test.png" });
	drawer.SetSize({ 16, 16 });
	this->pos = pos;
	region = Region::Enemy;
	hp = 3;
	velocity.y = 200;
	maxSpeed = 1000;
	score = 100;
}

void EnemyTest::Move() {
	velocity.x = Math::Sin(Math::Pi*2*((int)(Scene::Time()*100) % 100)/100) * 200;
}

void EnemyTest::Draw() const {
	drawer.DrawAt(pos);
}

void EnemyTest::Damaged(int32 amount) {
	UnitTemplate::Damaged(amount);
}
