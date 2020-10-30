
@echo on

IF /i %1=="Debug" (
	IF NOT EXIST "../../assets" mkdir "../../assets"
	IF NOT EXIST "../../assets/cpl" mkdir "../../assets/cpl"
	IF NOT EXIST "../../assets/cpl/shd" mkdir "../../assets/cpl/shd"

	for /r %%f in ("./cs_*.hlsl") do (
		fxc /T cs_5_0 /Fo "../../assets/cpl/shd/%%~nf.shader" "%%~f"
	)
	for /r %%f in ("./gs_*.hlsl") do (
		fxc /T gs_5_0 /Fo "../../assets/cpl/shd/%%~nf.shader" "%%~f"
	)
	for /r %%f in ("./ps_*.hlsl") do (
		fxc /T ps_5_0 /Fo "../../assets/cpl/shd/%%~nf.shader" "%%~f"
	)
	for /r %%f in ("./vs_*.hlsl") do (
		fxc /T vs_5_0 /Fo "../../assets/cpl/shd/%%~nf.shader" "%%~f"
	)
	exit /B
)
ELSE (
	IF NOT EXIST "../../assets" mkdir "../../assets"
	IF NOT EXIST "../../assets/cpl" mkdir "../../assets/cpl"
	IF NOT EXIST "../../assets/cpl/shd" mkdir "../../assets/cpl/shd"

	for /r %%f in ("./cs_*.hlsl") do (
		fxc /WX /Qstrip_debug /O3 /T cs_5_0 /Fo "../../assets/cpl/shd/%%~nf.shader" "%%~f"
	)
	for /r %%f in ("./gs_*.hlsl") do (
		fxc /WX /Qstrip_debug /O3 /T gs_5_0 /Fo "../../assets/cpl/shd/%%~nf.shader" "%%~f"
	)
	for /r %%f in ("./ps_*.hlsl") do (
		fxc /WX /Qstrip_debug /O3 /T ps_5_0 /Fo "../../assets/cpl/shd/%%~nf.shader" "%%~f"
	)
	for /r %%f in ("./vs_*.hlsl") do (
		fxc /WX /Qstrip_debug /O3 /T vs_5_0 /Fo "../../assets/cpl/shd/%%~nf.shader" "%%~f"
	)
	exit /B
)

@echo on
