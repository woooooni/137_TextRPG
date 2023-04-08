#include "stdafx.h"
#include "CEquip.h"
#include "CPlayer.h"
#include "CInventory.h"
#include "CItem.h"


CEquip::CEquip() : m_pEqPlayer(nullptr), m_iter(m_mapEquip.begin())
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
	int iInput;

	while (true)
	{
		system("cls");

		Render();
		m_pEqPlayer->Render();
		m_pEqPlayer->Get_Inventory()->Render();

		cout << "1. [�������]" << "  2. [�����ü����]" << "  3. [���ư���]" << endl;
		cin >> iInput;
		cout << endl;

		switch (iInput)
		{
		case 1:
			Unequip_Item();
			break;
		case 2:
			Unequip_All();
			break;
		case 3:
			return;
		default:
			break;
		}

		system("pause");
	}

	
}

void CEquip::Render()
{
	int iSloat = 1;

	if (m_mapEquip.empty())
	{
		cout << "[���� ������ ��� �����ϴ�]" << endl;
		cout << endl;
	}
	else
	{
		cout << "[���� ������ ���]" << endl;
		for (m_iter = m_mapEquip.begin(); m_iter != m_mapEquip.end(); ++m_iter)
		{
			cout << "[" << iSloat << "]" <<" ��񽽷� : " << STR_EQUIPTYPE[(int)m_iter->first] << "\t�̸� : " << m_iter->second->GetItem().strName << endl;
			cout << "===============================" << endl;
			++iSloat;
		}
	}

}

void CEquip::Release()
{
}

bool CEquip::Equip_Item(CItem* _pItem)
{	
	m_iter = m_mapEquip.find(_pItem->GetItem().eType);

	if (m_iter != m_mapEquip.end()) 
	{
		cout << "�̹� ������ ��񽽷��Դϴ�" << endl;
		system("pause");
		cout << endl;
		return false;
	}
	else 
	{
		m_mapEquip.insert({ _pItem->GetItem().eType, _pItem });
		m_pEqPlayer->Reflect_Stat(_pItem, false);
		return true;
	}
}

void CEquip::Unequip_Item()
{
	int iInput;
	
	if (m_mapEquip.empty())
	{
		cout << "������ ��� �����ϴ�" << endl;
		cout << endl;
		return;
	}

	while (true)
	{
		cout << "[������ ��� �����ϼ���] : ";
		cin >> iInput;
		cout << endl;

		if (iInput < 5)
		{
			m_iter = m_mapEquip.begin();

			for (int i = 0; i < (iInput - 1); ++i)
			{
				++m_iter;
			}

			m_pEqPlayer->Get_Inventory()->AddItem(m_iter->second, 0);
			m_pEqPlayer->Reflect_Stat(m_iter->second, true);
			if (m_iter->second != nullptr) {
				delete m_iter->second;
				m_iter->second = nullptr;
			}
			m_mapEquip.erase(m_iter);
		
			cout << "������� ����" << endl;

			return;
		}	
	}
	
}

void CEquip::Unequip_All()
{
	if (m_mapEquip.empty())
	{
		cout << "��������� �����ϴ�" << endl;
		cout << endl;
		return;
	}
	else 
	{
		for (m_iter = m_mapEquip.begin(); m_iter != m_mapEquip.end(); ++m_iter)
		{
			m_pEqPlayer->Get_Inventory()->AddItem(m_iter->second, 0);
			m_pEqPlayer->Reflect_Stat(m_iter->second, true);
			if (m_iter->second != nullptr) {
				delete m_iter->second;
				m_iter->second = nullptr;
			}
		}
		m_mapEquip.clear();
	}
	
	if (m_mapEquip.empty()) cout << "�����ü���� ����" << endl;
	else cout << "�����ü���� ����" << endl;
	
}
