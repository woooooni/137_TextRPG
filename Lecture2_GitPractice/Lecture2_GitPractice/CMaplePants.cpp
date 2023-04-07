#include "stdafx.h"
#include "CMaplePants.h"


CMaplePants::CMaplePants()
{
	m_tItem->strName = "메이플바지";
	m_tItem->eType = EQUIP_TYPE::BOTTOM;
	m_tItem->eRare = ITEM_RARITY::EPIC;
	m_tItem->iHp = 20;
	m_tItem->iPrice = 6000;
}


CMaplePants::~CMaplePants()
{
}