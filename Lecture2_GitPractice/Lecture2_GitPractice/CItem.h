#pragma once
#include "Struct.h"
#include "Enum.h"

class CItem
{
public:
	explicit CItem() : iAmount(0) {}
	virtual ~CItem();

public:
	tagItem* GetItem() { return m_tItem; }
	int GetAmount() { return iAmount; }
public:
	void SetAmount(int _iAmount) { iAmount = _iAmount; }
public:
	void Render();


protected:
	tagItem* m_tItem;
	int iAmount;

};

