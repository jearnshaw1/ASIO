//
//CUnknown implements functions and methods that allow COM support
// (Found in ComSup.cpp)
//

#include "driver.h"

class driver : public CUnknown, public IDriverEntry
{
private:

	IDriverEntry* QueryIDriverEntry
	(
		VOID
	)
	{
		AddRef();
		return static_cast<IDriverEntry*>(this);

	}

	HRESULT Initialize
	(
		VOID
	);

public:

	//Factory Method
	static HRESULT CreateInstance
	(
		_OUT_ PCMyDriver* Driver
	);

	virtual HRESULT __stdcall OnInitialize
	(
		_In_ IWDFDriver* FxWdfDriver
	)
	{
		UNREFERENCED_PARAMETER(FxWdfDriver);

		return S_OK;
	}

	virtual HRESULT __stdcall OnDeviceAdd
	(
		_In_ IWDFDriver* FxWdfDriver,
		_In_ IWDFDeviceInitialize* FxDeviceInit
	);

	virtual VOID __stdcall OnDeinitialize
	(
		_In_ IWDFDriver* FxWdfDriver
	)
	{

		UNREFERENCED_PARAMETER(FxWdfDriver);

	}

	_At_(this, __drv_freesMem(object))
	//_annotation list (2nd arg. ) is applied to -this-
	// instead of identifer
		virtual ULONG __stdcall Release
		(
			VOID

		)
	{
		//overriding a class and 
		//wish to call a base implementation
		// as all base-class implementations
		//are considered during overload resolution

		return __super::Release();
	}

	virtual HRESULT STDMETHODCALLTYPE QueryInterface
	(
		_In_ REFIId InterfaceId,
		_Out_ PVOID* Object
	);

};