#include "stdafx.h"
#include "CMace.h"


CMace::CMace()
{
	m_tItem->strName = "메이스";
	m_tItem->strType = "무기";
	m_tItem->strDetailType = "둔기";
	m_tItem->strRare = "노말";
	m_tItem->iAtk = 10;
	m_tItem->iHp = 0;
	m_tItem->iPrice = 3000;
}


CMace::~CMace()
{
}
