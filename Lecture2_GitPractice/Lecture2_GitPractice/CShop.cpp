#include "stdafx.h"
#include "CShop.h"


CShop::CShop()
	: m_pPlayer(nullptr)
	, CScene(SCENE_TYPE::SHOP)
{

}


CShop::~CShop()
{
}

void CShop::Enter()
{
	//������
	//��,��, ��&��
	//����:����, ����&��: ����
	CItem* pItem = new CMace;
	vecItemList[(int)SHOP_LEVEL::BEGGINER].push_back(pItem);
	pItem = new CRedPotion;
	vecItemList[(int)SHOP_LEVEL::BEGGINER].push_back(pItem);
	pItem = new CWoodWand;
	vecItemList[(int)SHOP_LEVEL::MIDDLE].push_back(pItem);
	pItem = new CMaplePants;
	vecItemList[(int)SHOP_LEVEL::MIDDLE].push_back(pItem);
	pItem = new COrangePotion;
	vecItemList[(int)SHOP_LEVEL::MIDDLE].push_back(pItem);
	pItem = new CMapleHat;
	vecItemList[(int)SHOP_LEVEL::SENIOR].push_back(pItem);
	pItem = new CMapleCloth;
	vecItemList[(int)SHOP_LEVEL::SENIOR].push_back(pItem);
	pItem = new CFruitDagger;
	vecItemList[(int)SHOP_LEVEL::SENIOR].push_back(pItem);
	pItem = new CWarBow;
	vecItemList[(int)SHOP_LEVEL::SENIOR].push_back(pItem);
	pItem = new CWhitePotion;
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
		if (vecItemList[_iLevel].size() <= iInput)
		{
			cout << "���� ���� : �̺� �ű� ���� �������!." << endl;
			system("pause");

		}
		else if (iInput == 0)
		return;

		
		else
		{
			CItem* pItem = vecItemList[_iLevel][iInput - 1];

			BuyItem(pItem);
			
		}
			
	}

}


void CShop::BuyItem(CItem* _pItem)
{
	bool bSuccess;
	int iInput(1), iPrice(0); 
	if (_pItem->GetItem().eType == EQUIP_TYPE::NONEQUIP)
	{
		cout << "������" << (_pItem->GetItem().strName) << "�� ������ �����Ͻÿ� :";
			cin >> iInput;
			iPrice = _pItem->GetItem().iPrice*iInput;
	}
	else
	{
		iPrice = _pItem->GetItem().iPrice;
	}
	bSuccess = m_pPlayer->Set_Gold(m_pPlayer->Get_Stat().m_iGold - iPrice);
	if (bSuccess==false)
	{
	cout<<"���� �����մϴ�"<<endl;
	}
	else
	{
		m_pPlayer->Get_Inventory()->AddItem(_pItem, iInput);
	cout << "���� ����" << endl;
	}
	
}
void CShop::SellItem()
{

	int		iInput = 0;

	while (true)
	{	int		iMoney = 0;
		system("cls");
		m_pPlayer->Render();
		m_pPlayer->Get_Inventory()->Render();
		cout << "�Ǹ��� �������� ���ÿ�.(0. ������):" << endl;
		cin >> iInput;
		--iInput;

		if (0 > iInput)
			return;
		m_pPlayer->Get_Inventory()->GetInven().erase(m_pPlayer->Get_Inventory()->GetInven().begin() + iInput);
		if
		cout << "���� �����̱�. ���� ���� �ĵ帮��." << endl;
	
		
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
}
