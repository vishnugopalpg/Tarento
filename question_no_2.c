///////////////////////////////////////////////////////////////////////////////////////////////////////
/* Question Number 2																				///
//------------------------------------------------------------------------------					///
//------------------------------------------------------------------------------					///
//  Accept a String Input                                                                           ///
//  Verify whether the pairs and the orders of “{“, “}”, “(“, “)”, “[“, “]” are correct in exp.		///
//  Print well formed if every opening brace has an equivalent closing brace.						///
//  Print invalid if every opening brace does not have an equivalent closing brace					///
//																									///
//  Eg. Input: exp = “[()]{}{[()()]()}”																///
//  Output: Balanced																				///
//																									///
//  Input: exp = “[(])”																				///
// Output: Not Balanced																				///				
// */																								///
///////////////////////////////////////////////////////////////////////////////////////////////////////


//import libraries
#include<stdio.h>
#include<string.h>

//Declare variables expression as a stack with top to traverse through the stack
char expression[100];
int top = -1;
//to push the open braces into the stack
void push(char input){
	top+=1;
	expression[top] = input;
}
//to pop out and return the character when a end brace occur 
char pop(){
	return expression[top--];
}

int main(){

	//input used to store the input expression, temp used to compare 
	char input[100], temp;
	//flag used to check whether balanced or not. flag =1 impplies balanced, flag =0 implies not balanced.
	int flag=1,i=0;
	printf("Exp = ");
	scanf("%s",input);
	//repeat upto string length 
	while(i<strlen(input)){
		//if input is an open brance push to stack
		if(input[i] == '[' || input[i] == '{' || input[i] == '('){
			push(input[i]);
		}
		//if it is an end brace pop out the top value and compare with the input value
		if(input[i] == ']' || input[i] == '}' || input[i] == ')'){
			// check the stack is empty or not to pop up. If empty set flag to not balanced(0)
			if(top == -1)
				flag=0;
			else{
				//pop out the top element from stack and compare whether the poped item is not the input.
				//It implies that the expression is unbalanced
				temp = pop();
				if((temp == '[' || temp == '{') && input[i] ==')')
					flag=0;
				if((temp == '[' || temp == '(') && input[i] =='}')
					flag=0;
				if((temp == '(' || temp == '{') && input[i] ==']')
					flag=0;
			}
		}
		i++;
	}
	//after every character is traversed, check if the stack is empty or not. If not empty it is not balanced
	if(top>0)
		flag=0;
	if(flag == 0)
		printf("Not Balanced\n");
	else
		printf("Balanced\n");

}


