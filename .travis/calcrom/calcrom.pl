#!/usr/bin/perl

use IPC::Cmd qw[ run ];

(@ARGV == 1)
    or die "ERROR: no map file specified.\n";
open(my $file, $ARGV[0])
    or die "ERROR: could not open file '$ARGV[0]'.\n";

my $src = 0;
my $asm = 0;
while (my $line = <$file>)
{
    if ($line =~ /^ \.(\w+)\s+0x[0-9a-f]+\s+(0x[0-9a-f]+) (\w+)\/.+\.o/)
    {
        my $section = $1;
        my $size = hex($2);
        my $dir = $3;

        if ($section =~ /text/)
        {
            if ($dir eq 'src')
            {
                $src += $size;
            }
            elsif ($dir eq 'asm')
            {
                $asm += $size;
            }
        }
    }
}

# It sucks that we have to objdump twice, but I can't figure out how to get
# stdin working for subcommands in perl while still having a timeout.
my $total_syms_as_string;
(run (
	command => "arm-none-eabi-nm pokeemerald.elf | wc -l",
	buffer => \$total_syms_as_string,
	timeout => 30
))
    or die "ERROR: Error while getting all symbols: $?";

my $undocumented_as_string;
(run (
	command => "arm-none-eabi-nm pokeemerald.elf | grep \"Unknown_\\|sub_\" | wc -l",
	buffer => \$undocumented_as_string,
	timeout => 30
))
    or die "ERROR: Error while filtering for undocumented symbols: $?";

my $undocumented = $undocumented_as_string + 0;
(($undocumented != 0) and ($undocumented_as_string ne "0"))
    or die "ERROR: Cannot convert string to num: '$undocumented_as_string'";

my $total_syms = $total_syms_as_string + 0;
(($total_syms != 0) and ($total_syms_as_string ne "0"))
    or die "ERROR: Cannot convert string to num: '$total_syms_as_string'";

($total_syms != 0)
    or die "ERROR: No symbols found.";

my $total = $src + $asm;
my $srcPct = sprintf("%.4f", 100 * $src / $total);
my $asmPct = sprintf("%.4f", 100 * $asm / $total);

my $documented = $total_syms - $undocumented;
my $docPct = sprintf("%.4f", 100 * $documented / $total_syms);
my $undocPct = sprintf("%.4f", 100 * $undocumented / $total_syms);

print "$total total bytes of code\n";
print "$src bytes of code in src ($srcPct%)\n";
print "$asm bytes of code in asm ($asmPct%)\n";
print "\n";
print "$total_syms total symbols\n";
print "$documented symbols documented ($docPct%)\n";
print "$undocumented symbols undocumented ($undocPct%)\n";
