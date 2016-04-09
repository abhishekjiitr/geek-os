/* Print a char on the screen at col , row , or at cursor position */
void print_char ( char character , int col , int row , char attribute_byte ) {
	/* Create a byte ( char ) pointer to the start of video memory */
	unsigned char * vidmem = ( unsigned char *) VIDEO_ADDRESS ;
	/* If attribute byte is zero , assume the default style . */
	if (! attribute_byte ) {
		attribute_byte = WHITE_ON_BLACK ;
	}
	/* Get the video memory offset for the screen location */
	int offset ;
	/* If col and row are non - negative , use them for offset . */
	if ( col >= 0 && row >= 0) {
		offset = get_screen_offset (col , row );
		/* Otherwise , use the current cursor position . */
	} else {
		offset = get_cursor ();
	}
// If we see a newline character , set offset to the end of
// current row , so it will be advanced to the first col
// of the next row.
	if ( character == '\n') {
		int rows = offset / (2 * MAX_COLS );
		offset = get_screen_offset (79 , rows );
// Otherwise , write the character and its attribute byte to
// video memory at our calculated offset .
	} else {
		vidmem [ offset ] = character ;
		vidmem [ offset + 1] = attribute_byte ;
	}
// Update the offset to the next character cell , which is
// two bytes ahead of the current cell .
	offset += 2;
// Make scrolling adjustment , for when we reach the bottom
// of the screen .
	offset = handle_scrolling ( offset );
// Update the cursor position on the screen device .
	set_cursor ( offset );
}

int get_cursor() {
// The device uses its control register as an index
// to select its internal registers , of which we are
// interested in:
	// reg 14: which is the high byte of the cursor 's offset
// reg 15: which is the low byte of the cursor 's offset
// Once the internal register has been selected , we may read or
// write a byte on the data register .
	port_byte_out ( REG_SCREEN_CTRL , 14);
	int offset = port_byte_in ( REG_SCREEN_DATA ) << 8;
	port_byte_out ( REG_SCREEN_CTRL , 15);
	offset += port_byte_in ( REG_SCREEN_DATA );
// Since the cursor offset reported by the VGA hardware is the
// number of characters , we multiply by two to convert it to
// a character cell offset .
	return offset * 2;
}

void print_at ( char * message , int col , int row ) {
// Update the cursor if col and row not negative .
	if ( col >= 0 && row >= 0) {
		set_cursor ( get_screen_offset (col , row ));
	}
// Loop through each char of the message and print it.
	int i = 0;
	while ( message [i] != 0) {
		print_char ( message [i++] , col , row , WHITE_ON_BLACK );
	}
}

void print ( char * message ) {
	print_at ( message , -1, -1);
}

void clear_screen () {
	int row = 0;
	int col = 0;
	/* Loop through video memory and write blank characters . */
	for (row = 0; row < MAX_ROWS ; row ++) {
		for (col = 0; col < MAX_COLS ; col ++) {
			print_char (' ', col , row , WHITE_ON_BLACK );
		}
	}
// Move the cursor back to the top left .
	set_cursor ( get_screen_offset (0, 0));
}


