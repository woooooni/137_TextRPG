#pragma once

template <typename T>
void Safe_Delete(T* _p) { if (_p) { delete _p; _p = nullptr; } }


template <typename T>
void Safe_Delete_Arr(T* _pArr) { if (_pArr) { delete[] _pArr; _pArr = nullptr; } }
