#include "stdafx.h"
// #include "CGameCore.h"
#include "CInventory.h"
#include "CEquip.h"
#include "CPlayer.h"
#include <algorithm>




CInventory::CInventory()
	:isEquip(0)
{
	// m_pPlayer = CGameCore::GetInst()->GetPlayer();
}

CInventory::~CInventory()
{
	Release();



}

void CInventory::Init()
{

}

void CInventory::Render()
{
	int curY = 1, i = 1;
	int prevX = m_item.currentX();
	int prevY = m_item.currentY();
	m_item.gotoxy(50, 0);
	cout << "============== 인벤토리 ==============" << endl;
	if (!m_vecItems.empty()) {
		sort(m_vecItems.begin(), m_vecItems.end(), tagSort());
		m_invenIter = m_vecItems.begin();
		for (; m_invenIter != m_vecItems.end(); ++m_invenIter) {
			m_item.gotoxy(50, curY);
			cout << i << ". ";
			(*m_invenIter)->Render(i, curY);
			i += 1;
			curY += 3;
		}
	}
	m_item.gotoxy(prevX, prevY);
}

void CInventory::Update()
{
	int iInput = 0;
	while (true) 
	{
		system("cls");
 		m_pPlayer->Get_Equip()->Render();
		m_pPlayer->Render();
		Render();
		cout << "사용할 아이템 번호 입력 (돌아가기 : 0) : ";
		cin >> iInput;
		if (iInput == 0) break;
		UseItem(iInput - 1);
	}
}

void CInventory::Release()
{
	m_invenIter = m_vecItems.begin();
	for (; m_invenIter != m_vecItems.end(); ++m_invenIter) {
		if ((*m_invenIter) != nullptr) {
			delete (*m_invenIter);
			(*m_invenIter) = nullptr;
		}
	}
}

void CInventory::AddItem(CItem * _pItem, int _iAmount)
{
	if (_pItem->GetItem().eType == EQUIP_TYPE::NONEQUIP) 
	{
		m_invenIter = find_if(m_vecItems.begin(), m_vecItems.end(), EqualName(_pItem->GetItem().strName));
		if (m_invenIter != m_vecItems.end())
		{
			(*m_invenIter)->SetAmount(_iAmount);
		}
		else 
		{
			CItem* tempItem = new CItem(*_pItem);
			tempItem->SetAmount(_iAmount);
			m_vecItems.push_back(tempItem);
		}
	}
	else 
	{
		CItem* tempItem = new CItem(*_pItem);
		tempItem->SetAmount(_iAmount);
		m_vecItems.push_back(tempItem);
	}
}

void CInventory::UseItem(int _iIndex)
{
	isEquip = false;
	if (_iIndex < m_vecItems.size()) {
		if (m_vecItems[_iIndex]->GetItem().eType == EQUIP_TYPE::NONEQUIP) {
			// 플레이어 피 회복
			m_pPlayer->Reflect_Stat(m_vecItems[_iIndex], false);
			m_vecItems[_iIndex]->SetAmount(-1);
			// 개수 0개되면 지우기
			if (m_vecItems[_iIndex]->GetAmount() <= 0) {
				m_invenIter = m_vecItems.begin() + _iIndex;
				delete (*m_invenIter);
				(*m_invenIter) = nullptr;
				m_vecItems.erase(m_invenIter);
			}
		}
		else {
			// 장비 착용
			isEquip = m_pPlayer->Get_Equip()->Equip_Item(m_vecItems[_iIndex]);
			if (isEquip) {
				// Safe_Delete(m_vecItems[_iIndex]);
				m_vecItems.erase(m_vecItems.begin() + _iIndex);
			}
		}
	}
}

bool CInventory::DecreaseItem(int _iIndex, int _iAmount)
{
	if (_iIndex < m_vecItems.size()) {
		m_vecItems[_iIndex]->SetAmount(-_iAmount);
		if (m_vecItems[_iIndex]->GetAmount() <= 0) {
			m_vecItems.erase(m_vecItems.begin() + _iIndex);
		}
		return true;
	}
	else return false;
}
