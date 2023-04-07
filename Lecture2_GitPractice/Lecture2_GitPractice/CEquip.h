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
	// ������ ���
	bool	Equip_Item(CItem* _pItem);

	// ��������� ����
	void	Unequip_Item(CItem* _pItem);

	// ��������� ��ü����;
	void	Unequip_All();

	// �÷��̾�� �κ� ��
	void	Set_EqPlayer(CPlayer* _pPlayer)  { m_pEqPlayer = _pPlayer; }
	void	Set_EqInven(CInventory* _pInven) { m_EqInven = _pInven; }

private:
	map<string, CItem*>				m_mapEquip;
	map<string, CItem*>::iterator	m_iter;
	CPlayer*						m_pEqPlayer;
	CInventory*						m_EqInven;
};

