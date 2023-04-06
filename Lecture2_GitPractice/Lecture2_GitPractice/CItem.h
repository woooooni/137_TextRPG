#pragma once
#include "Struct.h"
#include "Enum.h"

class CItem
{
public:
	explicit CItem() : iAmount(0) {
		m_tItem->iAtk = 0;
		m_tItem->iHp = 0;
		m_tItem->iRecovery = 0;
	}
	virtual ~CItem();

protected:
	tagItem* m_tItem;
	int iAmount;

public:
	tagItem* GetItem() { return m_tItem; }
	int GetAmount() { return iAmount; }
public:
	void SetAmount(int _iAmount) { iAmount += _iAmount; }
public:
	void Render();

};

