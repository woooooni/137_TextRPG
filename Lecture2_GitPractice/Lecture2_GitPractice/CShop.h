#pragma once
#include "CScene.h"
#include "stdafx.h"
#include "CItemPack.h"
class CShop:public CScene
{
public:
	CShop();
	~CShop();
	//void		Set_Player(CEntity* pPlayer) { m_pPlayer = pPlayer; }
	//void		Set_Inven(CInventory* pInven) { m_pInventory = pInven; }


	void ShowItem(int);
	void BuyItem(/*CItem* pItem*/);
	void SellItem();
private:



	// CScene을(를) 통해 상속됨
	virtual void Enter() override;

	virtual void Update() override;

	virtual void Render() override;

	virtual void Exit() override;

	//CDummy* m_pDummyItem[(int)(ITEM_CODE::END)];
	//CPlayer* m_pDummyPlayer;
	//CItem* m_pDummyInven;
	vector<CItem*> vecItemList[(int)SHOP_LEVEL::END];

};

