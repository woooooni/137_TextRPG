#include "stdafx.h"
#include "CWhitePotion.h"


CWhitePotion::CWhitePotion()
{
	m_tItem->strName = "하얀포션";
	m_tItem->strType = "포션";
	m_tItem->strRare = "노말";
	m_tItem->iRecovery = 50;
	m_tItem->iPrice = 360;
}


CWhitePotion::~CWhitePotion()
{
}
