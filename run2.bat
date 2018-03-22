for /f %%f in ('dir /b sequences\') do start /b /wait Debug\embedded.exe sequences\%%f
pause
