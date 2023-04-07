#pragma once
#include "CScene.h"
class CScene_JobChoice :
	public CScene
{
public:
	CScene_JobChoice();
	~CScene_JobChoice();

	// Inherited via CScene
	virtual void Enter() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Exit() override;
};

