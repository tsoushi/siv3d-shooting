#pragma once

/// @brief エンティティの描画に関する部品クラス
class EntityDrawer {
private:
	Texture texture;
	Size size;

	Timer damageEffectTimer{ 0.1s };
public:
	EntityDrawer();

	/// @brief 描画時に使用するテクスチャを設定する
	/// @param texture テクスチャ
	void SetTexture(Texture texture);

	/// @brief 描画時のサイズを指定する
	/// @param newSize 新しいサイズ
	void SetSize(Size newSize);

	/// @brief 描画する
	/// @param pos 描画位置
	void DrawAt(Vec2 pos) const;

	/// @brief ダメージエフェクトを開始する
	void StartDamageEffect();
};
