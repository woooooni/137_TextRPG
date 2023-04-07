#include "stdafx.h"
#include "CBag.h"


CBag::CBag()
{

}


CBag::~CBag()
{
}

void CBag::Init()
{
}

void CBag::Update()
{
	int iInput = 0;
	while (true) {
		m_pEquip->Render();
		m_pPlayer->Render();
		m_pInven->Render();
		cout << "1. 인벤토리  2. 장비창  3. 돌아가기" << endl;
		cin >> iInput;

	}
}

void CBag::Render()
{
}

void CBag::Release()
{
}
