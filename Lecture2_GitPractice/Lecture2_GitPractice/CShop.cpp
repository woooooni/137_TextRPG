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
	//빨주흰
	//메,완, 후&워
	//바지:에픽, 모자&옷: 레전
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
		cout << "상점 주인 : 어서오세요! 좋은것들만 모아놨습니다. (0. 나가기)\n" << endl;
		vector<CItem*>::iterator iter = m_vecItemList[_iLevel].begin();
		for (iter; iter != m_vecItemList[_iLevel].end(); iter++)
		{
			cout << "[" << i << "]. ";
			(*iter)->Render();
			++i;
		}

		cout << "\n사고싶은걸 말하라구 : ";
		cin >> iInput;

		if (m_vecItemList[_iLevel].size() < iInput)
		{
			system("cls");
			cout << "상점 주인 : 이봐 거긴 출입 금지라고!." << endl;
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
		cout << "구매할" << (_pItem->GetItem().strName) << "의 갯수를 선택하시오 :";
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
		cout<<"상점 주인 : 외상은 안돼!"<<endl;
		system("pause");
	}
	else
	{
		system("cls");
		m_pPlayer->Get_Inventory()->AddItem(_pItem, iInput);
		cout << "상점 주인 : 좋은 선택이군요! 아주 잘하셨어요!" << endl;
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

		cout << "판매할 아이템을 고르시오.(0. 나가기):" << endl;
		cin >> iInput;

		--iInput;
		if (0 > iInput)
			return;
		
		m_pPlayer->Get_Inventory()->GetInven().at(iInput);
		if (m_pPlayer->Get_Inventory()->GetInven().at(iInput)->GetItem().eType == EQUIP_TYPE::NONEQUIP)
		{
			system("cls");
			cout << "판매할 " << (m_pPlayer->Get_Inventory()->GetInven().at(iInput)->GetItem().strName) << "의 갯수를 선택하시오 :";
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
			cout << "상점 주인 : 좋은 물건이군. 좋은 값에 쳐드리지." << endl;
			system("pause");
		}

		else
		{
			system("cls");
			cout << "상점 주인 : 뭔가 오류가 난거 같아." << endl;
			system("pause");
		}
	}

}




void CShop::Update()
{
	int iInput(0);

	system("cls");

	cout << "1. 초급상점 2. 중급상점 3. 고오급상점 4. 판매 0. 전단계:";
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
	cout << "상점 주인 : 쇼핑할 시간이 없어? 다 끓인 차라도 한 잔 들고 가게." << endl;
	system("pause");
}
