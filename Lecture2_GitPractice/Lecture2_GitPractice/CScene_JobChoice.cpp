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

	cout << "직업을 선택해주세요." << endl;

	for (int i = 0; i < (unsigned int)PLAYER_JOB::END; ++i)
		cout << i + 1 << ". " << STR_JOB_NAME[i] << "  ";

	cout << "  (-1 : 이전)" << endl;

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
		// TODO :: 플레이어 직업 세팅.
		// ex) pPlayer->Set_Job(Input());
		Render();
		CSceneMgr::GetInst()->ChangeScene(SCENE_TYPE::LOBBY);
		break;
	}	
}

void CScene_JobChoice::Render()
{
	cout << endl << "직업 설정이 완료되었습니다." << endl;

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
