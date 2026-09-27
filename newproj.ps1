param(
    [Parameter(Mandatory=$true)]
    [string]$Name
)

$base = "E:\code"
$target = Join-Path $base $Name

if (Test-Path $target) {
    Write-Host "文件夹已存在: $target" -ForegroundColor Yellow
    exit 1
}

Copy-Item -Recurse (Join-Path $base "_template") $target
Write-Host "已创建: $target" -ForegroundColor Green
Write-Host "用以下命令打开: code `"$target`"" -ForegroundColor Cyan