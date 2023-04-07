#include "stdafx.h"
#include "CMapleHat.h"


CMapleHat::CMapleHat()
{
	m_tItem->strName = "메이플모자";
	m_tItem->eType = EQUIP_TYPE::HAT;
	m_tItem->eRare = ITEM_RARITY::RARE;
	m_tItem->iAtk = 0;
	m_tItem->iHp = 10;
	m_tItem->iPrice = 5000;
}


CMapleHat::~CMapleHat()
{
}