/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Program Name:    variableTypes.cpp                                        */
/* Programmer:      Mark Hooper - mr876805@dal.ca                            */
/* Last Updated:    APR-07-2019                                              */
/* Description:                                                              */
/*  Examples of types, their size, and printf(formatting options) for        */
/*  output to the console.                                                   */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include "stdlib.h"
#include "stdio.h"

#define BYTE1 0xFF;
#define BYTE2 0xFFFF;
#define BYTE4 0xFFFFFFFF;
#define BYTE8 0xFFFFFFFFFFFFFF;


int main(void) {
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	/*    The following are the basic arithmetic types avaible in the c-standrd library.  */
        /*    Variable declarations that are adjacent are equivalent.                         */
	/*    Sources:  https://en.wikipedia.org/wiki/C_data_types                            */
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	printf("***********************     DATA TYPES     ****************************\n");
	printf("-----------------------------------------------------------------------\n");
	printf("\tTYPE                    OUTPUT                    SIZE \n");
	printf("-----------------------------------------------------------------------\n");

	/********************* Characters - 1 Byte, 8 Bits ********************/

	/* signed */
	char c = 'a';					
	signed char sc = 's';	
	printf("\tchar:                   %-32c%d\n",c, sizeof(char));
	printf("\tsigned char:            %-32c%d\n", sc, sizeof(signed char));


	/* unsigned */
	unsigned char uc = 'u';			
	printf("\tunsigned char:          %-32c%d\n", uc, sizeof(unsigned char));

	/********************* Short - 2 Bytes, 16 Bits ***********************/

	/* signed */
	short s = BYTE2;					
	short int si = BYTE2;				
	signed short ss = BYTE2;			
	signed short int ssi = BYTE2;
	printf("\tshort:                  %-32hi%d\n", s, sizeof(short));
	printf("\tshort int:              %-32hi%d\n", si, sizeof(short int));
	printf("\tsigned short:           %-32hi%d\n", ss, sizeof(signed short));
	printf("\tsigned short int:       %-32hi%d\n", ssi, sizeof(signed short int));

	/* unsigned */
	unsigned short us = BYTE2;			
	unsigned short int usi = BYTE2;		
	printf("\tunsigned short:         %-32hu%d\n", us, sizeof(unsigned short));
	printf("\tunsigned short:         %-32hu%d\n", usi, sizeof(unsigned short));

	/*** Int - 2 or 4 Bytes, 16 or 32 Bits (depends on system/compiler) ***/

	/* signed */
	int i = BYTE4;						
	signed S = BYTE4;					
	signed int Si = BYTE4;				
	printf("\tint:                    %-32d%d\n", i, sizeof(int));
	printf("\tsigned:                 %-32d%d\n", S, sizeof(signed));
	printf("\tsigned int:             %-32d%d\n", Si, sizeof(signed int));


	/* unsigned */
	unsigned U = BYTE4;					
	unsigned int Ui = BYTE4;			
	printf("\tunsigned:               %-32u%d\n", U, sizeof(unsigned));
	printf("\tunsigned int:           %-32u%d\n", Ui, sizeof(unsigned int));


	/*** Long Int - 4 or 8 Bytes, 32 or 64 Bits (depends on system/compiler) ***/

	/* signed */
	long l = BYTE8;						
	long int li = BYTE8;				
	signed long sl = BYTE8;				
	signed long int sli = BYTE8;		
	printf("\tlong:                   %-32li%d\n", l, sizeof(long));
	printf("\tlong int:               %-32li%d\n", li, sizeof(long int));
	printf("\tsigned long:            %-32li%d\n", sl, sizeof(signed long));
	printf("\tsigned long int:        %-32li%d\n", sli, sizeof(signed long int));

	/* unsigned */
	unsigned long ul = BYTE8;			
	unsigned long int uli = BYTE8;		
	printf("\tunsigned long:          %-32lu%d\n", ul, sizeof(unsigned long));
	printf("\tunsigned long int:      %-32lu%d\n", uli, sizeof(unsigned long int));

	/* think of additional "long" keywords as just adding 2 or 4 bytes to the size */

	/* signed */
	long long ll = BYTE8;				
	long long int lli = BYTE8;			
	signed long long sll = BYTE8;		
	signed long long int slli = BYTE8;	
	printf("\tlong long:              %-32lli%d\n", ll, sizeof(long long));
	printf("\tlong long int:          %-32lli%d\n", lli, sizeof(long long int));
	printf("\tsigned long long:       %-32lli%d\n", sll, sizeof(signed long long));
	printf("\tsigned long long int:   %-32lli%d\n", slli, sizeof(signed long long int));


	/* unsigned */
	unsigned long long ull = BYTE8;		
	unsigned long long int ulli = BYTE8;
	printf("\tunsigned long long:     %-32llu%d\n", ull, sizeof(unsigned long long));
	printf("\tunsigned long long int: %-32llu%d\n", ulli, sizeof(unsigned long long int));


	/************ Float - 4 Bytes, 32 Bits - "double" multiplies the size by 2. ****/
	float f = 0.1f;						
	double d = 0.1f;					
	long double ld = 0.1f;				
	printf("\tfloat:                  %-32f%d\n", f, sizeof(float));
	printf("\tdouble:                 %-32lf%d\n", d, sizeof(double));
	printf("\tlong double:            %-32llf%d\n", ld, sizeof(long double));



	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	/*    Here are some examples of how printf() format specifiers work.                  */
	/*    Sources:  http://www.cplusplus.com/reference/cstdio/printf/                     */
	/*                                                                                    */
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	printf("\n\n\n***********************  printf() Formats   ***************************\n\n");
	int example = 0xFFFFFFFF;
	char formatString[] = "%[flags][width][.precision][length]specifier";
	printf("\tThis is how format specifiers are arranged: \n\t\t%s\n\n", formatString);
	printf("\tWith an int as our argument with a value of 0xFFFFFFFF, \
	\n\twe obtain the following output: \n\n");
	printf("\tFORMAT SPECIFIER USED       RESULT\n");
	printf("-----------------------------------------------------------------------\n");
	printf("\t\t%%d                   %d\n",example);		
	printf("\t\t%%i                   %i\n", example);		
	printf("\t\t%%-d                  %-d\n", example);		
	printf("\t\t%%+d                  %+d\n", example);		
	printf("\t\t%%u                   %u\n", example);		
	printf("\t\t%%+u                  %+u\n", example);		
	printf("\t\t%%-u                  %-u\n", example);		
	printf("\t\t%%hi                  %hi\n", example);		
	printf("\t\t%%hu                  %hu\n", example);		
	printf("\t\t%%hhi                 %hhi\n", example);	
	printf("\t\t%%hhu                 %hhu\n", example);	
	printf("\t\t%%x                   %x\n", example);		
	printf("\t\t%%X                   %X\n", example);		
	printf("\t\t%%16x                 %16x\n", example);	
	printf("\t\t%%.16x                %.16x\n", example);	
	printf("\t\t%%016x                %016x\n", example);	
	printf("\t\t%%8x                  %8x\n", example);		
	printf("\t\t%%.8x                 %.8x\n", example);	
	printf("\t\t%%08x                 %08x\n", example);	
	printf("\t\t%%4x                  %4x\n", example);		
	printf("\t\t%%.4x                 %.4x\n", example);	
	printf("\t\t%%04x                 %04x\n", example);	
	printf("\t\t%%016hhx              %016hhx\n", example);	  
	printf("\t\t%%04hx                %04hx\n", example);	
	printf("\t\t%%4hx                 %4hx\n", example);	
	printf("\t\t%%hx                  %hx\n", example);		
	printf("\t\t%%6hx                 %6hx\n", example);	
	printf("\t\t%%06hx                %06hx\n", example);	
	printf("\t\t%%#06hx               %#06hx\n", example);	
	printf("\t\t%%#6hx                %#6hx\n", example);	
	printf("\t\t%%c                   %c\n", example);		
	printf("\t\t%%1hhu                %1hhu\n", example);	
	printf("\t\t%%p                   %p\n", &example);		

	return 0;
}
