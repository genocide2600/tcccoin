// Copyright (c) 2011-2014 The tcccoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef tcccoin_QT_WALLETMODELTRANSACTION_H
#define tcccoin_QT_WALLETMODELTRANSACTION_H

#include "walletmodel.h"

#include <QObject>

class SendCoinsRecipient;

class CReserveKey;
class CWallet;
class CWalletTx;

/** Data model for a walletmodel transaction. */
class WalletModelTransaction
{
public:
    explicit WalletModelTransaction(const QList<SendCoinsRecipient> &recipients);
    ~WalletModelTransaction();

    QList<SendCoinsRecipient> getRecipients() const;

    CWalletTx *getTransaction() const;
    unsigned int getTransactionSize();

    void setTransactionFee(const CAmount& newFee);
    CAmount getTransactionFee() const;

    CAmount getTotalTransactionAmount() const;

    void newPossibleKeyChange(CWallet *wallet);
    CReserveKey *getPossibleKeyChange();

    void reassignAmounts(int nChangePosRet); // needed for the subtract-fee-from-amount feature

private:
    QList<SendCoinsRecipient> recipients;
    CWalletTx *walletTransaction;
    CReserveKey *keyChange;
    CAmount fee;
};

#endif // tcccoin_QT_WALLETMODELTRANSACTION_H
