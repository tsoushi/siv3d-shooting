#include "Units.h"
#include "../Bullet/Bullets.h"

Player::Player(Vec2 pos) {
	this->pos = pos;
	hp = 10;
	region = Region::Player;
	maxSpeed = 300;
}

void Player::Move() {
	accel = { 0, 0 };
	int32 speed = 1000;

	if (KeyW.pressed()) accel.y = -speed;
	if (KeyS.pressed()) accel.y = speed;
	if (KeyA.pressed()) accel.x = -speed;
	if (KeyD.pressed()) accel.x = speed;

	if (accel.length() == 0) accel = -10 * velocity;

	if (bulletInterval.reachedZero() && KeySpace.pressed()) {
		gm->em.Add(new PlayerBullet(pos, 0.4 * Math::Pi));
		gm->em.Add(new PlayerBullet(pos, 0.45 * Math::Pi));
		gm->em.Add(new PlayerBullet(pos, 0.5 * Math::Pi));
		gm->em.Add(new PlayerBullet(pos, 0.55 * Math::Pi));
		gm->em.Add(new PlayerBullet(pos, 0.6 * Math::Pi));
		bulletInterval.restart();
	}
}

void Player::Draw() const {
	Circle{ Arg::center(pos), 10 }.draw(Palette::Lightblue);
}

bool Player::IsActive() const {
	return true;
}
