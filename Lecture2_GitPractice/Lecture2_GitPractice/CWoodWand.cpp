#include "stdafx.h"
#include "CWoodWand.h"


CWoodWand::CWoodWand()
{
	m_tItem->strName = "우드완드";
	m_tItem->eType = EQUIP_TYPE::WEAPON;
	m_tItem->eRare = ITEM_RARITY::NORMAL;
	m_tItem->iAtk = 5;
	m_tItem->iHp = 0;
	m_tItem->iPrice = 1500;
}


CWoodWand::~CWoodWand()
{
}
