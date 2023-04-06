#include "stdafx.h"
#include "CInventory.h"

CInventory::CInventory()
{
}

CInventory::~CInventory()
{
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
	if (_iIndex < m_vecItems.size()) {
		if (m_vecItems[_iIndex]->GetItem()->strType == "�Ҹ�ǰ") {
			// �÷��̾� �� ȸ��
			m_vecItems[_iIndex]->SetAmount(-1);

			if (m_vecItems[_iIndex]->GetAmount() <= 0) {
				m_vecItems.erase(m_vecItems.begin() + _iIndex);
			}
		}
		else {
			// ��� ����
			// m_pEquip->Equip_Item(m_vecItems[_iIndex]);
			// �����
			m_vecItems.erase(m_vecItems.begin() + _iIndex);
		}
	}
}
