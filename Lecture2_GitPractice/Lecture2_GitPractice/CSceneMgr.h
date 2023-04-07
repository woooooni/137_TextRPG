#pragma once
#include "stdafx.h"
class CScene;
class CSceneMgr
{
	SINGLETON(CSceneMgr);

private:
	vector<CScene*>		m_vecScene;     // Scene
	vector<CScene*>		m_vecBackScene; // 이전 씬 저장 벡터 (뒤로가기 스택 용도)
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

