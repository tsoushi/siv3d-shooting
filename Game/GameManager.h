#pragma once
#include "EntityManager.h"
#include "StageManager.h"

/// @brief EntityManager, StageManagerを保持し、ゲームの進行を管理する。
class GameManager {
public:
	GameManager();

	void Update();
	void Draw() const;

	EntityManager em;
	StageManager sm;
};
