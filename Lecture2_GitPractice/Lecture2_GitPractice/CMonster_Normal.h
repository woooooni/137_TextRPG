#pragma once
#include "CMonster.h"
class CMonster_Normal :
	public CMonster
{
public:
	explicit CMonster_Normal();
	virtual ~CMonster_Normal();

public:
	// CMonster을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

