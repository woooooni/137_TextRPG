#pragma once
#include "stdafx.h"
class CScene;
class CSceneMgr
{
	SINGLETON(CSceneMgr);

private:
	vector<CScene*>		m_vecScene;     // Scene
	vector<CScene*>		m_vecBackScene; // ���� �� ���� ���� (�ڷΰ��� ���� �뵵)
	CScene*				m_pCurScene;

public:
	void ChangeScene(SCENE_TYPE _eType);
	void BackScene();

public:
	void Initialize();
	void Update();
	void Render();
	void Release();
};

