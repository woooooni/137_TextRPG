#pragma once
#include "CObj.h"
class CMonster :
	public CObj
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

