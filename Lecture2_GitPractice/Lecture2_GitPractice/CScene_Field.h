#pragma once
#include "CScene.h"
class CScene_Field :
	public CScene
{
public:
	explicit CScene_Field();
	virtual ~CScene_Field();

public:
	// CScene��(��) ���� ��ӵ�
	virtual void Enter() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Exit() override;
};

