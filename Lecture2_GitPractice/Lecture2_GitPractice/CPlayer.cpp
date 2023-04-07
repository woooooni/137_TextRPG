#include "stdafx.h"
#include "CPlayer.h"
#include "CItem.h"
#include "CInventory.h"
#include "CEquip.h"

CPlayer::CPlayer()
	: m_pInventory(nullptr)
	, m_pEquip(nullptr)
{
}

CPlayer::CPlayer(const string & _strName, const ATTACK_OBJ_STAT & _tStat, const OBJECT_TYPE & _eObjType)
	: m_pInventory(nullptr)
	, m_pEquip(nullptr)
	, CAttackObj(_strName, _tStat, _eObjType)
{
}

CPlayer::CPlayer(const string & _strName, const ATTACK_OBJ_STAT & _tStat, const OBJECT_TYPE & _eObjType, const PLAYER_JOB & _eJob)
	: m_eJob(_eJob)
	, m_pInventory(nullptr)
	, m_pEquip(nullptr)
	, CAttackObj(_strName, _tStat, _eObjType)
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	string name;
	cout << "�÷��̾� �̸��� �Է��ϼ���. : ";
	cin >> name;

	Set_Name(name);

	Set_MaxHp(100);
	Set_CurHp(100);
	Set_Str(5);
	Set_Gold(20000);

	if (nullptr == m_pInventory)
	{
		m_pInventory = new CInventory;
		m_pInventory->Init();
		m_pInventory->SetPlayer(this);
	}
	
	if (nullptr == m_pEquip)
	{
		m_pEquip = new CEquip;
		m_pEquip->Initialize();
		m_pEquip->Set_EqPlayer(this);
	}
}

void CPlayer::Update()
{
}

void CPlayer::Render()
{
	CAttackObj::Render();
	cout << "���� :\t" << STR_JOB_NAME[(int)m_eJob] << endl;
	cout << "��� :\t" << m_tStat.m_iGold << endl;
}

void CPlayer::Release()
{
	Safe_Delete<CInventory*>(m_pInventory);
	Safe_Delete<CEquip*>(m_pEquip);
}

bool CPlayer::Reflect_Stat(CItem * _pItem, bool _bUnEquip)
{
	if (nullptr == _pItem) return false;

	if (_bUnEquip)
	{
		m_tStat.m_iMaxHp	-= _pItem->GetItem().iHp;
		m_tStat.m_iCurHp	-= _pItem->GetItem().iRecovery;
		m_tStat.m_iStr		-= _pItem->GetItem().iAtk;
	}
	else
	{
		m_tStat.m_iMaxHp	+= _pItem->GetItem().iHp;
		m_tStat.m_iCurHp	+= _pItem->GetItem().iRecovery;
		m_tStat.m_iStr		+= _pItem->GetItem().iAtk;

		if (m_tStat.m_iMaxHp < m_tStat.m_iCurHp)
			m_tStat.m_iCurHp = m_tStat.m_iMaxHp;
	}

	return true;
}

bool CPlayer::Reflect_Stat(CItem & _rItem, bool _bUnEquip)
{
	if (_bUnEquip)
	{
		m_tStat.m_iMaxHp	-= _rItem.GetItem().iHp;
		m_tStat.m_iCurHp	-= _rItem.GetItem().iRecovery;
		m_tStat.m_iStr		-= _rItem.GetItem().iAtk;
	}
	else
	{
		m_tStat.m_iMaxHp	+= _rItem.GetItem().iHp;
		m_tStat.m_iCurHp	+= _rItem.GetItem().iRecovery;
		m_tStat.m_iStr		+= _rItem.GetItem().iAtk;

		if (m_tStat.m_iMaxHp < m_tStat.m_iCurHp)
			m_tStat.m_iCurHp = m_tStat.m_iMaxHp;
	}

	return true;
}
