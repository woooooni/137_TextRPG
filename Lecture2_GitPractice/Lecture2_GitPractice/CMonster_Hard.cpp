#include "stdafx.h"
#include "CMonster_Hard.h"


CMonster_Hard::CMonster_Hard()
	: CMonster("�ϵ� ����")
{
}


CMonster_Hard::~CMonster_Hard()
{
}

void CMonster_Hard::Initialize()
{
	Set_MaxHp(100);
	Set_CurHp(100);
	Set_Str(10);
}

void CMonster_Hard::Update()
{
}

void CMonster_Hard::Render()
{
	CAttackObj::Render();
}

void CMonster_Hard::Release()
{
}
