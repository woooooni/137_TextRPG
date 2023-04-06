#pragma once
#include "CItem.h"
#include "CEquip.h"
#include "CPlayer.h"

class CEquip;
class CInventory
{
public:
	CInventory();
	~CInventory();

private:
	vector<CItem*> m_vecItems;
	vector<CItem*>::iterator invenIter;
	CEquip* m_pEquip;
	CPlayer* m_pPlayer;

public:
	void Set_Player(CPlayer* _pPlayer) { m_pPlayer = _pPlayer; }
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

struct tagSort {
	bool operator ()(CItem* a, CItem* b) {
		return a->GetItem()->strType < b->GetItem()->strType;
	}
};
