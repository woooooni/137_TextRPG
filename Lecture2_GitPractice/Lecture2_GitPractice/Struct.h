#pragma once
#include "stdafx.h"

// ������
struct tagItem {
	string strName;
	string strType;
	string strDetailType = "";
	string strRare;

	int iAtk = 0;
	int iHp = 0;
	int iRecovery = 0;

	int iPrice = 0;
};