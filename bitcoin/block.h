#ifndef LIGHTNING_BITCOIN_BLOCK_H
#define LIGHTNING_BITCOIN_BLOCK_H
#include "config.h"
#include "bitcoin/shadouble.h"
#include <ccan/endian/endian.h>
#include <ccan/short_types/short_types.h>
#include <ccan/tal/tal.h>
#include <stdbool.h>

struct bitcoin_block_hdr {
	le32 version;
	struct sha256_double prev_hash;
	struct sha256_double merkle_hash;
	le32 timestamp;
	le32 target;
	le32 nonce;
};

struct bitcoin_block {
	struct bitcoin_block_hdr hdr;
    u8 * vchSig;
    bool fStake;
    struct sha256_double prev_stake_hash;
    le32 prev_stake_n;
    le32 stake_time;
	/* tal_count shows now many */
	struct bitcoin_tx **tx;
};

struct bitcoin_block *bitcoin_block_from_hex(const tal_t *ctx,
					     const char *hex, size_t hexlen);

/* Parse hex string to get blockid (reversed, a-la bitcoind). */
bool bitcoin_blkid_from_hex(const char *hexstr, size_t hexstr_len,
			    struct sha256_double *blockid);

/* Get hex string of blockid (reversed, a-la bitcoind). */
bool bitcoin_blkid_to_hex(const struct sha256_double *blockid,
			  char *hexstr, size_t hexstr_len);
#endif /* LIGHTNING_BITCOIN_BLOCK_H */
