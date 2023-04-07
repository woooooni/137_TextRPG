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

// 1. ����� 2. ���� 3.���濭�� -> (�κ�, ���) 4. ����

void CScene_Lobby::Enter()
{
	system("cls");
	cout << "�޴��� �������ּ���." << endl;
	cout << "1. �����  " << "2. ����  " << "3. ���� ����  " << "4. ����\n";
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
		// TODO :: ���濭��
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
