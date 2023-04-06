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
		//TODO :: 플레이어 정보를 가져오기.


	cout << "1. 초급\t 2. 중급\t 3.고급 (-1 : 나가기)" << endl;

	cout << "--->";

	int iInput = Input();

	if (iInput == -1)
		return;
	
	switch (iInput)
	{
	case 1:
		//TODO :: 초급 몬스터 생성
		// m_pMonster = 
		break;
	case 2:
		//TODO :: 중급 몬스터 생성
		break;
	case 3:
		//TODO :: 고급 몬스터 생성
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
