#pragma once
#include "CAttackObj.h"
class CMonster :
	public CAttackObj
{

public:
	explicit CMonster(string _strName);
	virtual ~CMonster();

public:
	// CObj을(를) 통해 상속됨
	virtual void Initialize()	= 0;
	virtual void Update()		= 0;
	virtual void Render()		= 0;
	virtual void Release()		= 0;
};

