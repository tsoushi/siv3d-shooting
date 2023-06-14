#include "EntityDrawer.h"

EntityDrawer::EntityDrawer()
{
	damageEffectTimer.setRemaining(0s);
	damageEffectTimer.start();
}

void EntityDrawer::SetTexture(Texture texture) {
	this->texture = texture;
	size = texture.size();
}

void EntityDrawer::SetSize(Size newSize) {
	size = newSize;
}

void EntityDrawer::DrawAt(Vec2 pos) const {
	texture
		.resized(size)
		.drawAt(pos, damageEffectTimer.reachedZero() ? Palette::White : Palette::Red);
}

void EntityDrawer::StartDamageEffect() {
	damageEffectTimer.restart();
}
