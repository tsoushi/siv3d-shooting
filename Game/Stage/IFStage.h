#pragma once

/// @brief inteface 各ステージはこれを実装する
class IFStage {
public:
	virtual ~IFStage() {};

	/// @brief ステージ遷移完了時に呼び出される。
	virtual void Init() = 0;
	/// @brief 更新処理。毎フレーム呼び出される。
	virtual void Update() = 0;
	/// @brief 描画処理。毎フレーム呼び出される。
	virtual void Draw() const = 0;
};
