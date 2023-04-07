#pragma once
#include "CScene.h"
#include "stdafx.h"
#include "CItemPack.h"
#include "CPlayer.h"
#include "CItemPack.h"
#include "CInventory.h"

class CShop :public CScene
{
public:
	CShop();
	~CShop();
	void		SetPlayer(CPlayer* pPlayer) { m_pPlayer = pPlayer; }
	void		SetInven(CInventory* pInven) { m_pInven = pInven; }


	void ShowItem(int);
	void BuyItem(CItem* pItem);
	void SellItem();


public:
	// CScene을(를) 통해 상속됨
	virtual void Enter() override;

	virtual void Update() override;

	virtual void Render() override;

	virtual void Exit() override;

	
	CPlayer* m_pPlayer;
	CInventory* m_pInven;
	vector<CItem*> vecItemList[(int)SHOP_LEVEL::END];

};

