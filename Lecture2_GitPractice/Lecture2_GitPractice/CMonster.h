#pragma once
#include "CAttackObj.h"
class CMonster :
	public CAttackObj
{

public:
	explicit CMonster(string _strName, int _iMoney);
	virtual ~CMonster();

public:
	// CObj��(��) ���� ��ӵ�
	virtual void Initialize()	= 0;
	virtual void Update()		= 0;
	virtual void Render()		= 0;
	virtual void Release()		= 0;

private:
	int m_iMoney;
};

