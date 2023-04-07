#include "stdafx.h"
#include "CMapleCloth.h"


CMapleCloth::CMapleCloth()
{
	m_tItem->strName = "메이플맨투맨";
	m_tItem->eType = EQUIP_TYPE::TOP;
	m_tItem->eRare = ITEM_RARITY::LEGENDARY;
	m_tItem->iHp = 30;
	m_tItem->iPrice = 7000;
}


CMapleCloth::~CMapleCloth()
{
}