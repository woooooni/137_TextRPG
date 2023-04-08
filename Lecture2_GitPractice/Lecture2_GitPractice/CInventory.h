#pragma once
// #include "CGameCore.h"
#include "CItem.h"
#include "CItemPack.h"

struct EqualName 
{
	EqualName(string _strName) : m_strName(_strName) {}
	bool operator()(CItem* _pItem) const {
		return _pItem->GetItem().strName == m_strName;
	}
	string m_strName;
};

class CPlayer;

class CInventory
{
public:
	CInventory();
	~CInventory();

private:
	vector<CItem*> m_vecItems;
	vector<CItem*>::iterator m_invenIter;
	CPlayer* m_pPlayer;
	CItem m_item;
	bool isEquip;

public:
	void SetPlayer(CPlayer* _pPlayer) { m_pPlayer = _pPlayer; }
public:
	void Init();
	void Render();
	void Update();
	void Release();

public:
	vector<CItem*> GetInven() { return m_vecItems; }
public:
	void AddItem(CItem* _pItem, int _iAmount);
	void UseItem(int _iIndex);
	bool DecreaseItem(int _iIndex, int _iAmount);
};



struct tagSort{
	bool operator()(CItem* _item1, CItem* _item2) {
		return _item1->GetItem().eType > _item2->GetItem().eType;
	}
};

