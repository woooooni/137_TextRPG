#include "stdafx.h"
#include "CMaplePants.h"


CMaplePants::CMaplePants()
{
	m_tItem->strName = "�����ù���";
	m_tItem->eType = EQUIP_TYPE::BOTTOM;
	m_tItem->eRare = ITEM_RARITY::RARE;
	m_tItem->iHp = 20;
	m_tItem->iPrice = 6000;
}


CMaplePants::~CMaplePants()
{
}