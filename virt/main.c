char *UART_ADDR = (char *)0x09000000;

extern void hlt();

void print(char *buffer){
	unsigned int i = 0;
	while(buffer[i] != 0){
		*UART_ADDR = buffer[i]; 
		i++;
	}
}

int main(){
	print("Hello World!");
	hlt();
	return 0;
}
