#include "stdafx.h"
#include "CRedPotion.h"


CRedPotion::CRedPotion()
{
	m_tItem->strName = "빨간포션";
	m_tItem->strType = "소모품";
	// m_tItem->strDetailType = "포션";
	m_tItem->strRare = "노말";
	m_tItem->iHp = 10;
	m_tItem->iPrice = 50;
}


CRedPotion::~CRedPotion()
{
}
