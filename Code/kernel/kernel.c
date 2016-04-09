void test();
void main()
	{
		char* video_memory = (char*) 0xb8000;
		// *video_memory = 'X';
		for ( int i = 0 ; i < 80 ; i++ )
			{
				*(video_memory) = '2';
				*(video_memory+2) = 1;
				video_memory += 2;
			}
		 // test();
	}