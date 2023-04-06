#pragma once
#include "stdafx.h"
#include <ctime>

class CGameCore
{
	SINGLETON(CGameCore);


public:
	void Initialize();
	void Tick();
	void Stop() { m_bPlaying = false; }


public:
	bool IsPlaying() { return m_bPlaying; }


private:
	bool m_bPlaying;

};
