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


	// ������ ���� �� ��� �÷��̾� ���� 




private:
	PLAYER_JOB m_eJob;

};

