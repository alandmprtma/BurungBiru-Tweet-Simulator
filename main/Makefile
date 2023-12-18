CC = gcc
CFLAGS = -Wall -Werror -std=c11

SRC = ../modules/wordmachine/charmachine.c ../modules/liststatik/liststatik.c ../modules/listdin/listdin.c ../modules/wordmachine/wordmachine.c ../modules/time/time.c ../modules/time/datetime.c ../modules/stack/stack.c ../modules/queue/queue.c ../modules/matrix/matrix.c ../modules/listlinier/listlinier.c ../modules/graf/graf.c ../modules/pcolor/pcolor.c ../modules/prioqueuefren/prioqueuefren.c Pengguna/Pengguna.c Teman/Teman.c PermintaanPertemanan/PermintaanPertemanan.c KelompokTeman/disjointset.c Kicauan/Kicauan.c DrafKicauan/DrafKicauan.c Utas/utas.c SimpanMuat/SimpanMuat.c

TARGET = main

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
 $(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
 rm -f $(TARGET)