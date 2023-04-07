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
	// ������ ���
	bool	Equip_Item(CItem* _pItem);

	// ��������� ����
	void	Unequip_Item();

	// ��������� ��ü����;
	void	Unequip_All();

	// �÷��̾�� �κ� ��
	void	Set_EqPlayer(CPlayer* _pPlayer)  { m_pEqPlayer = _pPlayer; }

private:
	map<EQUIP_TYPE, CItem*>				m_mapEquip;
	map<EQUIP_TYPE, CItem*>::iterator	m_iter;
	CPlayer*		m_pEqPlayer;
};

