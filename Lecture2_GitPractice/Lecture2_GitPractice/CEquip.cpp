#include "stdafx.h"
#include "CEquip.h"
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
}

void CEquip::Render()
{
	if (m_mapEquip.empty())
	{
		cout << "���� ������ ��� �����ϴ�" << endl;
		system("pause");
		return;
	}

	else
	{
		for (auto iter : m_mapEquip)
		{
			cout << "��񽽷� : " << iter.first << '\t' << "�̸� : " << iter.second->GetItem()->strName << endl;
			cout << "============================" << endl;
		}
	}

}

void CEquip::Release()
{
}

void CEquip::Equip_Item(CItem* _pItem)
{
	if (!_pItem)
		return;

	m_iter = m_mapEquip.find(_pItem->GetItem()->strDetailType);

	if (m_iter != m_mapEquip.end()) 
	{
		cout << "�̹� ������ ��񽽷��Դϴ�" << endl;
		return;
	}
	else 
	{
		m_mapEquip.insert({ _pItem->GetItem()->strDetailType, _pItem });
		// ��� ������ �÷��̾� �ɷ�ġ ��ȭ
	}
}

void CEquip::Unequip_Item(CItem* _pItem)
{
  m_iter = m_mapEquip.find(_pItem->GetItem()->strName);
  m_mapEquip.erase(m_iter);
  // ��� ������ �÷��̾� �ɷ�ġ ��ȭ
}
