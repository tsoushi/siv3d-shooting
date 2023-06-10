#include "Bullets.h"

void BulletTemplate::SetGameManager(GameManager* gameManager) {
	gm = gameManager;
}

void BulletTemplate::Update() {
	Move();
	pos += velocity * Scene::DeltaTime();
}

void BulletTemplate::Draw() const {
	Circle{ pos, 10 }.draw();
}

RectF BulletTemplate::GetBody() const {
	return RectF{ Arg::center(pos), Vec2{ 10, 10 } };
}

Region BulletTemplate::GetRegion() const {
	return region;
}

bool BulletTemplate::IsActive() const {
	return hp > 0 && gm->IsInAliveArea(pos);
}

void BulletTemplate::Attack(IFUnit* target) {
}
