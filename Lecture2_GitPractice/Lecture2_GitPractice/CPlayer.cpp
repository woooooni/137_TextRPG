#include "stdafx.h"
#include "CPlayer.h"
#include "CItem.h"

CPlayer::CPlayer()
{
}

CPlayer::CPlayer(const string & _strName, const ATTACK_OBJ_STAT & _tStat, const OBJECT_TYPE & _eObjType)
	: CAttackObj(_strName, _tStat, _eObjType)
{
}

CPlayer::CPlayer(const string & _strName, const ATTACK_OBJ_STAT & _tStat, const OBJECT_TYPE & _eObjType, const PLAYER_JOB & _eJob)
	: m_eJob(_eJob)
	, CAttackObj(_strName, _tStat, _eObjType)
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::Initialize()
{
}

void CPlayer::Update()
{
}

void CPlayer::Render()
{
	CAttackObj::Render();
	cout << "Á÷¾÷ :\t" << STR_JOB_NAME[(int)m_eJob] << endl;
	cout << "°ñµå :\t" << m_tStat.m_iGold << endl;
}

void CPlayer::Release()
{
}

bool CPlayer::Reflect_Stat(CItem * _pItem, bool _bUnEquip)
{
	if (nullptr == _pItem) return false;

	if (_bUnEquip)
	{
		m_tStat.m_iMaxHp	-= _pItem->GetItem()->iHp;
		m_tStat.m_iCurHp	-= _pItem->GetItem()->iRecovery;
		m_tStat.m_iStr		-= _pItem->GetItem()->iAtk;
	}
	else
	{
		m_tStat.m_iMaxHp	+= _pItem->GetItem()->iHp;
		m_tStat.m_iCurHp	+= _pItem->GetItem()->iRecovery;
		m_tStat.m_iStr		+= _pItem->GetItem()->iAtk;

		if (m_tStat.m_iMaxHp < m_tStat.m_iCurHp)
			m_tStat.m_iCurHp = m_tStat.m_iMaxHp;
	}

	return true;
}

bool CPlayer::Reflect_Stat(CItem & _rItem, bool _bUnEquip)
{
	if (_bUnEquip)
	{
		m_tStat.m_iMaxHp	-= _rItem.GetItem()->iHp;
		m_tStat.m_iCurHp	-= _rItem.GetItem()->iRecovery;
		m_tStat.m_iStr		-= _rItem.GetItem()->iAtk;
	}
	else
	{
		m_tStat.m_iMaxHp	+= _rItem.GetItem()->iHp;
		m_tStat.m_iCurHp	+= _rItem.GetItem()->iRecovery;
		m_tStat.m_iStr		+= _rItem.GetItem()->iAtk;

		if (m_tStat.m_iMaxHp < m_tStat.m_iCurHp)
			m_tStat.m_iCurHp = m_tStat.m_iMaxHp;
	}

	return true;
}
