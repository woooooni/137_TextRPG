#include "stdafx.h"
#include "CMace.h"


CMace::CMace()
{
	m_tItem->strName = "¸ÞÀÌ½º";
	m_tItem->eType = EQUIP_TYPE::WEAPON;
	m_tItem->eRare = ITEM_RARITY::NORMAL;
	m_tItem->iAtk = 10;
	m_tItem->iHp = 0;
	m_tItem->iPrice = 3000;
}


CMace::~CMace()
{
}
