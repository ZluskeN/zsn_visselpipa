@echo off

REM Calculating correct current folder
SET modpath=%~dp0
SET modpath=%modpath:~0,-1%

REM Remove old drive mapping
subst p: /d > nul

REM Mount current folder
subst p: "%modpath%"

REM Lookup DSSignFile folder from registry
for /F "Tokens=2* skip=2" %%A In ('REG QUERY "HKCU\SOFTWARE\Bohemia Interactive\dssignfile" /v "path" 2^>nul') do (set DSSIGNFILEPATH=%%B)
if not defined DSSIGNFILEPATH echo "Arma 3 Tools does not seem to be installed, signing will be disabled"

REM Build pbo files using pboproject and check for errors
pboproject +Clean -Engine=Arma3 -Key -Workspace=P:\ -Noisy -P +Mod="%modpath%\@zsn_visselpipa" -R -Z P:\zsn_visselpipa
if %errorlevel% neq 0 (
	type "temp\*.log"
	exit /b %errorlevel%
)

if defined DSSIGNFILEPATH (
	mkdir @zsn_visselpipa\Keys > nul 2> nul

	for %%k in (Keys\*.biprivatekey) do (
		echo Signing zsn_visselpipa with %%~nxk
		"%DSSIGNFILEPATH%\DSSignFile.exe" "%%k" "@zsn_visselpipa\Addons\zsn_visselpipa.pbo"
	)

	for %%k in (Keys\*.bikey) do (
		echo Copying %%~nxk to @zsn_visselpipa\Keys
		copy "%%k" "@zsn_visselpipa\Keys" > nul
	)
)

REM Remove drive mapping
subst p: /d
