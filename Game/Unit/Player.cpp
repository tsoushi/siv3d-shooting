#include "Units.h"
#include "../Bullet/Bullets.h"

Player::Player(Vec2 pos) {
	body.pos = pos;
	hp = 10;
	region = Region::Player;
	body.maxSpeed = 300;
}

void Player::Move() {
	body.accel = { 0, 0 };
	int32 speed = 1000;

	if (KeyW.pressed()) body.accel.y = -speed;
	if (KeyS.pressed()) body.accel.y = speed;
	if (KeyA.pressed()) body.accel.x = -speed;
	if (KeyD.pressed()) body.accel.x = speed;

	if (body.accel.length() == 0) body.accel = -10 * body.velocity;

	if (bulletInterval.reachedZero() && KeySpace.pressed()) {
		gm->em.Add(new PlayerBullet(body.pos, 0.4 * Math::Pi));
		gm->em.Add(new PlayerBullet(body.pos, 0.45 * Math::Pi));
		gm->em.Add(new PlayerBullet(body.pos, 0.5 * Math::Pi));
		gm->em.Add(new PlayerBullet(body.pos, 0.55 * Math::Pi));
		gm->em.Add(new PlayerBullet(body.pos, 0.6 * Math::Pi));
		bulletInterval.restart();
	}
}

void Player::Draw() const {
	Circle{ Arg::center(body.pos), 10 }.draw(Palette::Lightblue);
}

bool Player::IsActive() const {
	return true;
}
