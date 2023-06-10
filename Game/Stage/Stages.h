#pragma once
#include "IFStage.h"
#include "../GameManager.h"

class StageTemplate : public IFStage {
protected:
	GameManager* gm;
public:
	StageTemplate(GameManager* gameManager);

	virtual void Init() override;
};

class Stage1_1 : public StageTemplate {
private:
public:
	using StageTemplate::StageTemplate;

	void Init() override;
	void Update() override;
	void Draw() const override;
};
