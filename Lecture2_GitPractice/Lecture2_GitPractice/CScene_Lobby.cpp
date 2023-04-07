#include "stdafx.h"
#include "CScene_Lobby.h"
#include "CSceneMgr.h"

CScene_Lobby::CScene_Lobby()
	: CScene(SCENE_TYPE::LOBBY)
{
}


CScene_Lobby::~CScene_Lobby()
{
}

void CScene_Lobby::Enter()
{
	system("cls");

	cout << "메뉴를 선택해주세요." << endl;

	for (int i = 0; i < (unsigned int)SCENE_TYPE::END; ++i)
		cout << i + 1 << ". " << STR_MENU[i] << "  ";

	cout << endl << "--->";
}

void CScene_Lobby::Update()
{
	CSceneMgr::GetInst()->ChangeScene(static_cast<SCENE_TYPE>(Input()));
}

void CScene_Lobby::Render()
{
}

void CScene_Lobby::Exit()
{
}

const int CScene_Lobby::Input()
{
	int iInput = (unsigned int)SCENE_TYPE::EXIT;

	cin >> iInput;

	if (0 > iInput || (unsigned int)PLAYER_JOB::END <= iInput)
		iInput = (unsigned int)SCENE_TYPE::EXIT;

	return iInput;
}
