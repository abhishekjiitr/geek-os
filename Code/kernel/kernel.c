#include "../drivers/screen.c"

void main()
	{
		//delay(30000);
		int name_offset = 25, y_offset = 9;
		clear();
		colorize();
		printStr(0, 0, "================================================================================");
		printStr(4, 35, "GEEK - OS");
		printStr(7, 19, "Our attempt to build a small OS on our own :)");
		printStr(y_offset, name_offset, "Abhishek Jaisingh (14114002)");
		printStr(y_offset+1, name_offset, "Abhishek Jaisingh (14114002)");
		printStr(y_offset+2, name_offset, "Abhishek Jaisingh (14114002)");
		printStr(y_offset+3, name_offset, "Abhishek Jaisingh (14114002)");
		printStr(y_offset+4, name_offset, "Abhishek Jaisingh (14114002)");
		printStr(y_offset+5, name_offset, "Abhishek Jaisingh (14114002)");
		printStr(y_offset+6, name_offset+4, "Vaskar Ray Choudhary");
		
		printStr(24, 0, "================================================================================");
		
		
	}
