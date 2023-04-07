#pragma once
#include "Define.h"
#include "Struct.h"
#include "CItem.h"

class CEquip;
class CPlayer;

class CInventory
{
private:
	CPlayer*					m_pPlayer;
	vector<CItem*>				m_vecItems;
	vector<CItem*>::iterator	invenIter;
	CEquip*						m_pEquip;

public:
	CInventory();
	~CInventory();

public:
	void SetPlayer(CPlayer* _pPlayer) { m_pPlayer = _pPlayer; }

public:
	void Init();
	void Render();
	void Update();
	void Release();

public:
	void AddItem(CItem* _pItem, int _iAmount);
	void UseItem(int _iIndex);
};

struct tagSort{
	bool operator()(CItem* _item1, CItem* _item2) {
		return _item1->GetItem()->strType > _item2->GetItem()->strType;
	}

};

