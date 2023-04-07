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
	void	Initialize();
	void	Update();
	void	Render();
	void	Release();

public:
	// 아이템 장비
	bool	Equip_Item(CItem* _pItem);

	// 착용아이템 해제
	void	Unequip_Item(CItem* _pItem);

	// 착용아이템 전체해제;
	void	Unequip_All();

	// 플레이어랑 인벤 셋
	void	Set_EqPlayer(CPlayer* _pPlayer)  { m_pEqPlayer = _pPlayer; }
	void	Set_EqInven(CInventory* _pInven) { m_EqInven = _pInven; }

private:
	map<string, CItem*>				m_mapEquip;
	map<string, CItem*>::iterator	m_iter;
	CPlayer*						m_pEqPlayer;
	CInventory*						m_EqInven;
};

