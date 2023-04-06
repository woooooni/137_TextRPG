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

	if (m_tItem->strType == "公扁")   cout << "傍拜仿: " << m_tItem->iAtk;
	if (m_tItem->strType == "规绢备") cout << "眉仿: " << m_tItem->iHp;

	cout << "\n啊拜: " << m_tItem->iPrice << endl;
	cout << "===============================" << endl;
}
