#include "stdafx.h"
#include "CWhitePotion.h"


CWhitePotion::CWhitePotion()
{
	m_tItem->strName = "하얀포션";
	m_tItem->strType = "소모품";
	// m_tItem->strDetailType = "포션";
	m_tItem->strRare = "노말";
	m_tItem->iHp = 50;
	m_tItem->iPrice = 320;
}


CWhitePotion::~CWhitePotion()
{
}
