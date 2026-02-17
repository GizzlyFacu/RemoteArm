@echo off
REM -----------Conan Build-----------

set CONAN_BUILD_DIR=conan-build
if not exist %CONAN_BUILD_DIR% (

	conan install . --profile=conan-profile/gcc-ccache --output-folder=%CONAN_BUILD_DIR% --build=missing
	if errorlevel 1 (
    	echo Conan Build failed.
    	pause
    	exit /b %ERRORLEVEL%
    )

	call %CONAN_BUILD_DIR%/conanbuild.bat
	
)else (
    echo Reconfiguring project...
    rmdir /s /q conan-build
    conan install . --profile=conan-profile/gcc-ccache --output-folder=%CONAN_BUILD_DIR% --build=missing
)

echo Conan Build successful.


REM -----------Meson Build-----------
set MESON_BUILD_DIR=meson-build
if not exist %MESON_BUILD_DIR% (
	meson setup %MESON_BUILD_DIR% --native-file %CONAN_BUILD_DIR%/conan_meson_native.ini
) else (

    echo Reconfiguring project...
    rmdir /s /q meson-build
    meson setup %MESON_BUILD_DIR% --native-file %CONAN_BUILD_DIR%/conan_meson_native.ini
)

echo Compiling...
meson compile -C %MESON_BUILD_DIR%
if %ERRORLEVEL% neq 0 (
    echo Meson Build failed.
    pause
    exit /b %ERRORLEVEL%
)

echo Build successful.
pause