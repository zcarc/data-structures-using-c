#include <stdio.h>
#include "ExpressionTree.h"

int main(void)
{
    char exp[] = "12+7*";
    BTreeNode * eTree = MakeExpTree(exp);

    printf("ShowPrefixTypeExp: ");
    ShowPrefixTypeExp(eTree); printf("\n");

    printf("ShowInfixTypeExp: ");
    ShowInfixTypeExp(eTree); printf("\n");

    printf("ShowPostfixTypeExp: ");
    ShowPostfixTypeExp(eTree); printf("\n");

    printf("result: %d \n", EvaluateExpTree(eTree));

    return 0;
}