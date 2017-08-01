@echo off

REM Calculating correct current folder
SET modpath=%~dp0
SET modpath=%modpath:~0,-1%

REM Remove old drive mapping
subst p: /d > nul

REM Mount current folder
subst p: "%modpath%"

REM Build pbo files using pboproject and check for errors
pboproject +Clean -Engine=Arma3 -Key -Workspace=P:\ -Noisy -P +Mod="%modpath%\@zsn_visselpipa" -F +W -Z P:\zsn_visselpipa
if %errorlevel% neq 0 exit /b %errorlevel%

REM Remove drive mapping
subst p: /d
