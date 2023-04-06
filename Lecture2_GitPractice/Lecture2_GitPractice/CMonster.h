#pragma once
<<<<<<< .merge_file_I07I8O
#include "CObj.h"
class CMonster :
	public CObj
=======
#include "CAttackObj.h"
class CMonster :
	public CAttackObj
>>>>>>> .merge_file_MPh6Wu
{

public:
	explicit CMonster();
	virtual ~CMonster();

public:
	// CObj을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

