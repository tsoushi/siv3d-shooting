#pragma once
#include "../Interface/IFBullet.h"
#include "../GameManager.h"

/// @brief 機体テンプレートクラス。
class BulletTemplate : public IFBullet {
protected:
	GameManager* gm;
	Vec2 pos;
	Vec2 velocity;
	Region region;
	int32 hp;
public:
	virtual void SetGameManager(GameManager* gameManager);

	virtual void Update() override;
	virtual void Draw() const;

	virtual void Move() = 0;

	virtual RectF GetBody() const override;
	virtual Region GetRegion() const override;
	virtual bool IsActive() const override;
	virtual void Attack(IFUnit* target) override;
};

class PlayerBullet : public BulletTemplate {
private:
	double direction;
public:
	PlayerBullet(Vec2 pos, double direction);

	void Move() override;
	void Draw() const override;

	void Attack(IFUnit* target) override;
};
