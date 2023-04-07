#include "stdafx.h"
#include "CFruitDagger.h"


CFruitDagger::CFruitDagger()
{
	m_tItem.strName = "ÈÄ¸£Ã÷´ë°Å";
	m_tItem.eType = EQUIP_TYPE::WEAPON;
	m_tItem.eRare = ITEM_RARITY::UNIQUE;
	m_tItem.iAtk = 8;
	m_tItem.iHp = 0;
	m_tItem.iPrice = 2000;
}


CFruitDagger::~CFruitDagger()
{
}
