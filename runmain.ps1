$name = $args[0]
if ($name.EndsWith('.c')) {
    $name = $name.substring(0, $name.LastIndexOf('.c'))
}
$out = New-TemporaryFile
Rename-Item -Path "$($out.FullName)" -NewName "$($out.FullName + '.exe')"
$out = $out.FullName + '.exe'
gcc -Wall -pedantic -std=c11 "$name.c" "${name}_main.c" -o "$out"
& "$out"
Remove-Item "$out"
