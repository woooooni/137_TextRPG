#include "stdafx.h"
#include "CScene_Field.h"
#include "CSceneMgr.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CMonster_Easy.h"
#include "CMonster_Normal.h"
#include "CMonster_Hard.h"
#include "Template.h"

CScene_Field::CScene_Field()
	:CScene(SCENE_TYPE::FIELD)
{
}


CScene_Field::~CScene_Field()
{
	if (m_pMonster)
		Safe_Delete<CMonster*>(m_pMonster);
}

void CScene_Field::Enter()
{
	if(nullptr == m_pPlayer)
		//TODO :: 플레이어 정보를 가져오기.


	cout << "1. 초급\t 2. 중급\t 3.고급 (-1 : 나가기)" << endl;

	cout << "--->";

	int iInput = Input();

	if (iInput == -1)
		return;
	
	switch (iInput)
	{
	case 1:
		m_pMonster = new CMonster_Easy;
		break;
	case 2:
		m_pMonster = new CMonster_Normal;
		break;
	case 3:
		m_pMonster = new CMonster_Hard;
		break;
		
	default:
		break;
	}
}

void CScene_Field::Update()
{
	if (nullptr == m_pMonster)
	{
		cout << "사냥터에서 나갑니다." << endl;
		system("pause");
		CSceneMgr::GetInst()->ChangeScene(SCENE_TYPE::LOBBY);
	}

	Render();

	if (1 == Input())
		Fight();
	else
		RunAway();
}

void CScene_Field::Render()
{
	m_pPlayer->Render();
	m_pMonster->Render();

	cout << "1. 때린다.\t 2. 도망간다." << endl;
	cout << "-->";

}

void CScene_Field::Exit()
{
	if (m_pMonster)
		Safe_Delete<CMonster*>(m_pMonster);
}

int CScene_Field::Input()
{
	int iInput = -1;

	cin >> iInput;
	return iInput;
}

void CScene_Field::Fight()
{
	m_pPlayer->Attack(m_pMonster);

	if (m_pMonster->Is_dead())
	{
		cout << "플레이어 Win." << endl;
		cout << m_pPlayer->Set_Gold(m_pPlayer->Get_Stat().m_iGold + 100);
		system("pause");
		CSceneMgr::GetInst()->ChangeScene(SCENE_TYPE::LOBBY);
	}

	m_pMonster->Attack(m_pPlayer);

	if (m_pPlayer->Is_dead())
	{
		cout << "플레이어 Lose." << endl;
		cout << m_pPlayer->Set_Gold(m_pPlayer->Get_Stat().m_iGold + 100);
		system("pause");
		m_pPlayer->Revive();
		CSceneMgr::GetInst()->ChangeScene(SCENE_TYPE::LOBBY);
	}
}

void CScene_Field::RunAway()
{
	m_pPlayer->Set_Gold(m_pPlayer->Get_Stat().m_iGold - 100);
	cout << "플레이어가 도망쳤습니다." << endl;
	system("pause");
	CSceneMgr::GetInst()->ChangeScene(SCENE_TYPE::LOBBY);
}
