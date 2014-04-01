ripple:	ripple.o keyboard.o xterm_control.o
	gcc ripple.o keyboard.o xterm_control.o -o ripple
	
ripple.o:	ripple.c
	gcc -c ripple.c
	
keyboard.o:	keyboard.c
	gcc -c keyboard.c
	
xterm_control.o:	xterm_control.c
	gcc -c xterm_control.c
	
