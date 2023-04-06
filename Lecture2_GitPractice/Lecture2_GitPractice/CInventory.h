#pragma once
#include "Define.h"
#include "Struct.h"
#include "CItem.h"

class CEquip;
class CInventory
{
public:
	CInventory();
	~CInventory();

public:
	void Init();
	void Render();
	void Update();
	void Release();

public:
	void AddItem(CItem* _pItem, int _iAmount);
	void UseItem(int _iIndex);

private:
	vector<CItem*>				m_vecItems;
	vector<CItem*>::iterator	invenIter;
	CEquip*						m_pEquip;
};

