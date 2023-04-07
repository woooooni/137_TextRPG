#pragma once
// #include "CGameCore.h"
#include "CItem.h"
#include "CItemPack.h"

class CPlayer;

class CInventory
{
public:
	CInventory();
	~CInventory();

private:
	vector<CItem*> m_vecItems;
	vector<CItem*>::iterator invenIter;
	CPlayer* m_pPlayer;
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
};



struct tagSort{
	bool operator()(CItem* _item1, CItem* _item2) {
		return _item1->GetItem().eType > _item2->GetItem().eType;
	}
};

