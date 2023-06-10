#include "TestUnit.h"
#include "../Bullet/TestBullet.h"

TestUnit::TestUnit() {}

void TestUnit::SetGameManager(GameManager* gameManager) {
	gm = gameManager;
}

void TestUnit::Update() {
	int32 speed = 5;
	if (KeyW.pressed()) pos.y -= speed;
	if (KeyS.pressed()) pos.y += speed;
	if (KeyD.pressed()) pos.x += speed;
	if (KeyA.pressed()) pos.x -= speed;

	if (KeySpace.pressed()) gm->em.Add(new TestBullet(pos));
}

void TestUnit::Draw() const {
	Circle{ pos, 10 }.draw();
}

RectF TestUnit::GetBody() const {
	return RectF{ Arg::center(pos), Vec2{ 10, 10 } };
}

Region TestUnit::GetRegion() const {
	return Region::Player;
}

bool TestUnit::IsActive() const {
	return true;
}

void TestUnit::Damaged(int32 amount) {

}
