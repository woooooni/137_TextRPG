#include "stdafx.h"
#include "CItem.h"

CItem::~CItem()
{
}

void CItem::Render()
{
	cout << m_tItem.strName << "(" << STR_RARITY[(int)m_eRare] << ")" << "\t" 
		 << STR_EQUIPTYPE[(int)m_eType] << endl;

	if (m_tItem.eType == EQUIP_TYPE::WEAPON)   cout << "���ݷ�: " << m_tItem.iAtk;
	else if (m_tItem.eType == EQUIP_TYPE::END) cout << "ü��: " << m_tItem.iHp;

	cout << "\n����: " << m_tItem.iPrice << endl;
	cout << "===============================" << endl;
}
