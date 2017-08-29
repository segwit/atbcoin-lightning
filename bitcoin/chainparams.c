#include "chainparams.h"
#include <ccan/array_size/array_size.h>
#include <ccan/str/str.h>
#include <string.h>

const struct chainparams networks[] = {
    {.index = 0,
     .network_name = "atbcoin",
     .genesis_blockhash = {{.u.u8 = {0x00, 0x00, 0x00, 0x00, 0x00, 0x19, 0xd6,
				     0x68, 0x9c, 0x08, 0x5a, 0xe1, 0x65, 0x83,
				     0x1e, 0x93, 0x4f, 0xf7, 0x63, 0xae, 0x46,
				     0xa2, 0xa6, 0xc1, 0x72, 0xb3, 0xf1, 0xb6,
				     0x0a, 0x8c, 0xe2, 0x6f}}},
     .rpc_port = 8332,
     .cli = "/home/vadim/Документы/projects/blockchainGUI/blockchain/src/atbcoin-cli",
     .cli_args = NULL,
     .dust_limit = 546,
     .testnet = false},
    {.index = 1,
     .network_name = "regtest",
     .genesis_blockhash = {{.u.u8 = {0x0f, 0x91, 0x88, 0xf1, 0x3c, 0xb7, 0xb2,
				     0xc7, 0x1f, 0x2a, 0x33, 0x5e, 0x3a, 0x4f,
				     0xc3, 0x28, 0xbf, 0x5b, 0xeb, 0x43, 0x60,
				     0x12, 0xaf, 0xca, 0x59, 0x0b, 0x1a, 0x11,
				     0x46, 0x6e, 0x22, 0x06}}},
     .rpc_port = 18332,
     .cli = "/home/vadim/Документы/projects/blockchainGUI/blockchain/src/atbcoin-cli",
     .cli_args = "-regtest",
     .dust_limit = 546,
     .testnet = true},
    {.index = 2,
     .network_name = "testnet",
           .genesis_blockhash = {{.u.u8 = {0x00, 0x00, 0x00, 0x00, 0x09, 0x33, 0xea,
                          0x01, 0xad, 0x0e, 0xe9, 0x84, 0x20, 0x97,
                          0x79, 0xba, 0xae, 0xc3, 0xce, 0xd9, 0x0f,
                          0xa3, 0xf4, 0x08, 0x71, 0x95, 0x26, 0xf8,
                          0xd7, 0x7f, 0x49, 0x43}}},
     .rpc_port = 18332,
     .cli = "/home/vadim/Документы/projects/blockchainGUI/blockchain/src/atbcoin-cli",
     .cli_args = "-testnet",
     .dust_limit = 546,
     .testnet = true},
    {.index = 3,
     .network_name = "litecoin",
     .genesis_blockhash = {{.u.u8 = {0x12, 0xa7, 0x65, 0xe3, 0x1f, 0xfd, 0x40,
				     0x59, 0xba, 0xda, 0x1e, 0x25, 0x19, 0x0f,
				     0x6e, 0x98, 0xc9, 0x9d, 0x97, 0x14, 0xd3,
				     0x34, 0xef, 0xa4, 0x1a, 0x19, 0x5a, 0x7e,
				     0x7e, 0x04, 0xbf, 0xe2}}},
     .rpc_port = 18332,
     .cli = "litecoin-cli",
     .cli_args = "",
     .dust_limit = 100000,
     .testnet = false}};

const struct chainparams *chainparams_for_network(const char *network_name)
{
	for (size_t i = 0; i < ARRAY_SIZE(networks); i++) {
		if (streq(network_name, networks[i].network_name)) {
			return &networks[i];
		}
	}
	return NULL;
}

const struct chainparams *chainparams_by_index(const int index)
{
	if (index >= ARRAY_SIZE(networks) || index < 0) {
		return NULL;
	} else {
		return &networks[index];
	}
}
