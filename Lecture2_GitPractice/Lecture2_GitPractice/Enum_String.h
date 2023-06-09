#pragma once
#include "stdafx.h"
#include <string>

const string STR_STATE[(int)STATE::END] = { "무속성", "화상", "축축함", "한기" };
const string STR_PROPERTY[(int)PROPERTY_TYPE::END] = { "NORMAL", "FIRE", "WATER", "THUNDER", "GROUND", "ICE" };
const string STR_RARITY[(int)ITEM_RARITY::END] = { "노말", "레어", "에픽", "유니크", "레전드리" };
const string STR_EQUIPTYPE[(int)EQUIP_TYPE::END] = { "모자", "상의", "하의", "무기", "소모품" };
