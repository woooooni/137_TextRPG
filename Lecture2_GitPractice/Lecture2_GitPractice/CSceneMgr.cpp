#include "stdafx.h"
#include "CSceneMgr.h"
#include "CScene.h"
#include "Template.h"
#include "CScene_Field.h"

CSceneMgr::CSceneMgr()
{
}


CSceneMgr::~CSceneMgr()
{

}

void CSceneMgr::ChangeScene(SCENE_TYPE _eType)
{
	auto findLambda = [_eType](CScene* _pScene) -> const bool { if (_eType == _pScene->GetSceneType()) return true; else return false; };
	auto findIt = find_if(m_vecScene.begin(), m_vecScene.end(), findLambda);

	if (findIt == m_vecScene.end()) return;

	m_vecBackScene.push_back(m_pCurScene);

	m_pCurScene->Exit();
	m_pCurScene = m_vecScene[(unsigned int)_eType];
	m_pCurScene->Enter();
}

void CSceneMgr::BackScene()
{
	if (m_vecBackScene.empty()) return;

	m_pCurScene->Exit();
	m_pCurScene = m_vecBackScene.back();
	m_vecBackScene.pop_back();
	m_pCurScene->Enter();
}

void CSceneMgr::Initialize()
{
	CScene* pTemp = new CScene_Field;
	if(pTemp != nullptr) m_vecScene.push_back(pTemp);

	// 다른 씬들도 생성....
}

void CSceneMgr::Update()
{
	m_pCurScene->Update();
}

void CSceneMgr::Render()
{
	m_pCurScene->Render();
}

void CSceneMgr::Release()
{
	for_each(m_vecScene.begin(), m_vecScene.end(), Safe_Delete<CScene*>);
	for_each(m_vecBackScene.begin(), m_vecBackScene.end(), Safe_Delete<CScene*>);

	m_vecScene.clear();
	m_vecBackScene.clear();

	vector<CScene*>().swap(m_vecScene);
	vector<CScene*>().swap(m_vecBackScene);
}
