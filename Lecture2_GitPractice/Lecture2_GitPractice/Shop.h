#pragma once
#include "Dummy.h"
#include "stdafx.h"

class CShop
{
public:
	CShop();
	~CShop();
	void Initialize();
	void Update();
	void Release();
	void ShowItem(int);
	void BuyItem(/*CItem* pItem*/);
private:
	//CDummy* m_pDummyItem[(int)(ITEM_CODE::END)];
	//CDummy* m_pDummyPlayer;
};

