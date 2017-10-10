#!/bin/sh

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
SRCDIR=${SRCDIR:-$TOPDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

tcccoinD=${tcccoinD:-$SRCDIR/tcccoind}
tcccoinCLI=${tcccoinCLI:-$SRCDIR/tcccoin-cli}
tcccoinTX=${tcccoinTX:-$SRCDIR/tcccoin-tx}
tcccoinQT=${tcccoinQT:-$SRCDIR/qt/tcccoin-qt}

[ ! -x $tcccoinD ] && echo "$tcccoinD not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
BTCVER=($($tcccoinCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for tcccoind if --version-string is not set,
# but has different outcomes for tcccoin-qt and tcccoin-cli.
echo "[COPYRIGHT]" > footer.h2m
$tcccoinD --version | sed -n '1!p' >> footer.h2m

for cmd in $tcccoinD $tcccoinCLI $tcccoinTX $tcccoinQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${BTCVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${BTCVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
