TARGET = bin/main
CC = gcc
CFLAGS = -I src/ -Wall -Wextra -Werror -O0 -g
CPPFLAGS = -MMD
.PHONY : clean

$(TARGET) : ./obj/src/geom/*.o ./obj/src/libgeom/*.a
	$(CC) $(CFLAGS) -o $@ $^ -lm

./obj/src/geom/*.o : ./src/geom/main.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

./obj/src/libgeom/*.a : ./obj/src/libgeom/*.o 
	ar rcs $@ $^

./obj/src/libgeom/*.o : ./src/libgeom/geom.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

run :
	bin/main

clean :
	rm ./obj/src/geom/*.d ./obj/src/geom/*.o ./obj/src/libgeom/*.d ./obj/src/libgeom/*.a ./obj/src/libgeom/*.o $(TARGET)

-include main.d geometry.d