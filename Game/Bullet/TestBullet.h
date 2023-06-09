#pragma once
#include "../Interface/IFBullet.h"

class TestBullet : public IFBullet {
private:
	Vec2 pos;
	bool hit;
public:
	TestBullet(Vec2 pos);

	void Update() override;
	void Draw() const override;

	RectF GetBody() const override;
	Region GetRegion() const override;
	bool IsActive() const override;
	void Attack(IFUnit* unit) override;
};
