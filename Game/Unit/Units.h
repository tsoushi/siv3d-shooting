#pragma once
#include "../Interface/IFUnit.h"
#include "../GameManager.h"
#include "../Accesory/EntityDrawer.h"

/// @brief 機体テンプレートクラス。
class UnitTemplate : public IFUnit {
protected:
	GameManager* gm;
	EntityDrawer drawer;
	Vec2 pos;
	Vec2 velocity{ 0, 0 };
	double maxSpeed = 0;
	Vec2 accel{ 0, 0 };
	Region region;
	int32 hp;
	int32 score = 0;
public:
	virtual void SetGameManager(GameManager* gameManager);

	virtual void Update() override;
	virtual void Draw() const override = 0;
	virtual void Destroy() override;

	virtual void Move() = 0;

	virtual RectF GetBody() const override;
	virtual Region GetRegion() const override;
	virtual bool IsActive() const override;
	virtual void Damaged(int32 amount) override;
};

class Player : public UnitTemplate {
private:
	Timer bulletInterval{ 0.1s, StartImmediately::Yes };
public:
	Player(Vec2 pos);

	void Move() override;
	void Draw() const override;

	bool IsActive() const override;
};

class EnemyTest : public UnitTemplate {
private:
public:
	EnemyTest(Vec2 pos);

	void Move() override;
	void Draw() const override;

	void Damaged(int32 amount) override;
};
