#include "stdafx.h"
#include "CFruitDagger.h"


CFruitDagger::CFruitDagger()
{
	m_tItem->strName = "후르츠대거";
	m_tItem->strType = "무기";
	m_tItem->strDetailType = "단검";
	m_tItem->strRare = "노말";
	m_tItem->iAtk = 8;
	m_tItem->iHp = 0;
	m_tItem->iPrice = 2000;
}


CFruitDagger::~CFruitDagger()
{
}
