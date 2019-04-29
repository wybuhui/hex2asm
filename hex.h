#ifndef _hex_H
#define _hex_H 

#include <stdio.h>	
#include <math.h>
#include <string.h>

int char2int( char temp );
int str2int( char *temp, char nu );

typedef enum record_type{
	data,					// Data
	EoF,					// End of file
	EsA,					// Extended Segment Address
	SsA,					// Start Segment Address
	ElA,					// Extended Linear Address
	SlA						// start Linear Address
} record;

/*
 * a line in hex file
 * used to buff a line
 *
 */
								// full name					size
typedef struct hex_line{
	char   start_code;			// start_code ":"				1byte
	int    data_len;			// the length of data filed		1byte
	int    addr;				// address						2bytes
	record record_t;			// record type 					4bytes
	char   data[50];				// data buff with size unknown	n bytes
	char   check;				// checksum						1byte
} hex_line_t;

typedef struct command{
	int  code;					// hex code						1byte
	char bytes;					// bytes						1byte
	char name[6];				// cmd name						6byte
	char operands[20];			// operands						20byte
} cmd;


#endif /* ifndef _hex_H */
