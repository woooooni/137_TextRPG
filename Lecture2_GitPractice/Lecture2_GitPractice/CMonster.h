#pragma once
#include "CAttackObj.h"
class CMonster :
	public CAttackObj
{

public:
	explicit CMonster();
	virtual ~CMonster();

public:
	// CObj��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

