// Copyright (c) 2016 The tcccoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef tcccoin_WALLET_TEST_FIXTURE_H
#define tcccoin_WALLET_TEST_FIXTURE_H

#include "test/test_tcccoin.h"

/** Testing setup and teardown for wallet.
 */
struct WalletTestingSetup: public TestingSetup {
    explicit WalletTestingSetup(const std::string& chainName = CBaseChainParams::MAIN);
    ~WalletTestingSetup();
};

#endif

