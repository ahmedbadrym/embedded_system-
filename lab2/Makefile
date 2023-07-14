CC = arm-none-eabi-
CFLAGS = -g -mcpu=arm926ej-s -gdwarf-2
INCS = -I.
LIBS =
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
SRC2 = $(wildcard *.s)
OBJ2 = $(SRC2:.s=.o)
PRJ = toggle-led-cortex-m3

ALL: $(PRJ).bin
	@echo "--build is done--"


%.o: %.c
	$(CC)gcc -c $(CFLAGS) $(INCS) $< -o $@

$(PRJ).elf: $(OBJ) 
	$(CC)ld -T linker-script.ld $(OBJ)  $(LIBS) -o $@ -Map=map_file.map

$(PRJ).bin: $(PRJ).elf
	$(CC)objcopy -O binary $< $@ 

clean:
	rm *.elf *.bin

clean-all:
	rm *.o *.elf *.bin 
