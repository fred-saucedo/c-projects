#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>


void strInput (char str[], char *results[]); 
//void sort(int argc, char *argv[]); 
void testPrint( int *data, int count); 
void convertToInteger(char *results[], int *data, int count); 
int tokenize(char str[], char *results[]); 
void sort(int *data, int count); 
void printByRow(int *data, int count); //prints numbers in rows of 5
int main(int argc, char const *argv[])
{
	int maxChar = 81; 
	char str[maxChar]; 
	int count; 
	char *results[maxChar]; 
	int *data = (int *)malloc(10 * sizeof(int));  
	
	strInput(str, results);
	
	count = tokenize(str,results); 
	convertToInteger(results, data, count); 
	testPrint(data, count); 
	sort(data, count); 
	printf("Checking to see if sort worked \n");
	testPrint(data, count); 
	printByRow(data, count); 
	return 0;
}


void strInput(char str[], char *results[]) {

	printf("Enter a string of intergers, seperated by spaces\n");
	printf("Please note that only upto 80 characters are allowed\n");
	printf("per string. \n");

	int i = 0, k = 0; 
	int count =0; 
	int maxChar = 81; 

		 do {
		 	k = 0; 
		 	if(count>= maxChar) {
		 		printf("Plase make sure you use less than 81 characters\n");
		 	}
		 	count=0; //resetting the coun
			while((str[i] = getchar()) != '\n' && count<maxChar)
			{
				i++; 
				k++; 
				count++; //holds the num of chars per string
				if(count>=maxChar){
					break; 
				}
			}	

			if(k>1 )
				str[i] = ' \t'; 
			else
				str[i] = '\n'; 

			i++; 
		 }while(k>1);
		
				
}
int tokenize(char str[], char *results[]) {

	int i=0, count=0; 
	if (results[0] = strtok(str, " \t") ) {
			count++; 
		}

		while (results[count] = strtok(NULL, " \t")) {
			count++; 
		}

	return count; 
}

void convertToInteger(char *results[], int *data, int count){

	int i =0; 
	int size_of_array = count; 
	int initial_size = 10; 
	if(size_of_array > initial_size) {
		//free previous memmry; 
		free(data); 
		//allocate more memory; 
		int *data = (int*)malloc((size_of_array *2)* sizeof(int)); 
	}
	for(i = 0; i < count-1; i++) {
		data[i] = atoi(results[i]); 
	}

}

void testPrint( int *data, int count) {
	int i; 

	printf("Here are the string of numbers: \n");
	for (i=0; i<count-1; i++) 
		printf("%i\n",data[i] );
}

void sort (int *data, int count) {

	int i, j, temp; 
	for (i=0; i<count-1; i++){
		for(j=0; j<count-2-i; j++){
			
			if(data[j]<data[j+1]) {

				temp=data[j+1]; 
				data[j+1] = data[j]; 
				data[j] = temp; 
			}
		}
	}
	
}

void printByRow(int *data, int count) {

	//prints data in rows of 5

	int i, j,k; 
	int num = 5; //number of items in each row
	int data_size = count-1; 
	k=0; 

	printf("Printing Numbers in rows of 5 \n");
	do {

		for(j=0; j<num; j++){

			printf("%i  ", data[k]);
			k++; 
		}
		printf("\n");

	}while(data_size-num>5); 

	for(j=0; j<data_size-num; j++){
		printf("%i  ", data[k]);
		k++; 
	}
		
	printf("\n");
}
