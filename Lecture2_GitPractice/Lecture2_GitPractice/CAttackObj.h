#pragma once
#include "CObj.h"

typedef struct tagStat // Struct.h로 옮겨야 한다. 
{
	int m_iMaxHp;
	int m_iCurHp;
	int m_iStr;
	
	tagStat()
		: m_iMaxHp(0), m_iCurHp(0), m_iStr(0) {}

	tagStat(const int& _iMaxHp, const int& _iCurHp, const int& _iStr)
		: m_iMaxHp(_iMaxHp), m_iCurHp(_iCurHp), m_iStr(_iStr) {}

	/*const tagStat operator +=(const tagStat& _rStat)
	{
		tagStat tTemp(m_iMaxHp += _rStat.m_iMaxHp, m_iCurHp += _rStat.m_iCurHp, m_iStr += _rStat.m_iStr);

		return tTemp;
	}*/

}ATTACK_OBJ_STAT;


class CAttackObj :
	public CObj
{
public:
	explicit CAttackObj();
	explicit CAttackObj(const string& _strName, const OBJECT_TYPE& _eObjType);
	explicit CAttackObj(const string& _strName, const ATTACK_OBJ_STAT& _tStat, const OBJECT_TYPE& _eObjType);

	~CAttackObj();

public:
	// Access Methods
	const bool Set_Name(const string& _strName)		{ if ("" == _strName) return false;  m_strName = _strName; return true; }
	const bool Set_Dead()							{ if (true == m_bDead) return false; m_bDead = true;  return true; }
	const bool Set_MaxHp(const int& _iMaxHp)		{ if (0 > _iMaxHp) return false; m_tStat.m_iMaxHp = _iMaxHp; return true; }
	const bool Set_CurHp(const int& _iCurHp)		{ if (0 > _iCurHp) return false; m_tStat.m_iCurHp = _iCurHp; return true; }
	const bool Set_Str(const int& _iStr)			{ if (0 > _iStr) return false; m_tStat.m_iStr = _iStr; return true; }

	const ATTACK_OBJ_STAT& Get_Stat() const			{ return m_tStat; }
	const string& Get_Name() const					{ return m_strName; }

public:
	// Attack 관련
	const bool Attack(CAttackObj* const _pAttackObj);
	const bool Damaged(const int _iDamage);

	const bool Is_dead() const						{ return m_bDead; }
	void Revive()									{ m_bDead = true; }

protected:
	string m_strName; // 아이템은 이름을 구조체에 저장.. 그럼 플레이어랑 몬스터는 여기에?
	bool  m_bDead;
	ATTACK_OBJ_STAT m_tStat;
};
