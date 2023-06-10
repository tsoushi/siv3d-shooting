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

	if (KeySpace.pressed()) gm->em.Add(new PlayerBullet(pos, 0.5 * Math::Pi));
}

void Player::Draw() const {
	Circle{ Arg::center(pos), 10 }.draw(Palette::Lightblue);
}

bool Player::IsActive() const {
	return true;
}
