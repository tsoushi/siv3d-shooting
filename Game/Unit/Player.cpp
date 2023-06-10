#include "Units.h"
#include "../Bullet/Bullets.h"

Player::Player(Vec2 pos) {
	this->pos = pos;
	hp = 10;
	region = Region::Player;
}

void Player::Move() {
	velocity = { 0, 0 };
	int32 speed = 200;

	if (KeyW.pressed()) velocity.y = -speed;
	if (KeyS.pressed()) velocity.y = speed;
	if (KeyA.pressed()) velocity.x = -speed;
	if (KeyD.pressed()) velocity.x = speed;

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
