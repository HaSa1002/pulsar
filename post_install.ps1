$src = Resolve-Path $Args[0]
$dir = Resolve-Path ($Args[0]+"/..")
cd $src
Get-ChildItem -Include *.dll -Recurse | ForEach-Object {cp $_.FullName (Join-Path $dir $_.Name)}
Get-ChildItem -Include *.dll -Recurse | ForEach-Object {echo (Join-Path $dir $_.Name)}
Get-ChildItem -Include *.exe -Recurse | Where-Object {$_.Name -ne "sanitycheckcpp.exe" -and $_.Name -notlike "*_test*"} | ForEach-Object {cp $_.FullName (Join-Path $dir $_.Name)}