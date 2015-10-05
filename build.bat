as -mcpu=arm7tdmi asm/emerald.s -Iasm
ld -T ld_script.txt -o emerald.o a.out
objcopy -O binary emerald.o emerald.gba
fc /b base_emerald.gba emerald.gba
