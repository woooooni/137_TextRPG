#include "stdafx.h"
#include "Shop.h"


CShop::CShop()// :m_pDummyItem(nullptr),m_pDummyPlayer(nullptr) m_pInven(nullptr)
	:CScene(SCENE_TYPE::SHOP)
{

}


CShop::~CShop()
{
}

void CShop::Enter()
{
	//아이템 객체 받아오기? 생성?
}

void CShop::ShowItem(int _iShopLevel)
{
	system("cls");
	//m_pDummyPlayer->Render;
	//ItemList->Render;
	int iInput(0);
	while(true)
	{
		cout << "상점 주인 : 어서오세요! 좋은것들만 모아놨습니다. (1. 무기 2. 방어구 3.포션 4. etc(?)):";
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
		cout<<"Not enough Mineral"<<endl;
	}
	else if(m_Inventory->isFull;)
	{
		cout<<"인벤토리가 가득 찼습니다."<<endl;
	}
	else
	{
	cout << "구매 성공" << endl;
	}
	*/
}
void CShop::SellItem()
{

	int		iInput = 0;

	while (true)
	{
		system("cls");
		/*m_pPlayer->Render();
		m_pInventory->Render();*/
		cout << "판매할 아이템을 고르시오.(0. 나가기):" << endl;
		cin >> iInput;
		--iInput;
	
			if (0 > iInput)
				return;
/*
			if (최대 인벤토리 < iInput)
				continue;
*/
			int		iMoney = 0;
			/*if (아이템 판매(iInput, &iMoney))
			{
			
				cout << "좋은 물건이군요. 좋은 값에 쳐드리죠." << endl;
			}
			else
				cout << "판매 실패" << endl;*/
	}

}




void CShop::Update()
{
	int iInput(0);
	while (true)
	{
		cout << "1. 초급상점 2. 중급상점 3. 고급상점 0. 전단계:";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			ShowItem(0);
			break;
		case 2:
			ShowItem(1);
			break;
		case 3:
			ShowItem(2);
			break;
		case 0:
			return;
		}

	}

}

void CShop::Render()
{
}

void CShop::Exit()
{
	cout << "상점 주인 : 쇼핑할 시간이 없어 ? 다 끓인 차라도 한 잔 들고 가게."<<endl;
	system("pause");

	// safedelete 아이템들?
}
