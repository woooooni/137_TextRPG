#include "stdafx.h"
#include "COrangePotion.h"


COrangePotion::COrangePotion()
{
	m_tItem->strName = "��Ȳ����";
	m_tItem->eType = EQUIP_TYPE::NONEQUIP;
	m_tItem->eRare = ITEM_RARITY::NORMAL;
	m_tItem->iHp = 30;
	m_tItem->iPrice = 160;
}


COrangePotion::~COrangePotion()
{
}
