// Lecture2_GitPractice.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

