#pragma once
#include "CInventory.h"
#include "CPlayer.h"

class CInventory;
class CPlayer;

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
	bool Equip_Item(CItem* _pItem);
	void Unequip_Item(CItem* _pItem);
	void Unequip_All() { m_mapEquip.clear(); }

private:
	map<string, CItem*> m_mapEquip;
	map<string, CItem*>::iterator m_iter;
	CPlayer*	 m_pEqPlayer;
	CInventory*  m_EqInven;
};

