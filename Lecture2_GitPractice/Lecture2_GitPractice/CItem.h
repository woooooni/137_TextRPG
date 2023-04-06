#pragma once
#include "Struct.h"
#include "Enum.h"

class CItem
{
public:
<<<<<<< .merge_file_cRxao7
	explicit CItem();
=======
	explicit CItem() : iAmount(0) {}
>>>>>>> .merge_file_QQPLzM
	virtual ~CItem();

protected:
	tagItem* m_tItem;
<<<<<<< .merge_file_cRxao7

public:
	tagItem* GetItem() { return m_tItem; }
=======
	int iAmount;
public:
	tagItem* GetItem() { return m_tItem; }
	int GetAmount() { return iAmount; }
public:
	void SetAmount(int _iAmount) { iAmount = _iAmount; }
>>>>>>> .merge_file_QQPLzM
public:
	void Render();

};

