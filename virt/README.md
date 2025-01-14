## VIRT MACHINE

In this folder you'll find some example code for machine VIRT(qemu).

### BUILD

For build this HelloWorld, just run ```make makebin``` or ```make```, you'll recive a ```Kernel.img``` file, which is the kernel.

For build and run directly, run ```make qemu```.

For close qemu, in other terminal execute ```ps -a```, find the PID of qemu's process, and kill it.

For setting your cross compiler, add ```CROSS_COMPILE=your cross compiler``` after the word ```make```
