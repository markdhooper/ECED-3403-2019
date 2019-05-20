/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Program Name:  stringParsing.cpp                                     */
/* Programmer:    mark hooper - mr876805@dal.ca                         */
/* Last Updated:  MAY-20-2019                                           */
/* Description:   This is an overly explicit example of how to open a   */
/*                text file and parse it line by line for tokens.       */
/*                This can be done more elegantly by using strtok, but  */
/*                the gory detail should give a glimpse into what       */
/*                strtok is up to in general.                           */
/*                                                                      */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define FNAME 1
#define BSZ 256
#define FALSE 0
#define TRUE 1

int main(int argc, const char *argv[]) {
	FILE* inputFile;
	char buffer[BSZ];
	int lineNum = 1;
	char* comment = nullptr;
	char* tokenEnd;
	char* tokenStart;
	int recordParsed = FALSE;
	int numTokens = 0;
	int i = 0;

	if (argc < 2) {
	/* no command line arguments provided */
		printf("Please supply an input file\n");
		getchar();  //pause the command window
		return 1;
	}

	/* Open the file for reading */
	inputFile = fopen(argv[FNAME], "r");

	/* check to ensure file opened properly */
	if(inputFile == nullptr) {
		perror("Error opening input file\n");
		return 1;
	}

	/* output the file to the console line by line */
	while (fgets(buffer, BSZ, inputFile) != NULL) {
		/* Output the line and line number */
		printf("%d\t%s\n", lineNum, buffer);

		/* find a comment */
		if (comment = strchr(buffer, ';')) {
			printf("\tComment:\t%s\n", comment);
			if (comment == buffer) {
			/* first character in buffer was a comment */
				recordParsed = TRUE;
			}
		}
		
		/* Point at the start of the buffer */
		tokenStart = buffer;

		while (!recordParsed) {
			/* Record has not been fully parsed yet */
			if ( ( tokenEnd = strchr(tokenStart,' ') ) && ( (tokenEnd < comment) || (!comment) ) ){
				/* space found in relevant part of record */
				*tokenEnd = '\0';                                  //Put a null character in the record at the location of the space
				numTokens++;                                       //we've got a token between the two pointers tokenStart and tokenEnd
				printf("\tToken %d:\t%s\n",numTokens,tokenStart);  //output the token to the console
				tokenStart = tokenEnd + 1;                         //now let's look for the next token in the buffer
			}
			else {
				/* all tokens in the record have been found */
				if (tokenStart != comment){
					numTokens++;
					printf("\tToken %d:\t%s\n", numTokens, tokenStart);  //output the last token found
				}
				recordParsed = TRUE;                                 //We are done with this record
			}
		}
		/* reset all of the necessary variables in order to parse the next record */
		lineNum++;
		recordParsed = FALSE;
		numTokens = 0;
		comment = nullptr;
		printf("\n");
	}

	fclose(inputFile);  //close the input file
	getchar();          //pause the command window
	return 0;
}