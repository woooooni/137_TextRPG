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

void CEquip::Unequip_Item(CItem* _pItem)
{
  m_iter = m_mapEquip.find(_pItem->GetItem()->strDetailType);
  m_mapEquip.erase(m_iter);
  m_EqInven->AddItem(_pItem, 1);
  m_pEqPlayer->Reflect_Stat(_pItem, true);
}

void CEquip::Unequip_All()
{
	for (m_iter = m_mapEquip.begin(); m_iter != m_mapEquip.end(); ++m_iter)
	{
		m_EqInven->AddItem(m_iter->second, 1);
		m_pEqPlayer->Reflect_Stat(m_iter->second, true);
	}

	m_mapEquip.clear();
}
