/*
 * Copyright (c) 2007 Henric Jungheim <software@henric.info>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * NIST SP 800-90 CTR_DRBG (Random Number Generator)
 */

#ifndef NIST_CTR_DRBG_AES256_H
#define NIST_CTR_DRBG_AES256_H

/* Choose AES-256 as the underlying block cipher */
#define NIST_BLOCK_KEYLEN		(256)
#define NIST_BLOCK_KEYLEN_BYTES	(NIST_BLOCK_KEYLEN / 8)
#define NIST_BLOCK_KEYLEN_INTS	(NIST_BLOCK_KEYLEN_BYTES / sizeof(int))

#define NIST_BLOCK_OUTLEN		(NIST_AES_BLOCKSIZEBITS)
#define NIST_BLOCK_OUTLEN_BYTES	(NIST_BLOCK_OUTLEN / 8)
#define NIST_BLOCK_OUTLEN_INTS	(NIST_BLOCK_OUTLEN_BYTES / sizeof(int))

typedef NIST_AES_ENCRYPT_CTX NIST_Key;

#define Block_Encrypt(ctx, src, dst) NIST_AES_ECB_Encrypt(ctx, src, dst)
#define Block_Schedule_Encryption(ctx, key) NIST_AES_Schedule_Encryption(ctx, key, NIST_BLOCK_KEYLEN)

/*
 * NIST SP 800-90 March 2007
 * 10.2 DRBG Mechanism Based on Block Ciphers
 *
 * Table 3 specifies the reseed interval as
 * <= 2^48.  We are only using a 32-bit counter,
 * so we set the reseed interval a bit lower.
 */
#define NIST_CTR_DRBG_RESEED_INTERVAL	(100000)

#endif /* NIST_CTR_DRBG_AES256_H */

