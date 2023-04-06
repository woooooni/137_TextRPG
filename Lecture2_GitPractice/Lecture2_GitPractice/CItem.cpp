#include "stdafx.h"
#include "CItem.h"


CItem::CItem()
{
}


CItem::~CItem()
{
}

void CItem::Render()
{
	cout << m_tItem->strName << "(" << m_tItem->strRare << ")" << "\t" << m_tItem->strType << endl;

	if (m_tItem->strType == "무기")   cout << "공격력: " << m_tItem->iAtk;
	if (m_tItem->strType == "방어구") cout << "체력: " << m_tItem->iHp;

	cout << "\n가격: " << m_tItem->iPrice << endl;
	cout << "===============================" << endl;
}
