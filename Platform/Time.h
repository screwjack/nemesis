/*
 Copyright (c) 2008 nemesis Developers Association. All rights reserved.

 Governed by the nemesis License 3.0 the full text of which is contained in
 the file License.txt included in nemesis binary and source code distribution
 packages.
*/

#ifndef TC_HEADER_Platform_Time
#define TC_HEADER_Platform_Time

#include "PlatformBase.h"

namespace nemesis
{
	class Time
	{
	public:
		Time () { }
		virtual ~Time () { }

		static uint64 GetCurrent (); // Returns time in hundreds of nanoseconds since 1601/01/01

	private:
		Time (const Time &);
		Time &operator= (const Time &);
	};
}

#endif // TC_HEADER_Platform_Time
