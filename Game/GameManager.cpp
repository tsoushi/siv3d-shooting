#include "GameManager.h"
#include "Unit/Units.h"

GameManager::GameManager()
	: sm(this), em(this)
{
	auto area = GetEntityRenderArea();
	em.Add(new Player(Vec2{ area.size.x / 2, area.size.y * 0.8 }));
}

void GameManager::Update() {
	em.Update();
	sm.Update();
}

void GameManager::Draw() const {
	{
		ScopedRenderTarget2D target{ entityRenderTexture.clear(Palette::Black) };
		em.Draw();
	}
	entityRenderTexture.draw(entityRenderPos);
	RectF{ entityRenderPos, entityRenderTexture.size() }.drawFrame(1);

	em.DebugDraw();
	sm.Draw();

	Vec2 scoreDrawPos{ Scene::Width() * 0.80, Scene::Height() * 0.15 };
	scoreFont(U"{:0>10}"_fmt(score)).drawAt(scoreDrawPos);// Scene::Width() * 0.65, Scene::Height() * 0.1);
}

RectF GameManager::GetEntityRenderArea() const {
	return RectF{ entityRenderPos, entityRenderTexture.size() };
}

bool GameManager::IsInAliveArea(Vec2 pos) const {
	RectF area = GetEntityRenderArea();
	return (
		pos.x > area.size.x * -0.2 &&
		pos.x < area.size.x * 1.2 &&
		pos.y > area.size.y * -0.3 &&
		pos.y < area.size.y * 1.3
	);
}

void GameManager::IncScore(int32 amount) {
	score += amount;
}
