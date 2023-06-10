#pragma once
#include "../Interface/IFUnit.h"
#include "../GameManager.h"

class TestUnit : public IFUnit {
private:
	Vec2 pos;
	GameManager* gm;
public:
	TestUnit();

	void SetGameManager(GameManager* gameManager);

	void Update() override;
	void Draw() const override;

	RectF GetBody() const override;
	Region GetRegion() const override;
	bool IsActive() const override;
	void Damaged(int32 amount) override;
};
