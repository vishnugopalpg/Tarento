///////////////////////////////////////////////////////////////////////////////////////////////////////
// Question Number 1																				///
//------------------------------------------------------------------------------					///
//------------------------------------------------------------------------------					///
// Read an array of words as user input (do not hardcode input)    									///                                                                      ///
// and print all 2 word combinations possible without any duplications.								///
//  																								///
//	Eg: Input [one, two, three ]																	///
//  Output: [one-two, one-three, two-one, two-three, three-one, three-two] 							///												///
//																									///
///////////////////////////////////////////////////////////////////////////////////////////////////////
   
#include<stdio.h>
#include<string.h>

int main()
{
	int n=3,m=0;
	//initalize the array
	char *input[n];
	input[0] = "one";
	input[1] = "two";
	input[2] = "three";
	printf("The inputs are \t [%s, %s, %s]\n",input[0],input[1],input[2] );
	printf("The output is\t[");
	//removing the repeated terms in the array
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;){
			if(input[i] == input[j]){
				for(int k=j;k<n;k++)
             			 {
                			input[k]=input[k+1];
             		 	 }
                		 n--;
                	}
                	else
                		j++;
		}
	}
	
	//making combinations of unique items in the array. Same combinations are removed
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(input[i] != input[j]){
			printf(" %s-%s   ",input[i],input[j]);
	
			}

				
		}
	}
	printf("]");
}
	
