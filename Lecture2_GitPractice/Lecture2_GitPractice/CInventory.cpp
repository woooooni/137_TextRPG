#include "stdafx.h"
#include "CInventory.h"

CInventory::~CInventory()
{
}

void CInventory::Init()
{
}

void CInventory::Render()
{
}

void CInventory::Update()
{
}

void CInventory::Release()
{
}

void CInventory::AddItem(CItem * _pItem)
{
	m_vecItems.push_back(_pItem);
}
