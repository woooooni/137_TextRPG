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
		//TODO :: �÷��̾� ������ ��������.

	cout << "1. �ʱ�\t 2. �߱�\t 3.��� (-1 : ������)" << endl;

	cout << "--->";
	
	switch (Input())
	{
	case 1:
		//TODO :: �ʱ� ���� ����
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
		cout << "����Ϳ��� �����ϴ�." << endl;
		system("pause");
		CSceneMgr::GetInst()->ChangeScene(SCENE_TYPE::LOBBY);
	}

	Render();

	cout << "1. ������.\t 2. ��������." << endl;
	cout << "-->";

	if (1 == Input())
	{
		m_pPlayer->Attack(m_pMonster);

		if (m_pMonster->Is_dead())
		{
			cout << "�÷��̾� Win." << endl;
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
		- Player, Monster ���� ���. 
		- Player, Monster �ο��.
		- Player, Monster HP ����.
		- Player, Monster ����.
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
