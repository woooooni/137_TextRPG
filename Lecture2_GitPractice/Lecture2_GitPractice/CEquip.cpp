#include "stdafx.h"
#include "CEquip.h"


CEquip::CEquip()
{
}

CEquip::~CEquip()
{
}

void CEquip::Initialize()
{
}

void CEquip::Update()
{
}

void CEquip::Render()
{
	cout << "장비한 무기 : " << endl;
	cout << "장비한 모자 : " << endl;
	cout << "장비한 옷 : " << endl;
	cout << "장비한 신발 : " << endl;
	cout << "=============================" << endl;
}

void CEquip::Release()
{
}

//void CEquip::Equip_Item(CItem* _pItem)
//{
//	mapEquip.insert({ _pItem->Get_Info().Type, _PItem });
//}
//
//void CEquip::Unequip_Item(CItem* _pItem)
//{
//  iter = mapEquip.find(_pItem->Get_Info().Type);
//  mapEquip.earase(iter);
//}
