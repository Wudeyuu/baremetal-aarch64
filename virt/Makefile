CC := gcc
AS := as
LINKER := ld
COPIER := objcopy
OBJS := build/startup.o build/main.o
ELF_OUT := build/Kernel.elf
OUT := Kernel.img


all: makebin

qemu: makebin
	@qemu-system-aarch64 -M virt \
	            -cpu cortex-a72  \
	            -kernel $(OUT)   \
	            -nographic       

makebin: $(ELF_OUT)
	@$(COPIER) -O binary $(ELF_OUT) $(OUT)

$(ELF_OUT): $(OBJS)
	@$(LINKER) -T linker.ld -o $(ELF_OUT) $(OBJS)

build/startup.o: startup.s build
	@$(AS) -o build/startup.o startup.s

build/main.o: main.c build
	@$(CC) -o build/main.o main.c -c

build:
	@mkdir build

clean:
	@rm -f $(OBJS) $(OUT) $(ELF_OUT)
