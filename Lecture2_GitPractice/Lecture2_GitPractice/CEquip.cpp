#include "stdafx.h"
#include "CEquip.h"
#include "CItem.h"


CEquip::CEquip()
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
	if (!mapEquip.empty())
	{
		if (iter->second != nullptr) cout << "����� ���� : " << iter->second->GetItem()->strName << endl; ++iter;
		if (iter->second != nullptr) cout << "����� �� : " << iter->second->GetItem()->strName << endl; ++iter;
		if (iter->second != nullptr) cout << "����� �Ź� : " << iter->second->GetItem()->strName << endl; ++iter;
		if (iter->second != nullptr) cout << "����� ���� : " << iter->second->GetItem()->strName << endl;
		cout << "=============================" << endl;
	}

}

void CEquip::Release()
{
}

void CEquip::Equip_Item(CItem* _pItem)
{
	mapEquip.insert({ _pItem->GetItem()->strName, _pItem });
}

void CEquip::Unequip_Item(CItem* _pItem)
{

  iter = mapEquip.find(_pItem->GetItem()->strName);
  mapEquip.erase(iter);
  m_iter = m_mapEquip.find(_pItem->GetItem()->strName);
  m_mapEquip.erase(m_iter);
  m_EqInven->AddItem(_pItem, 1);
  // ��� ������ �÷��̾� �ɷ�ġ ��ȭ

}
