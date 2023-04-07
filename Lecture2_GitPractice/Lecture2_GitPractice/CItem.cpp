#include "stdafx.h"
#include "CItem.h"

CItem::~CItem()
{
}

void CItem::Render()
{
	cout << m_tItem.strName << "(" << STR_RARITY[(int)m_tItem.eRare] << ")" << "\t" 
		 << STR_EQUIPTYPE[(int)m_tItem.eType];

	if (m_tItem.eType == EQUIP_TYPE::WEAPON)   cout << " ���ݷ�: " << m_tItem.iAtk;
	else if (m_tItem.eType != EQUIP_TYPE::END) cout << " ü��: " << m_tItem.iHp;

	cout << " ����: " << m_tItem.iPrice << endl;
}

void CItem::Render(int _i, int _y)
{
	gotoxy(50, _y);
	cout << _i << ". ";
	cout << m_tItem.strName << "(" << STR_RARITY[(int)m_tItem.eRare] << ")" << "("
		<< STR_EQUIPTYPE[(int)m_tItem.eType] << ")" << endl;

	gotoxy(50, _y + 1);
	if (m_tItem.eType == EQUIP_TYPE::WEAPON)   cout << " \t���ݷ�: " << m_tItem.iAtk;
	else if (m_tItem.eType != EQUIP_TYPE::END) cout << " \tü��: " << m_tItem.iHp;

	cout << " ����: " << m_tItem.iPrice << endl;

	gotoxy(50, _y + 2);
	cout << "======================================" << endl;
}

void CItem::gotoxy(int _x, int _y)
{
	COORD pos;
	pos.X = _x;
	pos.Y = _y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int CItem::currentX()
{
	CONSOLE_SCREEN_BUFFER_INFO presentCur;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &presentCur);
	return presentCur.dwCursorPosition.X;
}

int CItem::currentY()
{
	CONSOLE_SCREEN_BUFFER_INFO presentCur;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &presentCur);
	return presentCur.dwCursorPosition.Y;
}

