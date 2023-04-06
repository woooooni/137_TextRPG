#pragma once

#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK, __FILE__, __LINE__)
#define new DBG_NEW
#endif

//#define Safe_Delete(p) { delete p; p = nullptr; }
//#define Safe_Delete_Arr(p) { delete[] p; p = nullptr; } 

#pragma region Singleton
#define SINGLETON(type)\
public:\
	static type* GetInst()\
	{\
		static type manager;\
		return &manager;\
	}\
private:\
	type();\
	~type();
#pragma endregion Singleton

#define CLONE(type) type* Clone() { return new type(*this); }
#define NOT_CLONE(type) type* Clone() = delete;

const int	MAX_INVENTORY_SIZE = 5;
