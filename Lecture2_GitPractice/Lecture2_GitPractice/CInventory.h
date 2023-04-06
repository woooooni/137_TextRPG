#pragma once
#include "Define.h"
#include "Struct.h"
#include "CItem.h"

class CInventory
{
public:
<<<<<<< .merge_file_EjHbIl
	CInventory() : iAmount(0) {

	}
=======
	CInventory();
>>>>>>> .merge_file_0sAJRe
	~CInventory();

private:
	vector<CItem*> m_vecItems;
	vector<CItem*>::iterator invenIter;
<<<<<<< .merge_file_EjHbIl
	int iAmount;
=======
>>>>>>> .merge_file_0sAJRe

public:
	void Init();
	void Render();
	void Update();
	void Release();

public:
<<<<<<< .merge_file_EjHbIl
	void AddItem(CItem* _pItem);
=======
	void AddItem(CItem* _pItem, int _iAmount = 1);
	void UseItem(int _iIndex);
>>>>>>> .merge_file_0sAJRe
};

