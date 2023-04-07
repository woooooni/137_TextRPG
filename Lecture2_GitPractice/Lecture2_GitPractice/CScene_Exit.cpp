#include "stdafx.h"
#include "CScene_Exit.h"
#include "CGameCore.h"

CScene_Exit::CScene_Exit()
	: CScene(SCENE_TYPE::EXIT)
{
}

CScene_Exit::~CScene_Exit()
{
}

void CScene_Exit::Enter()
{
}

void CScene_Exit::Update()
{
	cout << "게임을 종료하겠습니다.\n";

	system("pause");

	CGameCore::GetInst()->Stop();
}

void CScene_Exit::Render()
{
}

void CScene_Exit::Exit()
{
}
