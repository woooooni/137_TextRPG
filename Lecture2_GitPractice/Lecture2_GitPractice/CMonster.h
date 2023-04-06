#pragma once
#include "CObj.h"
class CMonster :
	public CObj
#include "CAttackObj.h"
class CMonster :
	public CAttackObj
{

public:
	explicit CMonster();
	virtual ~CMonster();

public:
	// CObjÀ»(¸¦) ÅëÇØ »ó¼ÓµÊ
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

