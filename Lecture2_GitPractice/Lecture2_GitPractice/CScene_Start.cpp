#include "stdafx.h"
#include "CScene_Start.h"
#include "CSceneMgr.h"

CScene_Start::CScene_Start()
	: CScene(SCENE_TYPE::START)
{
}

CScene_Start::~CScene_Start()
{
}

void CScene_Start::Enter()
{
	cout << "시작하려면 아무키나 입력해주세요." << endl;
	
	system("pause");
}

void CScene_Start::Update()
{
	CSceneMgr::GetInst()->ChangeScene(SCENE_TYPE::JOB_CHOICE);
}

void CScene_Start::Render()
{

}

void CScene_Start::Exit()
{
}
