#pragma once
#include "CObj.h"

class CAttackObj :
	public CObj
{
public:
	explicit CAttackObj();
	explicit CAttackObj(const string& _strName, const OBJECT_TYPE& _eObjType);
	explicit CAttackObj(const string& _strName, const ATTACK_OBJ_STAT& _tStat, const OBJECT_TYPE& _eObjType);

	~CAttackObj();

public:
	// Override
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	// Access Methods
	const bool					Set_Name(const string& _strName)		{ if ("" == _strName) return false; m_strName = _strName; return true; }
	const bool					Set_Dead()							{ if (true == m_bDead) return false; m_bDead = true; return true; }
	const bool					Set_MaxHp(const int& _iMaxHp)		{ if (0 > _iMaxHp) return false; m_tStat.m_iMaxHp = _iMaxHp; return true; }
	const bool					Set_CurHp(const int& _iCurHp)		{ if (0 > _iCurHp) return false; m_tStat.m_iCurHp = _iCurHp; return true; }
	const bool					Set_Str(const int& _iStr)			{ if (0 > _iStr) return false; m_tStat.m_iStr = _iStr; return true; }
	const bool					Set_Gold(const int& _iGold)			{ if (0 > _iGold) return false; m_tStat.m_iGold = _iGold; return true; }
	const ATTACK_OBJ_STAT&		Get_Stat() const					{ return m_tStat; }
	const string&				Get_Name() const					{ return m_strName; }

public:
	// Attack ����
	const bool	Attack(CAttackObj* const _pAttackObj);
	const bool	Damaged(const int _iDamage);
	const bool	Is_dead() const								{ return m_bDead; }
	void		Revive()									{ m_bDead = true; }

protected:
	string				m_strName; 
	bool				m_bDead;
	ATTACK_OBJ_STAT		m_tStat;
};
