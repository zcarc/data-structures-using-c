#include <stdio.h>
#include "InfixCalculator.h"

int main(void)
{
	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";

	printf("%s = %d \n", exp1, EvalInfixExp(exp1));
	printf("%s = %d \n", exp2, EvalInfixExp(exp2));
	printf("%s = %d \n", exp3, EvalInfixExp(exp3));
	return 0;
}

// 스택의 활용:   ListBaseStack.h, ListBaseStack.c
// 후위 표기법의 수식으로 변환:   InfixToPostfix.h, InfixToPostfix.c
// 후위 표기법의 수식을 계산:   PostCalculator.h, PostCalculator.c
// 중위 표기법의 수식을 계산:  InfixCalculator.h, InfixCalculator.c
// main 함수:   InfixCalculatorMain.c