#include "stdafx.h"
#include "CScene_Field.h"


CScene_Field::CScene_Field()
	:CScene(SCENE_TYPE::FIELD)
{
}


CScene_Field::~CScene_Field()
{
}

void CScene_Field::Enter()
{
	if(nullptr == m_pPlayer)
		//TODO :: �÷��̾� ������ ��������.


	cout << "1. �ʱ�\t 2. �߱�\t 3.��� (-1 : ������)" << endl;

	cout << "--->";

	int iInput = Input();

	if (iInput == -1)
		return;
	
	switch (iInput)
	{
	case 1:
		//TODO :: �ʱ� ���� ����
		// m_pMonster = 
		break;
	case 2:
		//TODO :: �߱� ���� ����
		break;
	case 3:
		//TODO :: ��� ���� ����
		break;
		
	default:
		break;
	}
}

void CScene_Field::Update()
{

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
