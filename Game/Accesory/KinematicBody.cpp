#include "KinematicBody.h"

void KinematicBody::Update(double deltaTime) {
	velocity += accel * deltaTime;
	if (velocity.length() > maxSpeed) velocity *= maxSpeed / velocity.length();
	pos += velocity * deltaTime;
}

void KinematicBody::SetVelocityByAngle(double length) {
	SetVelocityByAngle(length, angle);
}

void KinematicBody::SetVelocityByAngle(double length, double _angle) {
	velocity.x = Math::Cos(_angle) * length;
	velocity.y = -Math::Sin(_angle) * length;
}
