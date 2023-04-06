#pragma once
#include "stdafx.h"
class CScene;
class CSceneMgr
{
	SINGLETON(CSceneMgr);

private:
	vector<CScene*>		m_vecScene;
	CScene*				m_pCurScene;
	vector<CScene*>		m_vecBackScene; // ���� �� ����(�ڷΰ��� �뵵)

public:
	void ChangeScene(SCENE_TYPE _eType);
	void BackScene();

public:
	void Initialize();
	void Update();
	void Render();
	void Release();
};

