#include "stdafx.h"
// #include "CGameCore.h"
#include "CInventory.h"
#include "CEquip.h"
#include "CPlayer.h"
#include <algorithm>

CInventory::CInventory()
	:isEquip(0)
{
	m_vecItems.push_back(new CRedPotion());
	m_vecItems.push_back(new CMapleCloth());
	m_vecItems.push_back(new CFruitDagger());
	m_vecItems.push_back(new CWarBow());
	// m_pPlayer = CGameCore::GetInst()->GetPlayer();
}

CInventory::~CInventory()
{
}

void CInventory::Init()
{
}

void CInventory::Render()
{
	int i = 1;
	cout << "============== 인벤토리 ==============" << endl;
	if (!m_vecItems.empty()) {
		sort(m_vecItems.begin(), m_vecItems.end(), tagSort());
		invenIter = m_vecItems.begin();
		for (; invenIter != m_vecItems.end(); ++invenIter) {
			cout << i << ". ";
			(*invenIter)->Render();
		}
	}
}

void CInventory::Update()
{
	int iInput = 0;
	while (true) {
		system("cls");
		m_pPlayer->Get_Equip()->Render();
		m_pPlayer->Render();
		Render();
		cout << "사용할 아이템 번호 입력 : ";
		cin >> iInput;
	}
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
		if (m_vecItems[_iIndex]->GetItem().eType == EQUIP_TYPE::NONEQUIP) {
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
			isEquip = m_pPlayer->Get_Equip()->Equip_Item(m_vecItems[_iIndex]);
			if (isEquip) {
				Safe_Delete(m_vecItems[_iIndex]);
				m_vecItems.erase(m_vecItems.begin() + _iIndex);
			}
		}
	}
}
