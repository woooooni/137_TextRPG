#include "stdafx.h"
#include "CEquip.h"
#include "CItem.h"


CEquip::CEquip() : m_pEqPlayer(nullptr), m_EqInven(nullptr), m_iter(m_mapEquip.begin())
{
}

CEquip::~CEquip()
{
}

void CEquip::Initialize()
{
}

void CEquip::Update()
{
	// 이게 필요한지 모르겠음
	//int iInput;

	//while (true)
	//{
	//	system("cls");

	//	Render();

	//	cout << "1. [장비해제]" << '\t' << "2. [장비전체해제]" << "3. [나가기]" << endl;
	//	cin >> iInput;

	//	switch (iInput)
	//	{
	//	case 1:
	//		Unequip_Item();
	//		break;
	//	case 2:
	//		Unequip_All();
	//		break;
	//	default:
	//		break;
	//	}

	//	system("pause");
	//}

	//
}

void CEquip::Render()
{
	if (m_mapEquip.empty())
	{
		cout << "[현재 장착한 장비가 없습니다]" << endl;
	}
	else
	{
		cout << "[현재 장착한 장비]" << endl;
		for (m_iter = m_mapEquip.begin(); m_iter != m_mapEquip.end(); ++m_iter)
		{
			cout << "장비슬롯 : " << m_iter->first << '\t' << "이름 : " << m_iter->second->GetItem()->strName << endl;
			cout << "============================" << endl;
		}
	}

}

void CEquip::Release()
{
}

bool CEquip::Equip_Item(CItem* _pItem)
{
	if (!_pItem)
		return;

	m_iter = m_mapEquip.find(_pItem->GetItem()->strDetailType);

	if (m_iter != m_mapEquip.end()) 
	{
		cout << "이미 장착한 장비슬롯입니다" << endl;
		return false;
	}
	else 
	{
		m_mapEquip.insert({ _pItem->GetItem()->strDetailType, _pItem });
		m_pEqPlayer->Reflect_Stat(_pItem, false);
		return true;
	}
}

void CEquip::Unequip_Item()
{
	int iInput;
	
	if (m_mapEquip.empty())
	{
		cout << "해제할 장비가 없습니다" << endl;
		return;
	}

	while (true)
	{
		system("cls");

		Render();

		cout << "[해제할 장비를 선택하세요]";
		cout << "1. [모자]  2.[상의]  3.[하의]  4.[무기] : ";
		cin >> iInput;

		if (iInput < 5)
		{
			for (int i = 0; i < (iInput - 1); ++i)
			{
				++m_iter;
			}

			m_EqInven->AddItem(m_iter->second, 1);
			m_pEqPlayer->Reflect_Stat(m_iter->second, true);
			m_mapEquip.erase(m_iter);

			return;
		}	

		system("pause");
	}
	
}

void CEquip::Unequip_All()
{
	if (m_mapEquip.empty())
	{
		cout << "해제할장비가 없습니다" << endl;
		return;
	}
	else 
	{
		for (m_iter = m_mapEquip.begin(); m_iter != m_mapEquip.end(); ++m_iter)
		{
			m_EqInven->AddItem(m_iter->second, 1);
			m_pEqPlayer->Reflect_Stat(m_iter->second, true);
		}
		m_mapEquip.clear();
	}
	
	if (m_mapEquip.empty()) cout << "장비전체해제 성공" << endl;
	else cout << "장비전체해제 실패" << endl;
	
}
