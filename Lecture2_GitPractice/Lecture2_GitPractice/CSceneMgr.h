#pragma once
#include "stdafx.h"
class CScene;
class CSceneMgr
{
	SINGLETON(CSceneMgr);

private:
	vector<CScene*>		m_vecScene;
	CScene*				m_pCurrScene;

public:
	void ChangeScene(SCENE_TYPE _eType);

public:
	void Initialize();
	void Update();
	void Render();
	void Release();


};

