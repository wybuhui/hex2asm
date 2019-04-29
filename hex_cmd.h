#ifndef _hex_cmd_H
#define _hex_cmd_H

// define code map here
char code_bytes[0xFF + 1] = { 1, 2, 3, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,   //16
	3, 2, 3, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 2, 1, 1, 2, 2,     //22
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 2, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 2, 2, 2, 3, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2,
	2, 3, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 3, 2, 2, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 1, 2, 3, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 1, 1, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 1,
	2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 0, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
	2, 2, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 3,
	1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};


char code_cmd[0xFF + 1][6] = { "NOP", "AJMP", "LJMP", "RR", "INC", "INC",
	 "INC", "INC", "INC", "INC", "INC", "INC", "INC", "INC", "INC", "INC",
	 "JBC", "ACALL", "LCALL", "RRC", "DEC", "DEC", "DEC", "DEC", "DEC",
	 "DEC", "DEC", "DEC", "DEC", "DEC", "DEC", "DEC", "JB", "AJMP", "RET",
	 "RL", "ADD", "ADD", "ADD", "ADD", "ADD", "ADD", "ADD", "ADD", "ADD",
	 "ADD", "ADD", "ADD", "JNB", "ACALL", "RETI", "RLC", "ADDC", "ADDC", 
	 "ADDC", "ADDC", "ADDC", "ADDC", "ADDC", "ADDC", "ADDC", "ADDC", "ADDC",
	 "ADDC", "JC", "AJMP", "ORL", "ORL", "ORL", "ORL", "ORL", "ORL", "ORL", 
	 "ORL", "ORL", "ORL", "ORL", "ORL", "ORL", "ORL", "JNC", "ACALL", "ANL",
	 "ANL", "ANL", "ANL", "ANL", "ANL", "ANL", "ANL", "ANL", "ANL", "ANL",
	 "ANL", "ANL", "ANL", "JZ", "AJMP", "XRL",  "XRL", "XRL", "XRL", "XRL",
	 "XRL", "XRL", "XRL", "XRL", "XRL", "XRL", "XRL", "XRL", "XRL", "JNZ",
	 "ACALL", "ORL", "JMP", "MOV", "MOV", "MOV", "MOV", "MOV", "MOV", "MOV",
	 "MOV", "MOV", "MOV", "MOV", "MOV", "SJMP", "AJMP", "ANL", "MOVC", "DIV",
	 "MOV", "MOV", "MOV", "MOV", "MOV", "MOV", "MOV", "MOV", "MOV", "MOV",
	 "MOV", "MOV", "ACALL", "MOV", "MOVC", "SUBB", "SUBB", "SUBB", "SUBB",
	 "SUBB", "SUBB", "SUBB", "SUBB", "SUBB", "SUBB", "SUBB", "SUBB", "ORL",
	 "AJMP", "MOV", "INC", "MUL", "", "MOV", "MOV", "MOV", "MOV", "MOV",
	 "MOV", "MOV", "MOV", "MOV", "MOV", "ANL", "ACALL", "CPL", "CPL", "CJNE",
	 "CJNE", "CJNE", "CJNE", "CJNE", "CJNE", "CJNE", "CJNE", "CJNE", "CJNE",
	 "CJNE", "CJNE", "PUSH", "AJMP", "CLR", "CLR", "SWAP", "XCH",  "XCH",
	 "XCH", "XCH", "XCH", "XCH", "XCH", "XCH", "XCH", "XCH", "XCH", "POP",
	 "ACALL", "SETB", "SETB", "DA", "DJNZ", "XCHD", "XCHD", "DJNZ", "DJNZ",
	 "DJNZ", "DJNZ", "DJNZ", "DJNZ", "DJNZ", "DJNZ", "MOVX", "AJMP", "MOVX",
	 "MOVX", "CLR", "MOV", "MOV", "MOV", "MOV", "MOV", "MOV", "MOV", "MOV", 
	 "MOV", "MOV", "MOV", "MOVX", "ACALL", "MOVX", "MOVX", "CPL", "MOV",
	 "MOV", "MOV", "MOV", "MOV", "MOV", "MOV", "MOV", "MOV", "MOV", "MOV"};


char code_argvs[0xFF + 1][11] = { "", "", "", "A", "A", "", "@R0", "@R1", "R0",
	"R1", "R2", "R3", "R4", "R5", "R6", "R7", "", "", "", "A", "A", "", "@R0",
	"@R1", "R0", "R1", "R2", "R3", "R4", "R5", "R6", "R7", "", "", "", "A", 
	"A,", "A,", "A, @R0", "A, @R1", "A, R0", "A, R1", "A, R2", "A, R3", "A, R4",
	"A, R5", "A, R6", "A, R7", "", "", "",  "A", "A,", "A,", "A, @R0", "A, @R1",
	"A, R0", "A, R1", "A, R2", "A, R3", "A, R4", "A, R5", "A, R6", "A, R7", 
	"", "", ", A", "", "A,", "A,", "A, @R0", "A, @R1", "A, R0", "A, R1", "A, R2",
	"A, R3", "A, R4", "A, R5", "A, R6", "A, R7", "", "", ", A", "", "A,", "A,", 
	"A, @R0", "A, @R1", "A, R0", "A, R1", "A, R2", "A, R3", "A, R4", "A, R5", 
	"A, R6", "A, R7", "", "", ", A", "", "A,", "A,", "A, @R0", "A, @R1", "A, R0",
	"A, R1", "A, R2", "A, R3", "A, R4", "A, R5", "A, R6", "A, R7", "", "", "C,",
	"@A+DPTR", "A,", "", "@R0,", "@R1,", "R0,", "R1,", "R2,", "R3,", "R4,", "R5,", 
	"R6,", "R7,", "", "", "C,", "A, @A+PC", "AB", "", ",@R0", "@R1", ", R0", ", R1",
	", R2", ", R3", ", R4", ", R5", ", R6", ", R7", "DPTR,", "", ", C", "A, @A+DPTR",
	"A,", "A,", "A, @R0", "A, @R1", "A, R0", "A, R1", "A, R2", "A, R3", "A, R4",
	"A, R5", "A, R6", "A, R7", "C,", "", "C,", "DPTR", "AB", "", "@R0", "@R1", "R0,",
	"R1,", "R2,", "R3,", "R4,", "R5,", "R6,", "R7,", "C,", "", "", "C", "A,", "A,", 
	"@R0,", "@R1,", "R0,", "R1,", "R2,", "R3,", "R4,", "R5,", "R6,", "R7,", "C,", "",
	"", "C", "A", "A,", "A, @R0", "A, @R1", "A, R0", "A, R1","A, R2", "A, R3", "A, R4",
	"A, R5", "A, R6", "A, R7", "", "", "", "C", "A", "", "A, @R0", "A, @R1", "R0,",
	"R1,", "R2,", "R3,", "R4,", "R5,", "R6,", "R7,", "A, @DPTR", "", "A, @R0", "A, @R1",
	"A", "A,", "A, @R0", "A, @R1", "A, R0", "A, R1", "A, R2", "A, R3", "A, R4", "A, R5",
	"A, R6", "A, R7", "@DPTR, A", "","@R0, A", "@R1, A", "A", ", A", "@R0, A", "@R1, A",
	"R0, A", "R1, A",  "R2, A", "R3, A", "R4, A", "R5, A", "R6, A", "R7, A"};
	

#endif
