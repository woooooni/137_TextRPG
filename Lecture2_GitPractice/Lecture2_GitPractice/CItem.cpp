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

	if (m_tItem->strType == "����")   cout << "���ݷ�: " << m_tItem->iAtk;
	if (m_tItem->strType == "��") cout << "ü��: " << m_tItem->iHp;

	cout << "\n����: " << m_tItem->iPrice << endl;
	cout << "===============================" << endl;
}
