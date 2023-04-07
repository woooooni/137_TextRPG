#include "stdafx.h"
#include "CWarBow.h"


CWarBow::CWarBow()
{
	m_tItem->strName = "¿öº¸¿ì";
	m_tItem->eType = EQUIP_TYPE::WEAPON;
	m_tItem->eRare = ITEM_RARITY::UNIQUE;
	m_tItem->iAtk = 10;
	m_tItem->iHp = 0;
	m_tItem->iPrice = 3000;
}


CWarBow::~CWarBow()
{
}
