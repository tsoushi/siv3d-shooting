#pragma once
#include "../Interface/IFUnit.h"
#include "../EntityManager.h"

class TestUnit : public IFUnit {
private:
	Vec2 pos;
	EntityManager* entityManager;
public:
	TestUnit(EntityManager* entityManager);

	void Update() override;
	void Draw() const override;

	RectF GetBody() const override;
	Region GetRegion() const override;
	bool IsActive() const override;
	void Damaged(int32 amount) override;
};
