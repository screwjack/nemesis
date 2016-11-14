/*
 Copyright (c) 2016 nemesis project/mrn@sdf.org. All rights reserved.
 http://mrn.sixbit.org/

 Governed by the BSD 2 Clause license, the full text of which is contained in
 the file License.txt included in nemesis binary and source code distribution
 packages.
 Based on TrueCrypt 7.1a, which was governed by the TrueCrypt license, which
 is also made available with nemesis.
*/

#ifndef TC_HEADER_Core_RandomNumberGenerator
#define TC_HEADER_Core_RandomNumberGenerator

#include "Platform/Platform.h"
#include "Volume/Hash.h"
#include "Common/Random.h"

namespace nemesis
{
	class RandomNumberGenerator
	{
	public:
		static void AddToPool (const ConstBufferPtr &buffer);
		static void GetData (const BufferPtr &buffer) { GetData (buffer, false); }
		static void GetDataFast (const BufferPtr &buffer) { GetData (buffer, true); }
		static shared_ptr <Hash> GetHash ();
		static bool IsEnrichedByUser () { return EnrichedByUser; }
		static bool IsRunning () { return Running; }
		static ConstBufferPtr PeekPool () { return Pool; }
		static void SetEnrichedByUserStatus (bool enriched) { EnrichedByUser = enriched; }
		static void SetHash (shared_ptr <Hash> hash);
		static void Start ();
		static void Stop ();

		static const size_t PoolSize = RNG_POOL_SIZE;

	protected:
		static void AddSystemDataToPool (bool fast);
		static void GetData (const BufferPtr &buffer, bool fast);
		static void HashMixPool ();
		static void Test ();
		RandomNumberGenerator ();

		static const size_t MaxBytesAddedBeforePoolHashMix = RANDMIX_BYTE_INTERVAL;

		static Mutex AccessMutex;
		static size_t BytesAddedSincePoolHashMix;
		static bool EnrichedByUser;
		static SecureBuffer Pool;
		static shared_ptr <Hash> PoolHash;
		static size_t ReadOffset;
		static bool Running;
		static size_t WriteOffset;
	};
}

#endif // TC_HEADER_Core_RandomNumberGenerator
