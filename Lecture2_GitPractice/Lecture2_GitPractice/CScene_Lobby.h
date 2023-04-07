#pragma once
#include "CScene.h"
class CScene_Lobby :
	public CScene
{
public:
	CScene_Lobby();
	~CScene_Lobby();

	// Inherited via CScene
	virtual void Enter() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Exit() override;
};

