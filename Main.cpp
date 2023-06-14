# include <Siv3D.hpp> // OpenSiv3D v0.6.6
#include "Common.h"
#include "Game/GameScene.h"

void Main()
{
	App manager;

	manager.add<GameScene>(U"Game");

	Window::SetFullscreen(true);
	Window::Resize(1280, 720);

	while (System::Update())
	{
		if (not manager.update()) {
			break;
		}
	}
}
