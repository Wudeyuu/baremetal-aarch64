.extern stack
.global _start
.global hlt
_start:
	ldr x0, =stack
	mov sp, x0
	bl main
hlt:
	b hlt
