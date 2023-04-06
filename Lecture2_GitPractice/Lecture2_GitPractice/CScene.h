#pragma once
class CScene
{
public:
	virtual void Enter()	= 0;
	virtual void Update()	= 0;
	virtual void Render()	= 0;
	virtual void Exit()		= 0;

public:
	SCENE_TYPE GetSceneType() { return m_eType; }

public:
	explicit CScene(SCENE_TYPE _eType);
	virtual ~CScene();

private:
	SCENE_TYPE m_eType;
};

