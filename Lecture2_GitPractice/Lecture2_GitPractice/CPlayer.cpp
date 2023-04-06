#include "stdafx.h"
#include "CPlayer.h"

CPlayer::CPlayer()
{
}

CPlayer::CPlayer(const string & _strName, const ATTACK_OBJ_STAT & _tStat, const OBJECT_TYPE & _eObjType)
	: m_iMoney(0)
	, CAttackObj(_strName, _tStat, _eObjType)
{
}

CPlayer::CPlayer(const string & _strName, const ATTACK_OBJ_STAT & _tStat, const OBJECT_TYPE & _eObjType, const int & _iMoney)
	: m_iMoney(_iMoney)
	, CAttackObj(_strName, _tStat, _eObjType)
{
	
}

CPlayer::CPlayer(const string & _strName, const ATTACK_OBJ_STAT & _tStat, const OBJECT_TYPE & _eObjType, const PLAYER_JOB & _eJob, const int & _iMoney)
	: m_eJob(_eJob)
	, m_iMoney(_iMoney)
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
}

void CPlayer::Release()
{
}
