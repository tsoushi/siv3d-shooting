#pragma once
#include "../Interface/IFUnit.h"
#include "../GameManager.h"

/// @brief 機体テンプレートクラス。
class UnitTemplate : public IFUnit {
protected:
	GameManager* gm;
	Vec2 pos;
	Vec2 velocity;
	Region region;
	int32 hp;
public:
	virtual void SetGameManager(GameManager* gameManager);

	virtual void Update() override;
	virtual void Draw() const = 0;

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
	Timer damagedTimer{ 0.02s };
public:
	EnemyTest(Vec2 pos);

	void Move() override;
	void Draw() const override;

	void Damaged(int32 amount) override;
};
