#include "stdafx.h"
#include "CMonster.h"
#include "CAttackObj.h"

CMonster::CMonster(string _strName, int _iMoney)
	:CAttackObj(_strName, OBJECT_TYPE::MONSTER)
{
	m_iMoney = _iMoney;
}


CMonster::~CMonster()
{

}
