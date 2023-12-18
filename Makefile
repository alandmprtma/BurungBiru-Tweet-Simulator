CC = gcc
CFLAGS = -Wall -Werror -std=c11

SRC =  modules/wordmachine/charmachine.c modules/time/datetime.c modules/graf/graf.c modules/listdin/listdin.c modules/listlinier/listlinier.c modules/liststatik/liststatik.c modules/matrix/matrix.c modules/pcolor/pcolor.c  modules/prioqueuefren/prioqueuefren.c modules/queue/queue.c modules/stack/stack.c modules/modules/time.c modules/wordmachine/wordmachine.c main/Pengguna/Pengguna.c main//balasan.c adt/draftkicauan.c main.c feat/io.c feat/misc.c feat/operational.c feat/savenload.c

TARGET = main

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)