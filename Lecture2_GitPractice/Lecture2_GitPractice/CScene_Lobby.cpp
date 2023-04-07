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

// 1. 사냥터 2. 상점 3.가방열기 -> (인벤, 장비) 4. 종료

void CScene_Lobby::Enter()
{
	system("cls");
	cout << "메뉴를 선택해주세요." << endl;
	cout << "1. 사냥터  " << "2. 상점  " << "3. 가방 열기  " << "4. 종료\n";
	cout << endl << "--->";
}

void CScene_Lobby::Update()
{
	switch (Input())
	{
	case 1:
		CSceneMgr::GetInst()->ChangeScene(SCENE_TYPE::FIELD);
		break;
	case 2:
		CSceneMgr::GetInst()->ChangeScene(SCENE_TYPE::SHOP);
		break;
	case 3:
		// TODO :: 가방열기
	default:
		CSceneMgr::GetInst()->ChangeScene(SCENE_TYPE::EXIT);
	}
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
