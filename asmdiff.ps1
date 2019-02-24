$objdump = Join-Path -Path "$($args[0])" -ChildPath "bin\objdump.exe"
&$objdump -D -bbinary -marmv4t -Mforce-thumb --start-address="$($args[1])" --stop-address="$($args[2])" .\baserom.gba > .\baserom.dump
&$objdump -D -bbinary -marmv4t -Mforce-thumb --start-address="$($args[1])" --stop-address="$($args[2])" .\pokeemerald.gba > .\pokeemerald.dump
Compare-Object (Get-Content .\baserom.dump) (Get-Content .\pokeemerald.dump)
