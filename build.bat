as -mcpu=arm7tdmi asm/emerald.s
ld -T ld_script.txt -o emerald.o a.out
objcopy -O binary emerald.o emerald.gba
fc /b base_emerald.gba emerald.gba
