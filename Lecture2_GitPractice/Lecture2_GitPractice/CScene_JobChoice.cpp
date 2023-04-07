#include "stdafx.h"
#include "CScene_JobChoice.h"
#include "CSceneMgr.h"


CScene_JobChoice::CScene_JobChoice()
	: CScene(SCENE_TYPE::JOB_CHOICE)
{
}

CScene_JobChoice::~CScene_JobChoice()
{
}

void CScene_JobChoice::Enter()
{
	system("cls");

	cout << "������ �������ּ���." << endl;

	for (int i = 0; i < (unsigned int)PLAYER_JOB::END; ++i)
		cout << i + 1 << ". " << STR_JOB_NAME[i] << "  ";

	cout << "  (-1 : ����)" << endl;

	cout << endl << "--->";
}

void CScene_JobChoice::Update()
{
	switch (Input())
	{
	case 1:
		CSceneMgr::GetInst()->BackScene();
		break;
	default:
		// TODO :: �÷��̾� ���� ����.
		// ex) pPlayer->Set_Job(Input());
		Render();
		CSceneMgr::GetInst()->ChangeScene(SCENE_TYPE::LOBBY);
		break;
	}	
}

void CScene_JobChoice::Render()
{
	cout << endl << "���� ������ �Ϸ�Ǿ����ϴ�." << endl;

	system("pause");
}

void CScene_JobChoice::Exit()
{
}

const int CScene_JobChoice::Input()
{
	int iInput = -1;

	cin >> iInput;

	if (0 > iInput || (unsigned int)PLAYER_JOB::END <= iInput)
		iInput = -1;

	return iInput;
}
