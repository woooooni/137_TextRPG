#include "stdafx.h"
#include "CGameCore.h"
#include "CSceneMgr.h"
#include "CPlayer.h"

CGameCore::CGameCore()
	: m_bPlaying(true)
	, m_pPlayer(nullptr)
{
}

CGameCore::~CGameCore()
{
}

void CGameCore::Initialize()
{
	m_pPlayer = new CPlayer;
	m_pPlayer->Initialize();

	CSceneMgr::GetInst()->Initialize();
}

void CGameCore::Tick()
{
	while (m_bPlaying)
	{
		// Manager Update
		CSceneMgr::GetInst()->Update();
	}
}

void CGameCore::Release()
{
	if (m_pPlayer) 
		Safe_Delete<CPlayer*>(m_pPlayer);
}
