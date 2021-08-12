Param
(
    [Parameter(Position = 0)]
    [string]$Start,

    [Parameter(Position = 1)]
    [string]$Offset,

    [Parameter()]
    [string[]]$DiffTool
)

$ErrorActionPreference = "Stop"

$offset_default_value = "0x100"
$diff_tool_default_value = "diff"

$help = "
$($args[0]) [OPTIONS] Start [Offset]

Performs a diff on the assembly of a function in a rom. 'Start' is the start
location of the function, and 'Offset' is the number of bytes to disassemble.
The assembly is saved to *.dump files.

'Offset' is optional, and defaults to $offset_default_value. If this value is
very large (0x10000+), objdump may hang / freeze.

Requirements:
    - A clean copy of the rom named 'baserom.gba'.
    - $$ENV:DEVKITARM to point to the installation of devkitpro. By default, it is
      installed to 'C:\devkitpro\devkitARM'.

Options:
    -DiffTool <tool>   The tool to use for diffing. Defaults to '$diff_tool_default_value'. For VSCode,
                       you can use -DiffTool 'code --diff'. (Quotes are necessary around 'code --diff')
"

if ((-not (Test-Path variable:Start)) -or [string]::IsNullOrWhiteSpace($Start))
{
    Write-Host $help
    exit
}

if (-not (Test-Path variable:DiffTool) -or [string]::IsNullOrWhiteSpace($DiffTool))
{
    $DiffTool = $diff_tool_default_value
}

if (-not (Test-Path variable:Offset) -or [string]::IsNullOrWhiteSpace($Offset))
{
    $Offset = $offset_default_value
}

if (-Not (Test-Path env:DEVKITARM))
{
    Write-Host "ENV:DEVKITARM variable not set."
    Write-Host $help
    exit
}

if (-Not (Test-Path $env:DEVKITARM))
{
    Write-Host "DEVKITARM path '$env:DEVKITARM' does not exist."
    Write-Host $help
    exit
}

if (-Not (Test-Path ".\pokeemerald.gba"))
{
    Write-Host "File 'pokeemerald.gba' not found."
    Write-Host $help
    exit
}

if (-Not (Test-Path ".\baserom.gba"))
{
    Write-Host "File 'baserom.gba' not found."
}

try
{
    $start_num = [System.Convert]::ToUInt64($Start, 16)
}
catch
{
    Write-Host "Error parsing '$start_num' as a hex number."
    Write-Host $help
    exit
}

try
{
    $offset_num = [System.Convert]::ToUInt64($Offset, 16)
}
catch
{
    Write-Host "Error parsing '$offset_num' as a hex number."
    Write-Host $help
    exit
}

if ($start_num -gt 0x1000000)
{
    Write-Host "Warning: Start address is larger than the ROM file. Hint: ignore the leading number in the address."
}

$end_str = [System.Convert]::ToString($start_num + $offset_num, 16)
$end_str = "0x$end_str"

$start_str = "0x$Start"

Write-Host "$start_str - $end_str"
$objdump = Join-Path -Path $env:DEVKITARM -ChildPath "arm-none-eabi\bin\objdump.exe"
&$objdump -D -bbinary -marmv4t -Mforce-thumb --start-address="$start_str" --stop-address="$end_str" .\baserom.gba > .\baserom.dump
&$objdump -D -bbinary -marmv4t -Mforce-thumb --start-address="$start_str" --stop-address="$end_str" .\pokeemerald.gba > .\pokeemerald.dump
Invoke-Expression "$DiffTool .\baserom.dump .\pokeemerald.dump"
