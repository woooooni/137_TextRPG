#pragma once
#include "CAttackObj.h"

class CPlayer : public CAttackObj
{
public:
	explicit CPlayer();
	virtual ~CPlayer();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	// Access Methods


	// 아이템 관련 및 모든 플레이어 사항 




private:
	PLAYER_JOB m_eJob;

};

