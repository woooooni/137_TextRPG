#pragma once
#include "Enum.h"
#include "Enum_String.h"
#include "Struct.h"
#include "Template.h"
#include <Windows.h>

class CItem
{
public:
	explicit CItem() : iAmount(0) {}
	virtual ~CItem();

protected:
	tagItem m_tItem;
	int iAmount;

public:
	tagItem GetItem() { return m_tItem; }
	int GetAmount() { return iAmount; }

public:
	void SetAmount(int _iAmount) { iAmount += _iAmount; }

public:
	void Render();
	void Render(int _i, int _y);
public:
	void gotoxy(int _x, int _y);
	int currentX();
	int currentY();
};

