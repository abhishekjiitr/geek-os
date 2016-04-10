//#include "chaiChing.h"
#include "../drivers/screen.h"
#include "../drivers/screen.c"

void main()
	{
		//delay(20000);

		clear();
		colorize();
		//printStr(0, 0, "khaliiinaa");

		char* geek = "geek-os";
		printStr(4, 35, "GEEK - OS");
		printStr(7, 19, "Our attempt to build a small OS on our own :)");
		
	}
