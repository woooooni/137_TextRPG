#include "stdafx.h"
#include "CInventory.h"
#include "CEquip.h"
#include "CPlayer.h"
#include <algorithm>

CInventory::~CInventory()
{
	Safe_Delete(m_pEquip);
}

void CInventory::Init()
{
}

void CInventory::Render()
{
	invenIter = m_vecItems.begin();
	for (; invenIter != m_vecItems.end(); ++invenIter) {
		(*invenIter)->Render();
	}

	sort(m_vecItems.begin(), m_vecItems.end(), tagSort());
}

void CInventory::Update()
{
}

void CInventory::Release()
{
}

void CInventory::AddItem(CItem * _pItem, int _iAmount)
{
	_pItem->SetAmount(_iAmount);
	m_vecItems.push_back(_pItem);
}

void CInventory::UseItem(int _iIndex)
{
	isEquip = false;
	if (_iIndex < m_vecItems.size()) {
		if (m_vecItems[_iIndex]->GetItem()->eType == EQUIP_TYPE::NONEQUIP) {
			// 플레이어 피 회복
			m_pPlayer->Reflect_Stat(m_vecItems[_iIndex], false);

			m_vecItems[_iIndex]->SetAmount(-1);
			// 개수 0개되면 지우기
			if (m_vecItems[_iIndex]->GetAmount() <= 0) {
				m_vecItems.erase(m_vecItems.begin() + _iIndex);
			}
		}
		else {
			// 장비 착용
			isEquip = m_pEquip->Equip_Item(m_vecItems[_iIndex]);
			if (isEquip) {
				Safe_Delete(m_vecItems[_iIndex]);
				m_vecItems.erase(m_vecItems.begin() + _iIndex);
			}
		}
	}
}
