#pragma once

class CEquip
{
public:
	explicit CEquip();
	~CEquip();


private:
	//map<EQUIP_TYPE, CItem*> mapEquip;
	//map<EQUIP_TYPE, CItem*>::iterator iter;

public:
	void Initialize();
	void Update();
	void Render();
	void Release();

	//void Equip_Item(CItem* _pItem);
	//void Unequip_Item(CItem* _pItem);
};

