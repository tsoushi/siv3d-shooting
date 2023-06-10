#include "Stages.h"
#include "../Unit/Units.h"

void Stage1_1::Init() {
	interval.start();
}

void Stage1_1::Update() {
	if (interval.reachedZero()) {
		gm->em.Add(new EnemyTest(Vec2{ Random() * gm->GetEntityRenderArea().size.x, 50 }));
		interval.restart();
	}
}

void Stage1_1::Draw() const {

}
