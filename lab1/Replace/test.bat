
set PROGRAM=%~1

%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err


%PROGRAM% test-data\12312312345.txt 12312312345_out.txt 1231234 replaced
if ERRORLEVEL 1 goto err
fc.exe 12312312345_out.txt test-data\12312312345-replace-with-123replaced5.txt >nul
if ERRORLEVEL 1 goto err

%PROGRAM% test-data\12341234.txt 1234_out.txt 123 5
if ERRORLEVEL 1 goto err
fc.exe 1234_out.txt test-data\12341234-replace-123-with-5.txt >nul
if ERRORLEVEL 1 goto err

%PROGRAM% test-data\subway.txt subway_out.txt replaceit better
if ERRORLEVEL 1 goto err
fc.exe subway_out.txt test-data\subway-replaceit-with-better.txt >nul
if ERRORLEVEL 1 goto err

%PROGRAM% test-data\lorem.txt lorem_out.txt text replaced
if ERRORLEVEL 1 goto err
fc.exe lorem_out.txt test-data\lorem-replace-with-nothing.txt >nul
if ERRORLEVEL 1 goto err

echo OK
exit /b 0

:err
echo Program testing failed
exit /b 1
