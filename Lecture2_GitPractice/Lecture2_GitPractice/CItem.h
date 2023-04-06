#pragma once
#include "Struct.h"
#include "Enum.h"

class CItem
{
public:
	explicit CItem();
	virtual ~CItem();

protected:
	tagItem* m_tItem;

public:
	tagItem* GetItem() { return m_tItem; }
public:
	void Render();

};

