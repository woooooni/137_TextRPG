#pragma once
#include "stdafx.h"
#include <ctime>
#include "Template.h"
class CPlayer;
class CGameCore
{
	SINGLETON(CGameCore);

private:
	CPlayer* m_pPlayer;
	bool	 m_bPlaying;

public:
	void Initialize();
	void Tick();
	void Stop() { m_bPlaying = false; }
	void Release();

public:
	CPlayer*		GetPlayer() { return m_pPlayer; }
	bool			IsPlaying() { return m_bPlaying; }
};
