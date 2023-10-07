:loop
give.exe
text.exe
answer.exe
fc sort.out sort.ans
if not errorlevel 1 goto loop
