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
	explicit CShop();
	virtual  ~CShop();


public:
	void ShowItem(int);
	void BuyItem(CItem* pItem);
	void SellItem();

public:
	void SetPlayer(CPlayer* pPlayer) { m_pPlayer = pPlayer; }

public:
	// CScene을(를) 통해 상속됨
	virtual void Enter() override;

	virtual void Update() override;

	virtual void Render() override;

	virtual void Exit() override;

	CItem*		m_pItem;
	CPlayer*	m_pPlayer;
	
	vector<CItem*> m_vecItemList[(int)SHOP_LEVEL::END];

};

