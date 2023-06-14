#include "Bullets.h"

PlayerBullet::PlayerBullet(Vec2 pos, double direction) {
	this->pos = pos;
	this->direction = direction;
	region = Region::Player;
	velocity.x = Math::Cos(direction) * 500;
	velocity.y = -Math::Sin(direction) * 500;
	maxSpeed = 500;

	hp = 1;
	attack = 1;
}

void PlayerBullet::Move() {

}

void PlayerBullet::Draw() const {
	Circle{ pos, 5 }.draw(Palette::Yellow);
}

void PlayerBullet::Attack(IFUnit* target) {
	BulletTemplate::Attack(target);
}
