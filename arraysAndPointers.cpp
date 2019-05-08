/* Program Name:    arraysAndPointers.cpp                                    */
/* Programmer:      Mark Hooper - mr876805@dal.ca                            */
/* Last Updated:    APR-07-2019                                              */
/* Description:     repeat after me..                                        */
/*                  1. the value of a pointer is always an MEMORY ADDRESS.   */
/*                  2. int variableName = 1;							     */
/*                  3. &variableName - think "ADDRESS OF variableName"       */                         
/*					4. int* pointerName = &variableName;					 */
/*					5. *pointerName - think "THE VALUE STORED AT THE MEMORY  */
/*					   ADDRESS THAT pointerName IS POINTING TO (that value   */
/*                     in this specific case is 1)".                         */
/*					4. the address that pointerName is pointing to           */
/*                     is the value of pointerName.	Why? SEE STEP 1. 		 */							

#include <iostream>
#include <cstdlib>

int main(void) {
	/* declare some typical variables */
	char c = 'A';
	unsigned short us = 1000;
	int i = -1;

	/* now declare some pointers to these variables */
	int* p2i = &i;
	unsigned short* p2us = &us;
	char* p2c = &c;
	
	/* now we will output the value, address and 
	   (for the pointers) the value at the memory
	   address pointed to by the pointer. */
	std::cout << "\tc    == " << c << "\t\t&c    == " << (void*)&c<< std::endl;
	std::cout << "\tus   == " << us << "\t\t&us   == " << &us << std::endl;
	std::cout << "\ti    == " << i << "\t\t&i    == " << &i	<< std::endl;
	std::cout << "\tp2c  == " << (void*)p2c	<< "\t&p2c  == "	<< &p2c	
		<< "\t*p2c  == " << *p2c << std::endl;
	std::cout << "\tp2us == " << p2us << "\t&p2us == " << &p2us	
		<< "\t*p2us == " << *p2us << std::endl;
	std::cout << "\tp2i  == " << p2i << "\t&p2i  == " << &p2i	
		<< "\t*p2i  == " << *p2i << std::endl;
	
	/* now for the increment operations*/
	std::cout << "\n\n\n\tIncrementing pointer values..." << std::endl;
	p2c++;
	p2us++;
	p2i++;
	
	/* let's see how these incremented values differ. */
	std::cout << "\tp2c  == " << (void*)p2c << std::endl;
	std::cout << "\tp2us == " << p2us << std::endl;
	std::cout << "\tp2i  == " << p2i << std::endl;

	/* arrays are contiguous blocks of allocated memory */
	/* let's allocate two arrays, and point at them */
	char a1[6] = "Hello";			   //a1 is pointing to the first of 6 bytes (\0 is at the end)
	char a2[4] = { 'B','y','e','\0' }; //a2 is pointing to the first of 4 bytes of memory
	char* p1 = a1;					   //p1 is pointing at the same location as a1
	char* p2 = a2;		               //p2 is pointing at a2
	char** pp3 = &p1;				   //pp3 is pointing at p1

	/* let's output some strings */
	int j;
	std::cout << "\n\n\n\tString Output..." << std::endl;
	
	/* start with a1 */
	std::cout << "\ta1  == ";
	for (j = 0; j < 6; j++) {
		std::cout << a1[j];
	}

	/* now for a2 */
	std::cout << "\n\ta2  == ";
	for (j = 0; j < 4; j++) {
		std::cout << a2[j];
	}
	
	/* let's output a1 again, but lets use p1 to do it*/
	std::cout << "\n\t*p1 == ";
	while (*p1) {
		std::cout << *p1;
		p1++;
	}

	/* let's output a2 using p2 */
	std::cout << "\n\t*p2 == ";
	while (*p2) {
		std::cout << *p2;
		p2++;
	}
	
	/* now let's see the value of p1 using pp3 */
	std::cout << "\n\t*pp3 == " << (void*)*pp3 << std::endl;

	/* let's point p1 at a1 again */
	p1 = a1;
	
	/* Let's see the updated value of p1 */
	std::cout << "\tp1 == " << (void*)p1 << std::endl;

	/* again with pp3 */
	std::cout << "\t*pp3 == " << (void*)*pp3 << std::endl;

	/* lets try to print only the 'H' in a1 using pp3 */
	std::cout << "\t**pp3 == " << **pp3 << std::endl;

	/* now for the printf() version */
	printf("\t**pp3 == %c\t(printf)\n", **pp3);

	/* lets try to print "Hello" in a1 using pp3 */
	std::cout << "\t*&*pp3 == " << *&*pp3 << std::endl;

	/* now for the printf() version */
	printf("\t*&*pp3 == %s\t(printf)\n", *&*pp3);

	/* we can even use indexing with pointers much like arrays */
	std::cout << "\tp1[0..6] == ";
	for (j = 0; j < 6; j++) {
		std::cout << p1[j];
	}
	
	/* let's check to see if p1 still points at a1 after that..*/
	std::cout << "\n\tp1 == " << (void*)p1 << std::endl;

	/* that all checks out.. keep in mind, you'll likely get different
	   addresses each time you run the executable.*/

	/* so, pointers can be incremented, and use indexed addressing.*/

	/* but try incrementing a1 and see what happens..*/

	return 0;
}