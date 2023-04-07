#include "stdafx.h"
#include "CShop.h"


CShop::CShop():m_pPlayer(nullptr), m_pInven(nullptr),CScene(SCENE_TYPE::SHOP)//씬타입 넣은 기억이 읎는디;
{

}


CShop::~CShop()
{
}

void CShop::Enter()
{
	CItem* pItem = new CMace;
	vecItemList[(int)SHOP_LEVEL::BEGGINER].push_back(pItem);
	pItem = new COrangePotion;
	vecItemList[(int)SHOP_LEVEL::BEGGINER].push_back(pItem);
	pItem = new CFruitDagger;
	vecItemList[(int)SHOP_LEVEL::BEGGINER].push_back(pItem);
	pItem = new CWarBow;
	vecItemList[(int)SHOP_LEVEL::BEGGINER].push_back(pItem);
	vecItemList[(int)SHOP_LEVEL::MIDDLE].push_back(pItem);

	vecItemList[(int)SHOP_LEVEL::SENIOR].push_back(pItem);
}

void CShop::ShowItem(int _iLevel)
{

	system("cls");

	int iInput(0);
	while (true)
	{

		m_pPlayer->Render();
		cout << "상점 주인 : 어서오세요! 좋은것들만 모아놨습니다. (0. 나가기):";
		vector<CItem*>::iterator iter = vecItemList[_iLevel].begin();
		for (iter; iter != vecItemList[_iLevel].end(); iter++)
		{
			(*iter)->Render();
		}
		cin >> iInput;
		
		CItem* pItem = vecItemList[_iLevel][iInput - 1];

		BuyItem(pItem);

			if (!vecItemList[_iLevel][iInput - 1])
				cout << "상점 주인 : 이봐 거긴 출입 금지라고!." << endl;
		system("pause");
		break;
	}

}


void CShop::BuyItem(CItem* _pItem)
{
	int iInput;
	if (_pItem->GetItem()->strType == "소모품")
	{
		cout << "구매할" << (_pItem->GetItem()->strName) << "의 갯수를 선택하시오 :";
			cin >> iInput;
	}
	//if (_pItem->GetItem()->iPrice> player's money )
	//{
	//cout<<"돈이 부족합니다"<<endl;
	//}
	//else if(m_pInven)//is full?
	//{
	//cout<<"인벤토리가 가득 찼습니다."<<endl;
	//}
	//else
	//{

	//buy Item?//take player money;
	//cout << "구매 성공" << endl;
	//}
	
}
void CShop::SellItem()
{

	int		iInput = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		m_pInven->Render();
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

		cout << "좋은 물건이군. 좋은 값에 쳐드리지." << endl;
		}
		else
		cout << "뭔가 잘못됐구만" << endl;*/
	}

}




void CShop::Update()
{
	int iInput(0);
	while (true)
	{
		cout << "1. 무기상점 2. 방어구상점 3. 포션상점 0. 전단계:";
		cin >> iInput;
		switch (0)
		{
		case 1:
			ShowItem((int)SHOP_LEVEL::BEGGINER);
			break;
		case 2:
			ShowItem((int)SHOP_LEVEL::MIDDLE);
				break;
		case 3:
			ShowItem((int)SHOP_LEVEL::SENIOR);
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
	cout << "상점 주인 : 쇼핑할 시간이 없어? 다 끓인 차라도 한 잔 들고 가게." << endl;
	system("pause");

	// safedelete 아이템들?
}
