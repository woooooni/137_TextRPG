#pragma once
#include "stdafx.h"

// ¾ÆÀÌÅÛ
struct tagItem {
	string strName;
	string strType;
	string strRare;

	int iAtk;
	int iHp;

	int iPrice;
	string strDetailType = "";
	string strRare;

	int iAtk = 0;
	int iHp = 0;
	int iRecovery = 0;

	int iPrice = 0;
};
