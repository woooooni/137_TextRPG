#include "stdafx.h"
#include "CWoodWand.h"


CWoodWand::CWoodWand()
{
	m_tItem->strName = "우드완드";
	m_tItem->strType = "무기";
	m_tItem->strRare = "노말";
	m_tItem->iAtk = 5;
	m_tItem->iHp = 0;
	m_tItem->iPrice = 1500;
}


CWoodWand::~CWoodWand()
{
}
