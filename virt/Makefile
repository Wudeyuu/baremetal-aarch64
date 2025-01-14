CC := gcc
AS := as
LINKER := ld
COPIER := objcopy
CROSS_COMPILE := 
OBJS := build/startup.o build/main.o
ELF_OUT := build/Kernel.elf
OUT := Kernel.img


all: makebin

qemu: makebin
	@qemu-system-aarch64 -M virt \
	            -cpu cortex-a72  \
	            -kernel $(OUT)   \
	            -display vnc=:1  \
	            -serial stdio
	            
makebin: $(ELF_OUT)
	@$(CROSS_COMPILE)$(COPIER) -O binary $(ELF_OUT) $(OUT)

$(ELF_OUT): $(OBJS)
	@$(CROSS_COMPILE)$(LINKER) -T linker.ld -o $(ELF_OUT) $(OBJS)

build/startup.o: startup.s build
	@$(CROSS_COMPILE)$(AS) -o build/startup.o startup.s

build/main.o: main.c build
	@$(CROSS_COMPILE)$(CC) -o build/main.o main.c -c

build:
	@mkdir build

clean:
	@rm -f $(OBJS) $(OUT) $(ELF_OUT)
