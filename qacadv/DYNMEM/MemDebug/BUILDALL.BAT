@echo off

set COMPILER=cl

echo Building the mcb object file
echo.
echo %COMPILER% /W4 /c mcb.c

echo Building the "bad" programs
echo.
%COMPILER% /W4 bad1.c mcb.obj
del bad1.obj

%COMPILER% /W4 bad2.c mcb.obj
del bad2.obj

%COMPILER% /W4 bad3.c mcb.obj
del bad3.obj

