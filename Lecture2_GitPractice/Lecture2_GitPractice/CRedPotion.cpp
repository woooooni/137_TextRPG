#include "stdafx.h"
#include "CRedPotion.h"


CRedPotion::CRedPotion()
{
	m_tItem->strName = "»¡°£Æ÷¼Ç";
	m_tItem->eType = EQUIP_TYPE::NONEQUIP;
	m_tItem->eRare = ITEM_RARITY::NORMAL;
	m_tItem->iHp = 10;
	m_tItem->iPrice = 50;
}


CRedPotion::~CRedPotion()
{
}
