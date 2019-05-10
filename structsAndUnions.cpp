/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Program Name:    structsAndUnions.cpp                                     */
/* Programmer:      Mark Hooper - mr876805@dal.ca                            */
/* Last Updated:    APR-09-2019                                              */
/* Description:     Examples of structs and unions.			     */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#include "stdlib.h"
#include "stdio.h"


/* this is a struct, the content is contiguous in memory. */
struct byte4s{
	unsigned char LL;	// 1 byte
	unsigned char LH;	// 1 byte
	unsigned char HL;	// 1 byte
	unsigned char HH;       // 1 byte
};

/* this is a union, the memory contents overlap in memory */
union byte4u{
	/* The next 4 fields occupy the same 4 bytes in memory! */
	int i;			// 4 bytes
	unsigned int ui;	// 4 bytes
	unsigned short s[2];	// 2*2 bytes
	unsigned char c[4];	// 4*1 bytes
};

/* this struct allows you to specify a given number of bits for a field*/
struct fields {
	unsigned char lowNibble : 4;	// 4 bits
	unsigned char highNibble : 4;	// 4 bits
};

/* And this is just pure freakin magic */
/* All of this content (all 2 bytes of it) overlaps in memory */
union godMode {
	unsigned short uWord;
	short sWord;
	unsigned char uBytes[2];
	char sBytes[2];
	struct nibble {
		unsigned short LL : 4;
		unsigned short LH : 4;
		unsigned short HL : 4;
		unsigned short HH : 4;
	}nib;			//we can call this guy nib eg: nib.LL
	struct bits {
		unsigned short b0 : 1;
		unsigned short b1 : 1;
		unsigned short b2 : 1;
		unsigned short b3 : 1;
		unsigned short b4 : 1;
		unsigned short b5 : 1;
		unsigned short b6 : 1;
		unsigned short b7 : 1;
		unsigned short b8 : 1;
		unsigned short b9 : 1;
		unsigned short b10 : 1;
		unsigned short b11 : 1;
		unsigned short b12 : 1;
		unsigned short b13 : 1;
		unsigned short b14 : 1;
		unsigned short b15 : 1;
	}b;			//same with this call him b ex b.b12
};

