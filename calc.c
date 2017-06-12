#include <stdio.h>
#include "operators.h"
#include "my_fscanf.h"

int main(){
	FILE *fp = fopen("read.txt","r");
	int operand1, operand2;
	char operator = ' ';
	int line = 0;
	double(*cal) (int, int);
	fp = fopen("read.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%d", &line);
	
		for(int i=0; i<line&&!feof(fp); i++) {
			my_fscanf(fp, "%d %c %d",&operand1, &operator, &operand2);
			switch(operator) {
				case '+':
				cal = add;
				break;
				case '-':
				cal = minus;
				break;
				case '*':
				cal = mul;
				break;
				case '/':
				cal = div;
				break;
			}		
			printf("%d %c %d = %f\n",
				 operand1, operator, operand2, cal(operand1, operand2));
		}
	}
	return 0;
}

