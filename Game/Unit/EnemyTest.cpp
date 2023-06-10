#include "Units.h"

EnemyTest::EnemyTest(Vec2 pos) {
	this->pos = pos;
	region = Region::Enemy;
	hp = 3;
	velocity.y = 200;
}

void EnemyTest::Move() {

}

void EnemyTest::Draw() const {
	RectF{ Arg::center(pos), 20, 20 }.draw(Palette::Purple);
}
