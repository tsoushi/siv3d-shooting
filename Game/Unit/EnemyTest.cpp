#include "Units.h"

EnemyTest::EnemyTest(Vec2 pos) {
	this->pos = pos;
	region = Region::Enemy;
	hp = 3;
	velocity.y = 200;

	damagedTimer.setRemaining(0s);
	damagedTimer.start();
}

void EnemyTest::Move() {
	velocity.x = Math::Sin(Math::Pi*2*((int)(Scene::Time()*100) % 100)/100) * 200;
}

void EnemyTest::Draw() const {
	RectF{ Arg::center(pos), 20, 20 }.draw(damagedTimer.reachedZero() ? Palette::Purple : Palette::Red);
}

void EnemyTest::Damaged(int32 amount) {
	hp -= amount;
	damagedTimer.restart();
}
