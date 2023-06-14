#include "Bullets.h"

PlayerBullet::PlayerBullet(Vec2 pos, double direction) {
	region = Region::Player;
	body.pos = pos;
	body.angle = direction;
	body.SetVelocityByAngle(500);
	body.maxSpeed = 500;

	hp = 1;
	attack = 1;
}

void PlayerBullet::Move() {

}

void PlayerBullet::Draw() const {
	Circle{ body.pos, 5 }.draw(Palette::Yellow);
}

void PlayerBullet::Attack(IFUnit* target) {
	BulletTemplate::Attack(target);
}
