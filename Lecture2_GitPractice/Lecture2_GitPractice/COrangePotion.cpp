#include "stdafx.h"
#include "COrangePotion.h"


COrangePotion::COrangePotion()
{
	m_tItem->strName = "주황포션";
	m_tItem->strType = "포션";
	m_tItem->strRare = "노말";
	m_tItem->iRecovery = 30;
	m_tItem->iPrice = 160;
}


COrangePotion::~COrangePotion()
{
}
