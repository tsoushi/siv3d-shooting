#include "Bullets.h"

void BulletTemplate::SetGameManager(GameManager* gameManager) {
	gm = gameManager;
}

void BulletTemplate::Update() {
	Move();
	body.Update();
}

void BulletTemplate::Draw() const {
	Circle{ body.pos, 10 }.draw();
}

RectF BulletTemplate::GetBody() const {
	return RectF{ Arg::center(body.pos), Vec2{ 10, 10 } };
}

Region BulletTemplate::GetRegion() const {
	return region;
}

bool BulletTemplate::IsActive() const {
	return hp > 0 && gm->IsInAliveArea(body.pos);
}

void BulletTemplate::Attack(IFUnit* target) {
	if (hp > 0) {
		target->Damaged(attack);
		hp--;
	}
}
