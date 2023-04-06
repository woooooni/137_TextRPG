#pragma once
#include "CAttackObj.h"

class CItem;

class CPlayer : public CAttackObj
{
public:
	explicit CPlayer();
	explicit CPlayer(const string& _strName, const ATTACK_OBJ_STAT& _tStat, const OBJECT_TYPE& _eObjType);
	explicit CPlayer(const string& _strName, const ATTACK_OBJ_STAT& _tStat, const OBJECT_TYPE& _eObjType, const int& _iMoney);
	explicit CPlayer(const string& _strName, const ATTACK_OBJ_STAT& _tStat, const OBJECT_TYPE& _eObjType, const PLAYER_JOB& _eJob, const int& _iMoney);
	virtual ~CPlayer();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	// Access Methods 
	PLAYER_JOB Get_Job()				{ return m_eJob; }
	int Get_Money()						{ return m_iMoney; }
	
	bool Set_Job(PLAYER_JOB& _eJob)		{ if (PLAYER_JOB::END == _eJob) return false; m_eJob = _eJob; return true; }
	bool Set_Money(int _iMoney)			{ if (0 > _iMoney) return false; m_iMoney = _iMoney; return true; }

private:
	PLAYER_JOB m_eJob;
	int m_iMoney;
};

