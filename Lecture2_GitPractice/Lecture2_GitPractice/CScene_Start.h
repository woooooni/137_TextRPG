#pragma once
#include "CScene.h"
class CScene_Start :
	public CScene
{
public:
	explicit CScene_Start();
	~CScene_Start();

	// Inherited via CScene
	virtual void Enter() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Exit() override;
};

