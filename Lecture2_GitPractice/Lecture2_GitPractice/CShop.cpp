#include "stdafx.h"
#include "CShop.h"


CShop::CShop():m_pPlayer(nullptr), m_pInven(nullptr),CScene(SCENE_TYPE::SHOP)//��Ÿ�� ���� ����� ���µ�;
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
		cout << "���� ���� : �������! �����͵鸸 ��Ƴ����ϴ�. (0. ������):";
		vector<CItem*>::iterator iter = vecItemList[_iLevel].begin();
		for (iter; iter != vecItemList[_iLevel].end(); iter++)
		{
			(*iter)->Render();
		}
		cin >> iInput;
		
		CItem* pItem = vecItemList[_iLevel][iInput - 1];

		BuyItem(pItem);

			if (!vecItemList[_iLevel][iInput - 1])
				cout << "���� ���� : �̺� �ű� ���� �������!." << endl;
		system("pause");
		break;
	}

}


void CShop::BuyItem(CItem* _pItem)
{
	int iInput;
	if (_pItem->GetItem()->strType == "�Ҹ�ǰ")
	{
		cout << "������" << (_pItem->GetItem()->strName) << "�� ������ �����Ͻÿ� :";
			cin >> iInput;
	}
	//if (_pItem->GetItem()->iPrice> player's money )
	//{
	//cout<<"���� �����մϴ�"<<endl;
	//}
	//else if(m_pInven)//is full?
	//{
	//cout<<"�κ��丮�� ���� á���ϴ�."<<endl;
	//}
	//else
	//{

	//buy Item?//take player money;
	//cout << "���� ����" << endl;
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

		cout << "���� �����̱�. ���� ���� �ĵ帮��." << endl;
		}
		else
		cout << "���� �߸��Ʊ���" << endl;*/
	}

}




void CShop::Update()
{
	int iInput(0);
	while (true)
	{
		cout << "1. ������� 2. ������ 3. ���ǻ��� 0. ���ܰ�:";
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
	cout << "���� ���� : ������ �ð��� ����? �� ���� ���� �� �� ��� ����." << endl;
	system("pause");

	// safedelete �����۵�?
}
