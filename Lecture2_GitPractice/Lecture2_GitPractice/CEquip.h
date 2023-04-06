#pragma once
#include "CInventory.h"

class CInventory;

class CEquip
{
public:
	explicit CEquip();
	~CEquip();

public:
	void Initialize();
	void Update();
	void Render();
	void Release();

	void Equip_Item(CItem* _pItem);
	void Unequip_Item(CItem* _pItem);


private:
	map<string, CItem*> mapEquip;
	map<string, CItem*>::iterator iter;
};

