
void printXY(int r, int c, char ch)
{
	char* vm = (char*) 0xb8000;
	vm += ( r * 80 + c ) * 2 + 3;
	*vm = ch;
}

void printDesi(int r, int c, char ch, char design)
{
	char* vm = (char*) 0xb8000;
	vm += ( r * 80 + c ) * 2 + 3;
	*(vm + 1) = design;
	*vm = ch;
}

void printColor(int r, int c, int design)
{
	char* vm = (char*) 0xb8000;
	vm += ( r * 80 + c ) * 2 + 4;
	*(vm) = design;
}


void clear()
	{
		for ( int r = 0 ; r < 25 ; r++ )
		{
			for ( int c = 0 ; c < 80 ; c++ )
				{
					printXY(r, c, ' ');
				}
		}
	}

void printStr(int r, int c, char* s)
{

	while(*s != '\0')
	{
		
		printXY(r,c,*s);
		c++;
		s++;
	}
}

void colorize()
	{
		int counter = 0;
		for ( int r = 0 ; r < 25 ; r++ )
			{
				for ( int c = 0 ; c < 80 ; c++ )
					{
						if ( counter == 0 )
							counter++;
						printColor(r, c, (counter % 14)+1 );
						counter++;
					}
			}
	}
void delay(int x)
	{
		for ( int i = 0 ; i < x ; i++ )
			{
				for ( int j = 0 ; j < x ; j++ )
					{
						
					}
			}
	}