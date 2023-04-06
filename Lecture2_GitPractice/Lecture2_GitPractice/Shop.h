#pragma once
#include "CScene.h"
#include "stdafx.h"

class CShop:public CScene
{
public:
	CShop();
	~CShop();
	void Initialize();
	void Update();
	void Release();
	void ShowItem(int);
	void BuyItem(/*CItem* pItem*/);
	void SellItem();
private:

	// CScene을(를) 통해 상속됨
	virtual void Enter() override;
	virtual void Render() override;
	virtual void Exit() override;
	//CDummy* m_pDummyItem[(int)(ITEM_CODE::END)];
	//CDummy* m_pDummyPlayer;
};

