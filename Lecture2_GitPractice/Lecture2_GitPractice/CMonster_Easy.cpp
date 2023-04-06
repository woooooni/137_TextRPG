#include "stdafx.h"
#include "CMonster_Easy.h"


CMonster_Easy::CMonster_Easy()
	:CMonster("이지 몬스터")
{
}


CMonster_Easy::~CMonster_Easy()
{
}

void CMonster_Easy::Initialize()
{
	Set_MaxHp(30);
	Set_CurHp(30);
	Set_Str(1);

}

void CMonster_Easy::Update()
{

}

void CMonster_Easy::Render()
{
	CAttackObj::Render();

	//TODO :: 몬스터 정보 출력.

}

void CMonster_Easy::Release()
{
}
