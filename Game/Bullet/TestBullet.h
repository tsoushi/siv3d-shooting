#pragma once
#include "../Interface/IFBullet.h"
#include "../GameManager.h"

class TestBullet : public IFBullet {
private:
	GameManager* gm;

	Vec2 pos;
	bool hit;
public:
	TestBullet(Vec2 pos);

	void SetGameManager(GameManager* gameManager);

	void Update() override;
	void Draw() const override;

	RectF GetBody() const override;
	Region GetRegion() const override;
	bool IsActive() const override;
	void Attack(IFUnit* unit) override;
};
