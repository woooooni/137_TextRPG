#pragma once
#include "stdafx.h"
#include "Enum.h"

// æ∆¿Ã≈€
struct tagItem {
	string strName;
	EQUIP_TYPE eType;
	ITEM_RARITY eRare;

	int iAtk = 0;
	int iHp = 0;
	int iRecovery = 0;

	int iPrice = 0;
};

// Attack Object Stat
typedef struct tagStat 
{
	int m_iMaxHp;
	int m_iCurHp;
	int m_iStr;
	int m_iGold;

	tagStat()
		: m_iMaxHp(0), m_iCurHp(0), m_iStr(0), m_iGold(0) {}

	tagStat(const int& _iMaxHp, const int& _iCurHp, const int& _iStr, const int&_iGold)
		: m_iMaxHp(_iMaxHp), m_iCurHp(_iCurHp), m_iStr(_iStr), m_iGold(_iGold) {}

}ATTACK_OBJ_STAT;