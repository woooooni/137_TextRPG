#pragma once
#include "CMonster.h"
class CMonster_Easy :
	public CMonster
{
public:
	explicit CMonster_Easy();
	virtual ~CMonster_Easy();

public:
	// CMonster��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

