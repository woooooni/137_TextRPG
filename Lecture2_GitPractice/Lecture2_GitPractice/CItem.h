#pragma once
#include "Enum.h"
#include "Enum_String.h"
#include "Struct.h"
#include "Template.h"

class CItem
{
public:
	explicit CItem() : iAmount(0) {}
	virtual ~CItem();

protected:
	tagItem m_tItem;
	int iAmount;

	ITEM_RARITY m_eRare;
	EQUIP_TYPE m_eType;

public:
	tagItem GetItem() { return m_tItem; }
	int GetAmount() { return iAmount; }

public:
	void SetAmount(int _iAmount) { iAmount = _iAmount; }

public:
	void Render();

};

