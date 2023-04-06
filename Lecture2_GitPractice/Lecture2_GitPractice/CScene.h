#pragma once
class CScene
{
<<<<<<< .merge_file_jw2ANV
private:
	SCENE_TYPE _eType;

=======
>>>>>>> .merge_file_lofgRN
public:
	virtual void Enter()	= 0;
	virtual void Update()	= 0;
	virtual void Render()	= 0;
	virtual void Exit()		= 0;

public:
<<<<<<< .merge_file_jw2ANV
	explicit CScene();
	virtual ~CScene();
=======
	SCENE_TYPE GetSceneType() { return m_eType; }

public:
	explicit CScene(SCENE_TYPE _eType);
	virtual ~CScene();

private:
	SCENE_TYPE m_eType;
>>>>>>> .merge_file_lofgRN
};

