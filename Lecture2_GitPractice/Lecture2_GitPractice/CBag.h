#pragma once
#include "CInventory.h"
#include "CEquip.h"
#include "CPlayer.h"

class CBag
{
public:
	CBag();
	~CBag();

private:
	CPlayer* m_pPlayer;
	CInventory* m_pInven;
	CEquip* m_pEquip;

public:
	void SetPlayer(CPlayer* _pPlayer) { m_pPlayer = _pPlayer; }
	void SetInven(CInventory* _pInven) { m_pInven = _pInven; }
	void SetEquio(CEquip* _pEquip) { m_pEquip = _pEquip; }
public:
	void Init();
	void Update();
	void Render();
	void Release();
};

