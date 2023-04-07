#include "stdafx.h"
#include "CScene_JobChoice.h"
#include "CSceneMgr.h"
#include "CGameCore.h"
#include "CPlayer.h"


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
	const int iInput = Input();

	if(-1 == iInput)
		CSceneMgr::GetInst()->BackScene();
	else
	{
		CGameCore::GetInst()->GetPlayer()->Set_Job(static_cast<PLAYER_JOB>(iInput));
		Render();
		CSceneMgr::GetInst()->ChangeScene(SCENE_TYPE::LOBBY);
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

	if (0 >= iInput || (unsigned int)PLAYER_JOB::END <= iInput)
	{
		iInput = -1;
		return iInput;
	}

	return iInput - 1;
}
