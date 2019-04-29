#include <stdio.h>
#include <math.h>
#include <string.h>
#include "hex.h"
#include "hex_cmd.h"


#define Max_buff 4


int main(int argc, const char *argv[])
{
	char hex_format_flags = 0;
	char hex_format[3] = "hex";
	char is_hex = 0;
	int  read_index = 0;
	char read_buf[Max_buff] = "";
	cmd  command;

	FILE  *hexfile = NULL;

	hex_line_t  temp_line;
	
	// arguments 
	if (argc < 2) {
		printf("\n\t\t\x1b[92m Designed by wybuhui\n\x1b[0m");
		printf(" \n");
		printf("\x1b[91m\t     Usage: ./hex2asm [hexfile] \n\x1b[0m");

		return 1;
	}

	// file formats
	for (int i = 0; i < strlen( argv[1] ); i++) 
	{
		if ( argv[1][i] == '.' ) {
			hex_format_flags = i + 1;
			continue;
		}


		// start compare
		if (hex_format_flags) {
			if (argv[1][i] == hex_format[i - hex_format_flags]) {
				if ( strlen( argv[1] ) - i == 1) {
					// is hex file
					is_hex = 1;
				}
				continue;
			}
			break;
		}
	}


	if (!is_hex) {
		printf("\x1b[91m Input file format error! \n\x1b[0m");

		return 1;
	}


	// main body
	hexfile = fopen( argv[1], "r" );
	
	// read file line by line
	while(EOF != ( read_buf[0] = fgetc( hexfile ) ))
	{
		// wrong format line 
		if ( ':' != read_buf[0]) {
			while( '\n' != read_buf[0] && EOF != read_buf[0] )
				read_buf[0] = fgetc( hexfile );
		}

		temp_line.start_code = ':';
		
		//read data len
		read_buf[0] = fgetc( hexfile );
		read_buf[1] = fgetc( hexfile );

		temp_line.data_len = str2int( read_buf, 2 );
//		printf("temp_line.data_len = 0x%02X\n", temp_line.data_len);

		// read addr
		read_buf[0] = fgetc( hexfile );
		read_buf[1] = fgetc( hexfile );
		read_buf[2] = fgetc( hexfile );
		read_buf[3] = fgetc( hexfile );
		temp_line.addr = str2int( read_buf, 4 );

		memset( read_buf, 0, Max_buff );

		// read data type
		read_buf[0] = fgetc( hexfile );
		read_buf[1] = fgetc( hexfile );
		temp_line.record_t = str2int( read_buf, 2 );

		
		for (int i = 0; i < temp_line.data_len; i++) {
			
			memset( command.operands, 0, 20 );
			read_buf[0] = fgetc( hexfile );
			read_buf[1] = fgetc( hexfile );
			command.code = str2int( read_buf, 2 );

			memset( read_buf, 0, Max_buff );
			for (int j = 0; j < (code_bytes[command.code] - 1) * 2; j++) {
				if (0 == (j + 1) % 2) {
					i++;
				}
				read_buf[j] = fgetc( hexfile );
			}

			switch ( code_bytes[command.code] )
			{
				case 1:
					sprintf(command.operands, "0x%04X : %s %s\n", temp_line.addr + i, code_cmd[command.code], code_argvs[command.code]);
					break;

				case 2:
					if (0x85 < command.code && command.code < 0x90 ) {
						sprintf(command.operands, "0x%04X : %s 0x%s %s\n", temp_line.addr + i, code_cmd[command.code], read_buf, code_argvs[command.code]);}
					else
						sprintf(command.operands, "0x%04X : %s %s 0x%s\n", temp_line.addr + i, code_cmd[command.code], code_argvs[command.code], read_buf);
					break;

				case 3:
					sprintf(command.operands, "0x%04X : %s %s %s\n", temp_line.addr + i, code_cmd[command.code], code_argvs[command.code], read_buf);
					break;
			}
			printf("%s\n", command.operands);
		}

		

		while( '\n' != read_buf[0] && EOF != read_buf[0] )
			read_buf[0] = fgetc( hexfile );
	}
	

	fclose(hexfile);


	return 0;
}
