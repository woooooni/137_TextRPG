#pragma once
#include "CAttackObj.h"

class CItem;

class CPlayer : public CAttackObj
{
public:
	explicit CPlayer();
	explicit CPlayer(const string& _strName, const ATTACK_OBJ_STAT& _tStat, const OBJECT_TYPE& _eObjType);
	explicit CPlayer(const string& _strName, const ATTACK_OBJ_STAT& _tStat, const OBJECT_TYPE& _eObjType, const PLAYER_JOB& _eJob);
	virtual ~CPlayer();

public:
	// Override
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	// Access Methods 
	PLAYER_JOB	Get_Job() const					{ return m_eJob; }
	bool		Set_Job(PLAYER_JOB& _eJob)		{ if (PLAYER_JOB::END == _eJob) return false; m_eJob = _eJob; return true; }

public:
	// Item
	bool Reflect_Stat(CItem* _pItem, bool _bUnEquip); // 아이템 적용시 스탯에 반영 ('장비 착용 해제'만 true, 나머지 장비 착용이나 포션 아이템 사용은 false)
	bool Reflect_Stat(CItem& _rItem, bool _bUnEquip); // overloading

private:
	PLAYER_JOB m_eJob;
};

