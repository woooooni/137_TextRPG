#include "stdafx.h"
#include "CScene_JobChoice.h"


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
	{
		cout << i + 1 << ". " << STR_JOB_NAME[i] << "  ";
	}
	cout << "\n--->";
}

void CScene_JobChoice::Update()
{
	switch (Input())
	{
	case 1:
		break;

	default:
		break;
	}	
}

void CScene_JobChoice::Render()
{
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
