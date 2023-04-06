#include "stdafx.h"
#include "CGameCore.h"
#include "CSceneMgr.h"

CGameCore::CGameCore()
{
}


CGameCore::~CGameCore()
{
}

void CGameCore::Initialize()
{
	CSceneMgr::GetInst()->Initialize();
}

void CGameCore::Tick()
{
	CSceneMgr::GetInst()->Update();
}
