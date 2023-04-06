#pragma once
class CObj
{
public:
	virtual void Initialize()	= 0;
	virtual void Update()		= 0;
	virtual void Render()		= 0;
	virtual void Release()		= 0;
	
public:
	explicit CObj();
	explicit CObj(const OBJECT_TYPE& _eObjType) : m_eObjType(_eObjType) {}
	virtual ~CObj();

public:
	const OBJECT_TYPE& Get_ObjType() const						{ return m_eObjType; }
	const bool Set_ObjType(const OBJECT_TYPE& _eType)			{ m_eObjType = _eType; }

protected:
	OBJECT_TYPE m_eObjType;
};

