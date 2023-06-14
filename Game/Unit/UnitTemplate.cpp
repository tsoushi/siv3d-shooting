#include "Units.h"

void UnitTemplate::SetGameManager(GameManager* gameManager) {
	gm = gameManager;
}

void UnitTemplate::Update() {
	Move();
	body.Update();
}

void UnitTemplate::Draw() const {
	Circle{ body.pos, 10 }.draw();
}

void UnitTemplate::Destroy() {
}

RectF UnitTemplate::GetBody() const {
	return RectF{ Arg::center(body.pos), Vec2{ 10, 10 } };
}

Region UnitTemplate::GetRegion() const {
	return region;
}

bool UnitTemplate::IsActive() const {
	return hp > 0 && gm->IsInAliveArea(body.pos);
}

void UnitTemplate::Damaged(int32 amount) {
	if (hp > 0) {
		drawer.StartDamageEffect();
		hp -= amount;
		if (hp == 0) gm->IncScore(score);
	}
}
