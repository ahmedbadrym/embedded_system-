CC = arm-none-eabi-
CFLAGS = -g -mcpu=cortex-m4 -mthumb -gdwarf-2
INCS = -I.
LIBS =
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
SRC2 = $(wildcard *.s)
OBJ2 = $(SRC2:.s=.o)
PRJ = toggle-cortex-m4

ALL: $(PRJ).bin
	@echo "-- build is done --"


%.o: %.c
	$(CC)gcc -c $(CFLAGS) $(INCS) $< -o $@

$(PRJ).elf: $(OBJ) 
	$(CC)ld -T linker-script.ld $(OBJ) $(LIBS) -o $@ -Map=map_file.map
	cp $(PRJ).elf $(PRJ).axf

$(PRJ).bin: $(PRJ).elf
	$(CC)objcopy -O binary $< $@ 

clean:
	rm -f *.elf *.bin

clean-all:
	rm -f *.o *.elf *.bin 
