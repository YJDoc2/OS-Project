
include ../Makefile.config

USER_PROGRAMS=ball.exe clock.exe copy.exe livestat.exe manager.exe fractal.exe procstat.exe saver.exe shell.exe snake.exe sysstat.exe ttest.exe ttest2.exe ttest3.exe ttest4.exe ttest5.exe

all: $(USER_PROGRAMS)

%.o: %.c
	${CC} ${KERNEL_CCFLAGS} -I ../include $< -o $@

%.exe: %.o ../library/user-start.o ../library/baselib.a
	${LD} ${KERNEL_LDFLAGS} -Ttext 0x80000000 ../library/user-start.o $< ../library/baselib.a -o $@

clean:
	rm -rf *.exe *.o
