second: libworld.so Practice02.o; g++ -osecond Practice02.o -L. -lworld -Wl,-rpath,.
libworld.so:	Printer.o Student.o; g++ -shared -olibworld.so Printer.o Student.o
Printer.o:  Printer.cpp; g++ -c Printer.cpp
Student.o:  Student.cpp; g++ -c Student.cpp
Practice02.o:  Practice02.cpp Printer.h Student.h; g++ -c Practice02.cpp
test.o:	test.cpp Student.h; g++ -c test.cpp 
test:	test.o Student.o; g++ -otest test.o Student.o /home/slayer143/Documents/Unity/src/unity.c
runtests:	test; ./test
clean: rm --force Printer.o Student.o Practice02.o test.o second test