#pragma once
#include "Define.h"
#include "Struct.h"
#include "CItem.h"

class CInventory
{
public:
	CInventory();
	~CInventory();

private:
	vector<CItem*> m_vecItems;
	vector<CItem*>::iterator invenIter;

public:
	void Init();
	void Render();
	void Update();
	void Release();

public:
	void AddItem(CItem* _pItem, int _iAmount = 1);
	void UseItem(int _iIndex);
};

