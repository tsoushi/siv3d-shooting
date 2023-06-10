#include "Stages.h"
#include "../Unit/TestUnit.h"

void Stage1_1::Init() {
	gm->em.Add(new TestUnit());
}

void Stage1_1::Update() {
	if (KeyP.pressed()) gm->em.Add(new TestUnit());
}

void Stage1_1::Draw() const {

}
