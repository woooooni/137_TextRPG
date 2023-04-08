#pragma once

template <typename T>
void Safe_Delete(T& _p) { if (_p) { delete _p; _p = nullptr; } }


template <typename T>
void Safe_Delete_Arr(T& _pArr) { if (_pArr) { delete[] _pArr; _pArr = nullptr; } }


template<typename T>
void Safe_Delete_Vec(vector<T>& _vec)
{
	typename vector<T>::iterator iter = _vec.begin();
	for (; iter != _vec.end(); ++iter)
	{
		if (nullptr != (*iter))
		{
			delete (*iter);
			*iter = nullptr;
		}
	}
	_vec.clear();
	_vec.shrink_to_fit();
}