#pragma once
#include "CMonster.h"
class CMonster_Hard :
	public CMonster
{
public:
	explicit CMonster_Hard();
	virtual ~CMonster_Hard();

public:
	// CMonster��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

