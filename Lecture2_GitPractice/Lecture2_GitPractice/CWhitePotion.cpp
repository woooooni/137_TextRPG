#include "stdafx.h"
#include "CWhitePotion.h"


CWhitePotion::CWhitePotion()
{
	m_tItem->strName = "�Ͼ�����";
	m_tItem->eType = EQUIP_TYPE::NONEQUIP;
	m_tItem->eRare = ITEM_RARITY::EPIC;
	m_tItem->iHp = 50;
	m_tItem->iPrice = 320;
}


CWhitePotion::~CWhitePotion()
{
}
