#include "stdafx.h"
#include "CShop.h"
#include "CSceneMgr.h"
#include "Template.h"

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
	m_vecItemList[(int)SHOP_LEVEL::BEGGINER].push_back(pItem);

	pItem = new CRedPotion;
	m_vecItemList[(int)SHOP_LEVEL::BEGGINER].push_back(pItem);

	pItem = new CWoodWand;
	m_vecItemList[(int)SHOP_LEVEL::MIDDLE].push_back(pItem);

	pItem = new CMaplePants;
	m_vecItemList[(int)SHOP_LEVEL::MIDDLE].push_back(pItem);

	pItem = new COrangePotion;
	m_vecItemList[(int)SHOP_LEVEL::MIDDLE].push_back(pItem);

	pItem = new CMapleHat;
	m_vecItemList[(int)SHOP_LEVEL::SENIOR].push_back(pItem);

	pItem = new CMapleCloth;
	m_vecItemList[(int)SHOP_LEVEL::SENIOR].push_back(pItem);

	pItem = new CFruitDagger;
	m_vecItemList[(int)SHOP_LEVEL::SENIOR].push_back(pItem);

	pItem = new CWarBow;
	m_vecItemList[(int)SHOP_LEVEL::SENIOR].push_back(pItem);

	pItem = new CWhitePotion;
	m_vecItemList[(int)SHOP_LEVEL::SENIOR].push_back(pItem);
}

void CShop::ShowItem(int _iLevel)
{

	int iInput(0);
	while (true)
	{
		int i = 1;

		system("cls");
		m_pPlayer->Render();
		cout << "���� ���� : �������! �����͵鸸 ��Ƴ����ϴ�. (0. ������)\n" << endl;
		vector<CItem*>::iterator iter = m_vecItemList[_iLevel].begin();
		for (iter; iter != m_vecItemList[_iLevel].end(); iter++)
		{
			cout << "[" << i << "]. ";
			(*iter)->Render();
			++i;
		}

		cout << "\n�������� ���϶� : ";
		cin >> iInput;

		if (m_vecItemList[_iLevel].size() < iInput)
		{
			system("cls");
			cout << "���� ���� : �̺� �ű� ���� �������!." << endl;
			system("pause");

		}
		else if (iInput == 0)
			return;
		else
		{
			CItem* pItem = m_vecItemList[_iLevel][iInput - 1];
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

		int iPrice = m_pPlayer->Get_Inventory()->GetInven().at(iInput)->GetItem().iPrice *iAmount;
		
		bool bSuccess = m_pPlayer->Get_Inventory()->DecreaseItem(iInput, iAmount );
		if (bSuccess == true)
		{
			m_pPlayer->Set_Gold(m_pPlayer->Get_Stat().m_iGold + iPrice);
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
	for (int i = 0; i < (int)SHOP_LEVEL::END; ++i)
	{
		Safe_Delete_Vec(m_vecItemList[i]);
	}

	system("cls");
	cout << "���� ���� : ������ �ð��� ����? �� ���� ���� �� �� ��� ����." << endl;
	system("pause");
}
