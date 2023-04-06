#pragma once
#include "Define.h"
#include "Struct.h"
#include "CItem.h"

class CInventory
{
public:
	CInventory() : iAmount(0) {

	}
	~CInventory();

private:
	vector<CItem*> m_vecItems;
	vector<CItem*>::iterator invenIter;
	int iAmount;

public:
	void Init();
	void Render();
	void Update();
	void Release();

public:
	void AddItem(CItem* _pItem);
};

