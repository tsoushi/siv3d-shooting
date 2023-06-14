#pragma once

/// @brief 速度、加速度による運動計算行う
class KinematicBody {
public:
	Vec2 pos{ 0, 0 };
	Vec2 velocity{ 0, 0 };
	Vec2 accel{ 0, 0 };
	double maxSpeed = 1000;

	double angle = 0;

	/// @brief 経過時間を元に位置、速度を計算する
	/// @param deltaTime 前回Updateからの経過時間
	void Update(double deltaTime = Scene::DeltaTime());
	
	void SetVelocityByAngle(double length);
	void SetVelocityByAngle(double length, double angle);
};
