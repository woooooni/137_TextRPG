#include "stdafx.h"
#include "CMonster_Normal.h"


CMonster_Normal::CMonster_Normal()
	:CMonster("노말 몬스터")
{
}


CMonster_Normal::~CMonster_Normal()
{
}

void CMonster_Normal::Initialize()
{
	Set_MaxHp(50);
	Set_CurHp(50);
	Set_Str(5);
}

void CMonster_Normal::Update()
{

}

void CMonster_Normal::Render()
{
	CAttackObj::Render();
	// TODO :: 몬스터 정보 출력.

}

void CMonster_Normal::Release()
{
}
