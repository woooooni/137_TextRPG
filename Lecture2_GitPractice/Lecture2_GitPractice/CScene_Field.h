#pragma once
#include "CScene.h"

class CPlayer;
class CMonster;
class CScene_Field :
	public CScene
{
public:
	explicit CScene_Field();
	virtual ~CScene_Field();

public:
	// CScene을(를) 통해 상속됨
	virtual void Enter() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Exit() override;

private:
	int Input();

private:
	CPlayer*	m_pPlayer;
	CMonster*	m_pMonster;
};

