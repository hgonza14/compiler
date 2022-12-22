// Abstract Syntax Tree Implementation
// First run bison -d parser.y
// Second make
// ./output

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct AST
{
	char nodeType[50];
	char LHS[50];
	char RHS[50];

	struct AST *left;
	struct AST *right;
};

struct AST *AST_assignment(char nodeType[50], char LHS[50], char RHS[50])
{
	struct AST *ASTassign = malloc(sizeof(struct AST));
	strcpy(ASTassign->nodeType, nodeType);
	strcpy(ASTassign->LHS, LHS);
	strcpy(ASTassign->RHS, RHS);

	/*
		 =
	   /   \
	  x     y

	*/
	return ASTassign;
}

struct AST *AST_BinaryExpression(char nodeType[50], char LHS[50], char RHS[50])
{
	struct AST *ASTassign = malloc(sizeof(struct AST));
	strcpy(ASTassign->nodeType, nodeType);
	strcpy(ASTassign->LHS, LHS);
	strcpy(ASTassign->RHS, RHS);

	if (strcmp(nodeType, "+") == 0)
	{
		return 1;
	}
	if (strcmp(nodeType, "-") == 0)
	{
		return 2;
	}
	if (strcmp(nodeType, "*") == 0)
	{
		return 3;
	}
	if (strcmp(nodeType, "-") == 0)
	{
		return 4;
	}

	return -1;
}

struct AST *AST_Type(char nodeType[50], char LHS[50], char RHS[50])
{
	struct AST *ASTassign = malloc(sizeof(struct AST));
	strcpy(ASTassign->nodeType, nodeType);
	strcpy(ASTassign->LHS, LHS);
	strcpy(ASTassign->RHS, RHS);

	return ASTassign;
}

struct AST *AST_Func(char nodeType[50], char LHS[50], char RHS[50])
{
	struct AST *ASTassign = malloc(sizeof(struct AST));
	strcpy(ASTassign->nodeType, nodeType);
	strcpy(ASTassign->LHS, LHS);
	strcpy(ASTassign->RHS, RHS);

	return ASTassign;
}

struct AST *AST_Write(char nodeType[50], char LHS[50], char RHS[50])
{
	struct AST *ASTassign = malloc(sizeof(struct AST));
	strcpy(ASTassign->nodeType, nodeType);
	strcpy(ASTassign->LHS, LHS);
	strcpy(ASTassign->RHS, RHS);

	return ASTassign;
	// finish this function for the final project
}

void printDots(int num)
{
	for (int i = 0; i < num; i++)
		printf("      ");
}

void printAST(struct AST *tree, int level)
{
	if (tree == NULL)
	{
		printDots(level);
		printf("--Empty--");
		return;
	}

	printDots(level);
	printf("Value = %s\n", tree->nodeType);
	printDots(level);
	printf("left\n");

	printAST(tree->left, level);
	printDots(level);
	printf("right\n");

	printAST(tree->right, level);

	printDots(level);
	printf("done\n");

	// finish this function for the final project
}