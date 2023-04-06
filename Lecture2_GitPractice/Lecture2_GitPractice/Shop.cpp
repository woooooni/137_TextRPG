#include "stdafx.h"
#include "Shop.h"


CShop::CShop()// :m_pDummyItem(nullptr),m_pDummyPlayer(nullptr)
{

}


CShop::~CShop()
{
}

void CShop::Initialize()
{
	//m_pDummyItem
}

void CShop::Update()
{
	int iInput(0);
	while (true)
	{
		cout << "1. 초급상점 2. 중급상점 3. 고급상점 :";
		cin >> iInput;
		switch (iInput)
		{
		case 1:

			break;
		case 2:

			break;
		case 3:

			break;
		}

	}

}

void CShop::Release()
{
}

void CShop::ShowItem(int _iShopLevel)
{
	system("cls");
	//m_pDummyPlayer->Render;
	//ItemList->Render;
	int iInput(0);
	while(true)
	{
		cout << "Take your time and look around(1. 무기 2. 방어구 3.포션 4. etc(?)):";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			//BuyItem(m_pItem[_iShopLevel][Weapon]);
			break;
		case 2:
			// BuyItem(m_pItem[_iShopLevel][Armor]);
			break;
		case 3:
			//BuyItem(m_pItem[_iShopLevel][Portion]);
		case 4:
			//BuyItem(m_pItem[_iShopLevel][Something else]);
			break;
		default:
			cout << "잘못 입력하셨습니다." << endl;
			system("pause");
			break;
		}

	}
}

void CShop::BuyItem(void)
{
	/*if (m_pItem->GetMoney() > m_pPlayer->GetMoney())
	{
		cout<<"Not enough Mineral"
	}
	else if(m_)
	
	*/
}
