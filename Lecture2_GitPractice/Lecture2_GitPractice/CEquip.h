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

public:
	void Equip_Item(CItem* _pItem);
	void Unequip_Item(CItem* _pItem);


private:
<<<<<<< HEAD
	map<string, CItem*> mapEquip;
	map<string, CItem*>::iterator iter;
=======
	map<string, CItem*> m_mapEquip;
	map<string, CItem*>::iterator m_iter;
	CPlayer*	 m_pEqPlayer;
	CInventory*  m_EqInven;
>>>>>>> dff3d02a47d9f321c1e661a63983fda99f74138c
};

