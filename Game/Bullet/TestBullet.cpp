#include "TestBullet.h"

TestBullet::TestBullet(Vec2 pos)
	: pos(pos) {}

void TestBullet::Update() {
	int32 speed = 1;
	if (KeyW.pressed()) pos.y -= speed;
	if (KeyS.pressed()) pos.y += speed;
	if (KeyD.pressed()) pos.x += speed;
	if (KeyA.pressed()) pos.x -= speed;
	hit = false;
}

void TestBullet::Draw() const {
	Circle{ pos, 10 }.draw(hit ? Palette::Red : Palette::Yellow);
}

RectF TestBullet::GetBody() const {
	return RectF{ Arg::center(pos), Vec2{ 10, 10 } };
}

Region TestBullet::GetRegion() const {
	return Region::Enemy;
}

bool TestBullet::IsActive() const {
	return true;
}

void TestBullet::Attack(IFUnit* unit) {
	hit = true;
}
