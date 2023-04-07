#pragma once
#include "CItem.h"

class CEquip;
class CPlayer;

class CInventory
{
public:
	CInventory() :isEquip(0) {

	}
	~CInventory();

private:
	vector<CItem*> m_vecItems;
	vector<CItem*>::iterator invenIter;
	CEquip* m_pEquip;
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
		return _item1->GetItem()->eType > _item2->GetItem()->eType;
	}
};

