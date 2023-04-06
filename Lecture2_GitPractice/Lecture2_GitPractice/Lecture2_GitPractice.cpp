// Lecture2_GitPractice.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "CGameCore.h"

int main()
{
	CGameCore::GetInst()->Initialize();
	CGameCore::GetInst()->Tick();

	return 0;
}

