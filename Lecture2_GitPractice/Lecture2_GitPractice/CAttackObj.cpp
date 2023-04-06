#include "stdafx.h"
#include "CAttackObj.h"

CAttackObj::CAttackObj()
	: m_strName("")
	, m_bDead(false)
{
	m_tStat = ATTACK_OBJ_STAT();
}

CAttackObj::CAttackObj(const string & _strName, const OBJECT_TYPE & _eObjType)
	: m_strName("")
	, m_bDead(false)
	, CObj(_eObjType)
{
	m_tStat = ATTACK_OBJ_STAT();
}

CAttackObj::CAttackObj(const string & _strName, const ATTACK_OBJ_STAT & _tStat, const OBJECT_TYPE & _eObjType)
	: m_strName("")
	, m_bDead(false)
	, m_tStat(_tStat)
	, CObj(_eObjType)
{
}

CAttackObj::~CAttackObj()
{
}

const bool CAttackObj::Attack(CAttackObj * const _pAttackObj)
{
	if (nullptr == _pAttackObj) return false;

	_pAttackObj->Damaged(m_tStat.m_iStr);

	return true;
}

const bool CAttackObj::Damaged(const int _iDamage)
{
	if (0 > _iDamage) return false;

	m_tStat.m_iCurHp -= _iDamage;

	if (0 >= m_tStat.m_iCurHp)
	{
<<<<<<< .merge_file_R0LPUh
		if (Set_Dead)
=======
		if (Set_Dead())
>>>>>>> .merge_file_OdgdX9
			return true;
		else
			return false;
	}

	return true;
}

<<<<<<< .merge_file_R0LPUh
=======
void CAttackObj::Initialize()
{
}

void CAttackObj::Update()
{
}

void CAttackObj::Render()
{
}

void CAttackObj::Release()
{
}

>>>>>>> .merge_file_OdgdX9
