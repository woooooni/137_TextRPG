// Lecture2_GitPractice.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "CGameCore.h"

int main()
{
	CGameCore::GetInst()->Initialize();
	CGameCore::GetInst()->Tick();

	return 0;
}