int main(void){
	/* You can create a struct and initialize it */
	struct byte4s Sa = { 0xFF, 0xFF, 0xFF, 0xFF };			   //this guy is 4 bytes full of 1's
	struct byte4s Sb = {Sb.LL = 0, Sb.LH = 0, Sb.HL = 0, Sb.HH = 0 };  //this is all zeroes

	/* unions overlap in memory so we can initialize them to some value so 
	   long as we make sure that we have enough room for them, if you're not sure
	   best bet is to use our old friend sizeof() or your compiler will 
	   not be a happy camper. */
	
	
	/* let's just print them all out first */
	printf(" struct byte4s  has a size of %d bytes\n", (int)sizeof(struct byte4s));
	printf(" union  byte4u  has a size of %d bytes\n", (int)sizeof(union byte4u));
	printf(" struct fields  has a size of %d bytes\n",(int)sizeof(struct fields));
	printf(" union  godMode has a size of %d bytes\n", (int)sizeof(union godMode));

	/* you should check to make sure that it's the size you think it is for example 
	take a look at this guy: */
	struct naughty {
		char ImTotallyOnly1Byte;	//1
		short ImTotallyOnly2Bytes;	//+2
		char ITooAmTotallyOnly1Byte;	//+1 = 4
	};
	printf(" struct naughty has a size of %d bytes\n\n", (int)sizeof(struct naughty));

	/*depending on how your compiler wants to manage memory content that may have
	not worked as expected...*/

	/* so let's make some more variables, with the union, we can just set the 
	largest field, which in this case is one of the int (Ua.i, or Ua.ui)
	because all fields share the same memory space. */
	union byte4u Ua = { Ua.i = 0xFFFFFFFF };	//again filled with ones

	struct fields Sf = { 0xFF, 0x00 };		//should be 0x0F

	union godMode omgHax = { 0xFFFF };		//ones yet again

	/* so a struct is basically a poor mans class everything is public, 
	   constructors... destructors... setters.. getters.. methods in 
	   general.. none of that here. observe: */
	printf(" struct byte4s Sa 's initial values:  \n");
	printf(" Sa.LL %02X\n", Sa.LL);
	printf(" Sa.LH %02X\n", Sa.LH);
	printf(" Sa.HL %02X\n", Sa.HL);
	printf(" Sa.HH %02X\n\n", Sa.HH);

	/* You can change any one of the fields you're interested in like so */
	Sa.LL = 0;
	Sa.HL = 0;

	/* print it again.. */
	printf(" struct byte4s Sa 's manipulated values:  \n");
	printf(" Sa.LL: %02X\n", Sa.LL);
	printf(" Sa.LH: %02X\n", Sa.LH);
	printf(" Sa.HL: %02X\n", Sa.HL);
	printf(" Sa.HH: %02X\n\n", Sa.HH);

	/* we can also assign a struct the value(s) of another struct of the same type*/
	printf(" struct byte4s Sb 's initial values:  \n");
	printf(" Sb.LL %02X\n", Sb.LL);
	printf(" Sb.LH %02X\n", Sb.LH);
	printf(" Sb.HL %02X\n", Sb.HL);
	printf(" Sb.HH %02X\n\n", Sb.HH);
	
	/* let's assign it Sa's values */
	Sb = Sa;

	/* print it again.. */
	printf(" struct byte4s Sb 's values after assignment:  \n");
	printf(" Sb.LL: %02X\n", Sb.LL);
	printf(" Sb.LH: %02X\n", Sb.LH);
	printf(" Sb.HL: %02X\n", Sb.HL);
	printf(" Sb.HH: %02X\n\n", Sb.HH);

	/* so what about unions?  well let's print some initial content out*/
	printf(" union byte4U Ua 's initial values:  \n");
	printf(" Ua.i(hex): %08X\n", Ua.i);
	printf(" Ua.i:      %i\n", Ua.i);
	printf(" Ua.ui:     %u\n", Ua.ui);
	printf(" Ua.s[0]:   %hu\n", Ua.s[0]);
	printf(" Ua.s[1]:   %hu\n", Ua.s[1]);
	printf(" Ua.c[0]:   %02X\n", Ua.c[0]);		// printing the hex values
	printf(" Ua.c[1]:   %02X\n", Ua.c[1]);		// for these since they are
	printf(" Ua.c[2]:   %02X\n", Ua.c[2]);		// all initialized to 
	printf(" Ua.c[3]:   %02X\n\n", Ua.c[3]);	// 0xFF

	/* So lets change the character fields */
	Ua.c[0] = 'W';
	Ua.c[1] = 'O';
	Ua.c[2] = 'W';
	Ua.c[3] = '\0';

	/* Try printing again */
	printf(" union byte4U Ua 's reassigned values:  \n");
	printf(" Ua.i(hex): %08X\n", Ua.i);
	printf(" Ua.i:      %i\n", Ua.i);
	printf(" Ua.ui:     %u\n", Ua.ui);
	printf(" Ua.s[0]:   %hu\n", Ua.s[0]);
	printf(" Ua.s[1]:   %hu\n", Ua.s[1]);
	printf(" Ua.c[0]:   %c\n", Ua.c[0]);		
	printf(" Ua.c[1]:   %c\n", Ua.c[1]);		
	printf(" Ua.c[2]:   %c\n", Ua.c[2]);		
	printf(" Ua.c[3]:   %c\n\n", Ua.c[3]);	

	printf(" All we can say now is %s.\n\n", Ua.c);

	/* Now.. pays your attentions...  */
	printf(" union godMode omgHax 's initial values:  \n");
	printf(" omgHax.uWord:      %hu\n", omgHax.uWord);
	printf(" omgHax.sWord:      %hhi\n", omgHax.sWord);
	printf(" omgHax.uByte[0]:   %hhu\n", omgHax.uBytes[0]);
	printf(" omgHax.uByte[1]:   %hhu\n", omgHax.uBytes[1]);
	printf(" omgHax.sByte[0]:   %hhi\n", omgHax.sBytes[0]);
	printf(" omgHax.sByte[1]:   %hhi\n", omgHax.sBytes[1]);
	printf(" omgHax.nib.LL:     %01X\n", omgHax.nib.LL);
	printf(" omgHax.nib.LH:     %01X\n", omgHax.nib.LH);
	printf(" omgHax.nib.HL:     %01X\n", omgHax.nib.HL);
	printf(" omgHax.nib.HH:     %01X\n", omgHax.nib.HH);
	printf(" omgHax.b.b0...b15: %hu%hu%hu%hu %hu%hu%hu%hu %hu%hu%hu%hu %hu%hu%hu%hu\n\n",
		omgHax.b.b15, omgHax.b.b14, omgHax.b.b13, omgHax.b.b12,
		omgHax.b.b11, omgHax.b.b10, omgHax.b.b9,  omgHax.b.b8,
		omgHax.b.b7,  omgHax.b.b6,  omgHax.b.b5,  omgHax.b.b4,
		omgHax.b.b3,  omgHax.b.b2,  omgHax.b.b1,  omgHax.b.b0 );

	/*Lets flip some bits */
	omgHax.b.b15 ^= 1;
	omgHax.b.b13 ^= 1;
	
	/*Clear a nibble or two*/
	omgHax.nib.HL = 0;
	omgHax.nib.LH = 0;

	/*and set a bit*/
	omgHax.uWord |= (1 << 6);

	
	/*0101 0000 0100 1111*/
	printf(" union godMode omgHax 's values after bit/nibble manipulations:  \n");
	printf(" omgHax.uWord:      %hu\n", omgHax.uWord);
	printf(" omgHax.sWord:      %hhi\n", omgHax.sWord);
	printf(" omgHax.uByte[0]:   %hhu\n", omgHax.uBytes[0]);
	printf(" omgHax.uByte[1]:   %hhu\n", omgHax.uBytes[1]);
	printf(" omgHax.sByte[0]:   %hhi\n", omgHax.sBytes[0]);
	printf(" omgHax.sByte[1]:   %hhi\n", omgHax.sBytes[1]);
	printf(" omgHax.nib.LL:     %01X\n", omgHax.nib.LL);
	printf(" omgHax.nib.LH:     %01X\n", omgHax.nib.LH);
	printf(" omgHax.nib.HL:     %01X\n", omgHax.nib.HL);
	printf(" omgHax.nib.HH:     %01X\n", omgHax.nib.HH);
	printf(" omgHax.b.b0...b15: %hu%hu%hu%hu %hu%hu%hu%hu %hu%hu%hu%hu %hu%hu%hu%hu\n\n",
		omgHax.b.b15, omgHax.b.b14, omgHax.b.b13, omgHax.b.b12,
		omgHax.b.b11, omgHax.b.b10, omgHax.b.b9,  omgHax.b.b8,
		omgHax.b.b7,  omgHax.b.b6,  omgHax.b.b5,  omgHax.b.b4,
		omgHax.b.b3,  omgHax.b.b2,  omgHax.b.b1,  omgHax.b.b0 );

	/* So now we can see why unions are going to be pretty useful */

	printf(" This concludes the tutorial on Structs and Unions for now.\n");
	printf(" Unions are clearly %c%c!\n", omgHax.uBytes[0], omgHax.uBytes[1]);

	return 0;
}
