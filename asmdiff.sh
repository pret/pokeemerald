#!/usr/bin/env bash

if [[ -d "$DEVKITARM/bin/" ]]; then
    OBJDUMP_BIN="$DEVKITARM/bin/arm-none-eabi-objdump"
else
    OBJDUMP_BIN="arm-none-eabi-objdump"
fi

OBJDUMP="$OBJDUMP_BIN -D -bbinary -marmv4t -Mforce-thumb"

if [ $(($1)) -ge $((0x8000000)) ]; then
    OPTIONS="--adjust-vma=0x8000000 --start-address=$(($1)) --stop-address=$(($1 + $2))"
else
    OPTIONS="--start-address=$(($1)) --stop-address=$(($1 + $2))"
fi

$OBJDUMP $OPTIONS baserom.gba > baserom.dump
$OBJDUMP $OPTIONS pokeemerald.gba > pokeemerald.dump
diff -u baserom.dump pokeemerald.dump
