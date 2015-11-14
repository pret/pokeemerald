as -mcpu=arm7tdmi asm/emerald.s -o emerald.o
ld -T ld_script.txt -T wram_syms.txt -o emerald.elf emerald.o
objcopy -O binary emerald.elf emerald.gba
fc /b base_emerald.gba emerald.gba
