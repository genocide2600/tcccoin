// Copyright (c) 2011-2014 The tcccoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef tcccoin_QT_tcccoinADDRESSVALIDATOR_H
#define tcccoin_QT_tcccoinADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class tcccoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit tcccoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** tcccoin address widget validator, checks for a valid tcccoin address.
 */
class tcccoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit tcccoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // tcccoin_QT_tcccoinADDRESSVALIDATOR_H
