/*
	Symbol table header.
	1.) run bison -d parser.y
	2.) make
	3.) ./output
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct Entry
{
	int itemID;
	int arrayLength;
	char itemName[50]; // the name of the identifier
	char itemKind[8];  // function or variable
	char itemType[8];  // int, char, etc.
	char scope[50];	   // global, or the name of the function
};

struct Entry symTabItems[100];
int symTabIndex = 0;
int SYMTAB_SIZE = 20;

void symTabAccess(void)
{
	printf("::::> Symbol table accessed.\n");
}

void addItem(char itemName[50], char itemKind[8], char itemType[8], int arrayLength, char scope[50])
{
	// add items into symTabItems
	struct Entry *newSymTabItems = malloc((sizeof(struct Entry)));

	newSymTabItems->itemID = symTabIndex;
	strcpy(newSymTabItems->scope, scope);
	strcpy(newSymTabItems->itemKind, itemKind);
	strcpy(newSymTabItems->itemName, itemName);
	strcpy(newSymTabItems->itemType, itemType);
	newSymTabItems->arrayLength = arrayLength;
	symTabItems[symTabIndex] = *newSymTabItems;

	symTabIndex++;
}

void showSymTable()
{
	int i;
	printf("itemID  itemName  itemKind  itemType  ArrayLength  itemScope\n");
	printf("-----------------------------------------------------------------------\n");

	// for loop to print items from the symbol table

	for (i = 0; i < symTabIndex; i++)
	{
		printf(
			" %d\t%s\t%s\t\t%s\t\t%d\t\t%s\n",
			symTabItems[i].itemID,
			symTabItems[i].itemName,
			symTabItems[i].itemKind,
			symTabItems[i].itemType,
			symTabItems[i].arrayLength,
			symTabItems[i].scope);
	}

	printf("-----------------------------------------------------------------------\n");
}

int found(char itemName[50], char scope[50])
{
	// Lookup an identifier in the symbol table
	// return TRUE or FALSE

	// For loop that counts SYMTAB_SIZE times, no matter the size of the symbol table
	for (int i = 0; i < SYMTAB_SIZE; i++)
	{
		int one = strcmp(symTabItems[i].itemName, itemName);
		int two = strcmp(symTabItems[i].scope, scope);
		if (one == 0 && two == 0)
		{
			return 1; // found the ID in the table
		}
	}
	return 0;
}

const char *getVariableType(char itemName[50], char scope[50])
{

	for (int i = 0; i < SYMTAB_SIZE; i++)
	{
		int str1 = strcmp(symTabItems[i].itemName, itemName);
		// printf("\n\n---------> str1=%d: COMPARED: %s vs %s\n\n", str1, symTabItems[i].itemName, itemName);
		int str2 = strcmp(symTabItems[i].scope, scope);
		// printf("\n\n---------> str2=%d: COMPARED %s vs %s\n\n", str2, symTabItems[i].itemName, itemName);
		if (str1 == 0 && str2 == 0)
		{
			return symTabItems[i].itemType; // found the ID in the table
		}
	}
	return NULL;
}

int compareTypes(char itemName1[50], char itemName2[50], char scope[50])
{
	const char *idType1 = getVariableType(itemName1, scope);
	const char *idType2 = getVariableType(itemName2, scope);

	printf("%s = %s\n", idType1, idType2);

	int typeMatch = strcmp(idType1, idType2);
	if (typeMatch == 0)
	{
		return 1; // types are matching
	}
	else
		return 0;
}