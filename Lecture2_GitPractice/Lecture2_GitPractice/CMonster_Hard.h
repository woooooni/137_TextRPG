#pragma once
#include "CMonster.h"
class CMonster_Hard :
	public CMonster
{
public:
	explicit CMonster_Hard();
	virtual ~CMonster_Hard();

public:
	// CMonster을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

