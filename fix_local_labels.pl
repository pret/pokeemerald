use strict;
use warnings;

open(IN_FILE, $ARGV[0]);
open(OUT_FILE, ">", $ARGV[1]);

my @labels = ();

while (<IN_FILE>) {
	if ($_ =~ /^\.(.+):/) {
		push(@labels, $1);
	}
}

seek IN_FILE, 0, 0;

while (<IN_FILE>) {
	for (my $i = 0; $i < scalar(@labels); $i++) {
		my $find = quotemeta '.' . $labels[$i];
		my $replace = '$' . $labels[$i];
		$_ =~ s/$find/$replace/;
	}

	print OUT_FILE $_;
}

close(IN_FILE);
close(OUT_FILE);
