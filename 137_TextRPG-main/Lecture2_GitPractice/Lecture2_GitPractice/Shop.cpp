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
	//������ ��ü �޾ƿ���? ����?
}

void CShop::ShowItem(int _iShopLevel)
{
	system("cls");
	//m_pDummyPlayer->Render;
	//ItemList->Render;
	int iInput(0);
	while(true)
	{
		cout << "���� ���� : �������! �����͵鸸 ��Ƴ����ϴ�. (1. ���� 2. �� 3.���� 4. etc(?)):";
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
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
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
		cout<<"�κ��丮�� ���� á���ϴ�."<<endl;
	}
	else
	{
	cout << "���� ����" << endl;
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
		cout << "�Ǹ��� �������� ���ÿ�.(0. ������):" << endl;
		cin >> iInput;
		--iInput;
	
			if (0 > iInput)
				return;
/*
			if (�ִ� �κ��丮 < iInput)
				continue;
*/
			int		iMoney = 0;
			/*if (������ �Ǹ�(iInput, &iMoney))
			{
			
				cout << "���� �����̱���. ���� ���� �ĵ帮��." << endl;
			}
			else
				cout << "�Ǹ� ����" << endl;*/
	}

}




void CShop::Update()
{
	int iInput(0);
	while (true)
	{
		cout << "1. �ʱ޻��� 2. �߱޻��� 3. ��޻��� 0. ���ܰ�:";
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
	cout << "���� ���� : ������ �ð��� ���� ? �� ���� ���� �� �� ��� ����."<<endl;
	system("pause");

	// safedelete �����۵�?
}
