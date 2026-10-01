# Processes 'cpp' output and discards lines that don't originate in the
# top-level file.

# This is used to prevent C definitions etc leaking into linker scripts,
# but as a consequence linker script commands from those files will be
# ignored. It's unlikely this limitation will ever matter.

# FIXME: Linemarkers are not correctly processed, so if 'cpp' skips any
# output (e.g. due to a top-level '#if 0') the error messages will be
# difficult to understand.

BEGIN {
    getline
    toplevel = $3
    at_toplevel = 0
}

/^#/ {
    if (at_toplevel) print ""
    at_toplevel = $2 != 0 && $3 == toplevel
}

!/^#/ {
    if (at_toplevel) print $0
}
