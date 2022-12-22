// ---- Functions to handle IR code generation ---- //
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

FILE *IRcode;

void initIRcodeFile()
{
    IRcode = fopen("IRcode.ir", "a");
}

void emitBinaryOperation(char *op, char *id1, char *id2)
{
    fprintf(IRcode, "T1 = %s %s %s\n", id1, op, id2);
}

void emitBinaryNumber(char *op, char *id1, int id2)
{
    fprintf(IRcode, "T1 = %s %s %d\n", id1, op, id2);
}

void emitBinaryHelper(char *op, char *id1, char *id2)
{
    fprintf(IRcode, "T2 = %s %s %s\n", id1, op, id2);
}

void emitOptional(char *id1, char *id2)
{
    fprintf(IRcode, "%s = %s\n", id1, id2);
}

void emitAssignment(char *id1, char *id2)
{
    // Option 1
    // fprintf(IRcode, "%s = %s\n", id1, id2);

    // Option 2
    fprintf(IRcode, "T1 = %s\n", id1);
    fprintf(IRcode, "T2 = %s\n", id2);
    fprintf(IRcode, "T2 = T1\n");
}

void emitConstantIntAssignment(char id1[50], char id2[50])
{
    fprintf(IRcode, "%s = %s\n", id1, id2);
}

void emitWriteId(char *id)
{
    // fprintf (IRcode, "output %s\n", id); // This is the intent... :)

    // This is what needs to be printed, but must manage temporary variables
    fprintf(IRcode, "output %s\n", id);
}