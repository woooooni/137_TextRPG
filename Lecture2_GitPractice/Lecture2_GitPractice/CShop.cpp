#include "stdafx.h"
#include "CShop.h"


CShop::CShop()// :m_pDummyItem(nullptr),m_pDummyPlayer(nullptr) m_pInven(nullptr)
	:CScene(SCENE_TYPE::SHOP)
{

}


CShop::~CShop()
{
}

void CShop::Enter()
{
	CItem* pItem;



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

		//m_pDummyPlayer->Render;
		cout << "���� ���� : �������! �����͵鸸 ��Ƴ����ϴ�. (0. ������):";
		vector<CItem*>::iterator iter = vecItemList[_iLevel].begin;
		for (iter; iter != vecItemList[_iLevel].end; iter++)
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


void CShop::BuyItem(CItem* pItem)
{
	//if(pItem->GetItem()->strtype==�Ҹ�ǰ)
	//cout<< "������"<< /*������*/<<"�� ������ �����Ͻÿ� :"

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
		cout << "�Ǹ��� �������� �����ÿ�.(0. ������):" << endl;
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
		cout << "1. �ʱ޻��� 2. �߱޻��� 3. ���޻��� 0. ���ܰ�:";
		cin >> iInput;
		switch (0)
		{
		case 1:
			ShowItem(1);
			break;
		case 2:
			ShowItem(2);
				break;
		case 3:
			ShowItem(3);
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
	cout << "���� ���� : ������ �ð��� ���� ? �� ���� ���� �� �� ��� ����." << endl;
	system("pause");

	// safedelete �����۵�?
}