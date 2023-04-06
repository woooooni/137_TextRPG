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
		cout << "현재 장착한 장비가 없습니다" << endl;
		system("pause");
		return;
	}

	else
	{
		for (auto iter : m_mapEquip)
		{
			cout << "장비슬롯 : " << iter.first << '\t' << "이름 : " << iter.second->GetItem()->strName << endl;
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
		cout << "이미 장착한 장비슬롯입니다" << endl;
		return;
	}
	else 
	{
		m_mapEquip.insert({ _pItem->GetItem()->strDetailType, _pItem });
		// 장비 장착시 플레이어 능력치 변화
	}
}

void CEquip::Unequip_Item(CItem* _pItem)
{
  m_iter = m_mapEquip.find(_pItem->GetItem()->strName);
  m_mapEquip.erase(m_iter);
  // 장비 해제시 플레이어 능력치 변화
}
