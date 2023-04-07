#pragma once
#include "CScene.h"
class CScene_Exit :
	public CScene
{
public:
	CScene_Exit();
	~CScene_Exit();

	// Inherited via CScene
	virtual void Enter() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Exit() override;
};

