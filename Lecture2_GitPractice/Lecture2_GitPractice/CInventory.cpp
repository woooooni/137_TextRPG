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
	invenIter = m_vecItems.begin();

	for (; invenIter != m_vecItems.end();) {
		if ((*invenIter)->GetAmount() <= 0) 
			invenIter = m_vecItems.erase(invenIter);

		else 
			invenIter++;
	}

}

void CInventory::Release()
{
}

void CInventory::AddItem(CItem * _pItem, int _iAmount = 1)
{
	_pItem->SetAmount(_iAmount);
	m_vecItems.push_back(_pItem);
	Update();
}

void CInventory::UseItem(int _iIndex)
{
	if (_iIndex < m_vecItems.size()) {
		if (m_vecItems[_iIndex]->GetItem()->strType == "포션") {

		}
		else {
			// 장비 장착은 누가?
			// 포션은 내가 하고
		}
	}
	
}
