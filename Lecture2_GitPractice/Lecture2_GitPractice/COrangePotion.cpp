#include "stdafx.h"
#include "COrangePotion.h"


COrangePotion::COrangePotion()
{
	m_tItem.strName = "주황포션";
	m_tItem.eType = EQUIP_TYPE::NONEQUIP;
	m_tItem.eRare = ITEM_RARITY::RARE;
	m_tItem.iRecovery = 30;
	m_tItem.iPrice = 160;
}


COrangePotion::~COrangePotion()
{
}
