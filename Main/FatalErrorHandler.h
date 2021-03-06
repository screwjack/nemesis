/*
 Copyright (c) 2008-2009 nemesis Developers Association. All rights reserved.

 Governed by the nemesis License 3.0 the full text of which is contained in
 the file License.txt included in nemesis binary and source code distribution
 packages.
*/

#ifndef TC_HEADER_Main_FatalErrorHandler
#define TC_HEADER_Main_FatalErrorHandler

#include "System.h"

namespace nemesis
{
	class FatalErrorHandler
	{
	public:
		static void Deregister();
		static uint32 GetAppChecksum ();
		static wstring GetCallStack (int depth);
		static void Register();

	protected:
		static void OnSignal (int signal);
		static void OnTerminate ();

	private:
		FatalErrorHandler ();
	};
}

#endif // TC_HEADER_Main_FatalErrorHandler
