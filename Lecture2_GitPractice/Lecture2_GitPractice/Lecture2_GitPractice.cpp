// Lecture2_GitPractice.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "CGameCore.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CGameCore::GetInst()->Initialize();
	CGameCore::GetInst()->Tick();

	return 0;
}

