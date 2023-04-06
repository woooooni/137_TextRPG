#pragma once
class CScene
{
private:
	SCENE_TYPE _eType;

public:
	virtual void Enter()	= 0;
	virtual void Update()	= 0;
	virtual void Render()	= 0;
	virtual void Exit()		= 0;

public:
	explicit CScene();
	virtual ~CScene();
};

