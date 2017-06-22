@echo off
setlocal

@echo.
@echo ===== b2fJ .class to C =====
@echo.

rem home of the b2fJ installation
set "B2FJ_HOME=%~dp0.."
@echo   b2fJ Home: "%B2FJ_HOME%"

rem home of the jdk to use for compiling
if [%JAVA_HOME%] == [] (
    @echo   Java Home empty; javac must be in your CLASSPATH
    set "JC=java"
) else (
    @echo   Java Home: "%JAVA_HOME%"
    set "JC=%JAVA_HOME%\bin\java"
)
    rem @echo   Java CLASSPATH: "%CLASSPATH%"

set "LINK_CLASSPATH=.;%B2FJ_HOME%\redistr\lib\bcel-5.1.jar;%B2FJ_HOME%\redistr\lib\commons-cli-1.0.jar;%B2FJ_HOME%\lib\jtools.jar;%B2FJ_HOME%\lib\classes.jar"
set "OBJ_FILE=%~n1.o"

@echo.
@echo Linking classes:
@echo.
@echo on

%JC% -classpath "%LINK_CLASSPATH%" js.tinyvm.TinyVM --writeorder LE --classpath "%LINK_CLASSPATH%" -o %OBJ_FILE% %~n1
@echo off
if ERRORLEVEL 1 goto end

@echo.
@echo Creating C bytecode array:
@echo.
@echo on

"%B2FJ_HOME%\bin\ClassToC" "%OBJ_FILE%"
MOVE /Y java_code.h "%B2FJ_HOME%"\src\platform\c64

:end
@echo off
@echo.
@echo ============================

