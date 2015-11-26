as -mcpu=arm7tdmi asm/emerald.s -o emerald.o
ld -T ld_script.txt -T wram_syms.txt -o pokeemerald.elf emerald.o
objcopy -O binary pokeemerald.elf pokeemerald.gba
diff base_emerald.gba pokeemerald.gba
