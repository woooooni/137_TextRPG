#include "stdafx.h"
#include "CScene_Field.h"
#include "CAttackObj.h"
#include "CMonster.h"
#include "CMonster_Easy.h"
#include "CMonster_Normal.h"
#include "CMonster_Hard.h"
#include "CSceneMgr.h"
#include "CPlayer.h"

CScene_Field::CScene_Field()
	:CScene(SCENE_TYPE::FIELD)
{
}


CScene_Field::~CScene_Field()
{
}

void CScene_Field::Enter()
{
	system("cls");
	if(nullptr == m_pPlayer)
		//TODO :: 플레이어 정보를 가져오기.

	cout << "1. 초급\t 2. 중급\t 3.고급 (-1 : 나가기)" << endl;

	cout << "--->";
	
	switch (Input())
	{
	case 1:
		//TODO :: 초급 몬스터 생성
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

	cout << "1. 때린다.\t 2. 도망간다." << endl;
	cout << "-->";

	if (1 == Input())
	{
		m_pPlayer->Attack(m_pMonster);

		if (m_pMonster->Is_dead())
		{
			cout << "플레이어 Win." << endl;
			cout << m_pPlayer->Set_Money(m_pPlayer->Get_Money() + 100);
			system("pause");
			CSceneMgr::GetInst()->ChangeScene(SCENE_TYPE::LOBBY);
		}

		m_pMonster->Attack(m_pPlayer);
	}

	else if (2 == Input())
	{

	}

	else
	{

	}

}

void CScene_Field::Render()
{
	/*	TODO :: 
		- Player, Monster 정보 출력. 
		- Player, Monster 싸우기.
		- Player, Monster HP 판정.
		- Player, Monster 보상.
	*/

}

void CScene_Field::Exit()
{

}

int CScene_Field::Input()
{
	int iInput = -1;

	cin >> iInput;
	return iInput;
}
