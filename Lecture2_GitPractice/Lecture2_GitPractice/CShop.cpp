#include "stdafx.h"
#include "CShop.h"
#include "CSceneMgr.h"

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

	int iInput(0);
	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		cout << "���� ���� : �������! �����͵鸸 ��Ƴ����ϴ�. (0. ������):" << endl;
		vector<CItem*>::iterator iter = vecItemList[_iLevel].begin();
		for (iter; iter != vecItemList[_iLevel].end(); iter++)
		{
			(*iter)->Render();
		}
		cin >> iInput;
		if (vecItemList[_iLevel].size() < iInput)
		{
			system("cls");
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
		system("cls");
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
		system("cls");
	cout<<"���� ���� : �ܻ��� �ȵ�!"<<endl;
	system("pause");
	}
	else
	{
		system("cls");
		m_pPlayer->Get_Inventory()->AddItem(_pItem, iInput);
	cout << "���� ���� : ���� �����̱���! ���� ���ϼ̾��!" << endl;
	system("pause");
	}
	
}
void CShop::SellItem()
{
	
	int		iInput = 0, iAmount(0);

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
		
		m_pPlayer->Get_Inventory()->GetInven().at(iInput);
		if (m_pPlayer->Get_Inventory()->GetInven().at(iInput)->GetItem().eType == EQUIP_TYPE::NONEQUIP)
		{
			system("cls");
			cout << "�Ǹ��� " << (m_pPlayer->Get_Inventory()->GetInven().at(iInput)->GetItem().strName) << "�� ������ �����Ͻÿ� :";
			cin >> iAmount;
			
		}	
		else
		{
			iAmount = 1;
		}

		
		
		bool bSuccess = m_pPlayer->Get_Inventory()->DecreaseItem(iInput, iAmount );
		if (bSuccess == true)
		{
			m_pPlayer->Set_Gold(m_pPlayer->Get_Stat().m_iGold + m_pPlayer->Get_Inventory()->GetInven().at(iInput)->GetItem().iPrice *iAmount);
			system("cls");
				cout << "���� ���� : ���� �����̱�. ���� ���� �ĵ帮��." << endl;
				system("pause");
		}

		else
		{
			system("cls");
			cout << "���� ���� : ���� ������ ���� ����." << endl;
			system("pause");
		}
	}

}




void CShop::Update()
{
	int iInput(0);
	system("cls");
	cout << "1. �ʱ޻��� 2. �߱޻��� 3. ����޻��� 4. �Ǹ� 0. ���ܰ�:";
	cin >> iInput;
	switch (iInput)
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
	case 4:
		SellItem();
		break;
	default:
		CSceneMgr::GetInst()->BackScene();
		break;
	}
}

void CShop::Render()
{
}

void CShop::Exit()
{
	system("cls");
	cout << "���� ���� : ������ �ð��� ����? �� ���� ���� �� �� ��� ����." << endl;
	system("pause");
}
