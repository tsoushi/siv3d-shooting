#pragma once
#include <Siv3D.hpp>
#include "../GameCommon.h"

/// @brief が継承する
class IFEntity {
public:
	virtual void Update() = 0;
	virtual void Draw() const = 0;

	virtual RectF GetBody() = 0;
	virtual Region GetRegion() = 0;
	virtual bool IsActive() = 0;
};
