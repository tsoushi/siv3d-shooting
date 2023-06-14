#include "Units.h"

void UnitTemplate::SetGameManager(GameManager* gameManager) {
	gm = gameManager;
}

void UnitTemplate::Update() {
	Move();
	pos += velocity * Scene::DeltaTime();
}

void UnitTemplate::Draw() const {
	Circle{ pos, 10 }.draw();
}

void UnitTemplate::Destroy() {
	gm->IncScore(score);
}

RectF UnitTemplate::GetBody() const {
	return RectF{ Arg::center(pos), Vec2{ 10, 10 } };
}

Region UnitTemplate::GetRegion() const {
	return region;
}

bool UnitTemplate::IsActive() const {
	return hp > 0 && gm->IsInAliveArea(pos);
}

void UnitTemplate::Damaged(int32 amount) {
	hp -= amount;
}
