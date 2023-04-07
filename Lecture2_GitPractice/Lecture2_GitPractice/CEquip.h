#pragma once
#include "CPlayer.h"
#include "CInventory.h"

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
	void	Unequip_Item();

	// 착용아이템 전체해제;
	void	Unequip_All();

	// 플레이어랑 인벤 셋
	void	Set_EqPlayer(CPlayer* _pPlayer)  { m_pEqPlayer = _pPlayer; }

private:
	map<EQUIP_TYPE, CItem*>				m_mapEquip;
	map<EQUIP_TYPE, CItem*>::iterator	m_iter;
	CPlayer*		m_pEqPlayer;
};

