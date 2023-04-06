#include "stdafx.h"
#include "CInventory.h"

<<<<<<< .merge_file_uuPBYe
=======
CInventory::CInventory()
{
}

>>>>>>> .merge_file_62PPmn
CInventory::~CInventory()
{
}

void CInventory::Init()
{
}

void CInventory::Render()
{
<<<<<<< .merge_file_uuPBYe
=======
	invenIter = m_vecItems.begin();
	for (; invenIter != m_vecItems.end(); ++invenIter) {
		(*invenIter)->Render();
	}
>>>>>>> .merge_file_62PPmn
}

void CInventory::Update()
{
}

void CInventory::Release()
{
}

<<<<<<< .merge_file_uuPBYe
void CInventory::AddItem(CItem * _pItem)
{
	m_vecItems.push_back(_pItem);
}
=======
void CInventory::AddItem(CItem * _pItem, int _iAmount = 1)
{
	_pItem->SetAmount(_iAmount);
	m_vecItems.push_back(_pItem);
}

void CInventory::UseItem(int _iIndex)
{
	if (_iIndex < m_vecItems.size()) {
		if (m_vecItems[_iIndex]->GetItem()->strType == "소모품") {
			// 플레이어 피 회복
			m_vecItems[_iIndex]->SetAmount(-1);

			if (m_vecItems[_iIndex]->GetAmount() <= 0) {
				m_vecItems.erase(m_vecItems.begin() + _iIndex);
			}
		}
		else {
			// 장비 착용

			// 지우기
			m_vecItems.erase(m_vecItems.begin() + _iIndex);
		}
	}
}
>>>>>>> .merge_file_62PPmn
