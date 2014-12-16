#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

void strInput (char str[], char *results[]);  
void testPrint( int *data, int count); 
int  *convertToInteger(char *results[],int *data, int count); 
int tokenize(char str[], char *results[]); 
void sort(int *data, int count); 
void printByRow(int *data, int count); //prints numbers in rows of 5
double average(int *data, int count); 
void mode(int *data, int count,int *result); 
int Median(int *data, int count); //finding the mean
int  aboveAverage(int *data, int count, double average); 
int  belowAverage(int *data, int count, double average); 
int equalAverage(int *data, int count, double average); 
int negativeVal(int *data, int count); 
int positiveVal(int *data, int count); 
int zeroVal(int *data, int count); 
void outToFile(int *data, int count, int high, int low, double average, int above_average, 
int below_average, int equal_average, int negative_val, int zero_val, int positive_val, 
int median, int *mode); 
void FILEprintByRow(int *data, int count); 
void printMode(int *result); 



int main(int argc, char const *argv[])
{
	int maxChar = 81; 
	int specifics = 12; 
	int specArr[specifics]; 
	char str[maxChar]; 
	int count,i; 
	int above_average, below_average, equal_average; 
	double avg; 
	int highest, lowest; 
	char *results[maxChar]; 
	int *result = (int *)malloc(2*sizeof(int)); 
	int *data; 
	 //holds mode and its repeated times
	data = (int *)malloc(10 * sizeof(int)); //initial statement; 
	strInput(str, results);
	count = tokenize(str,results);  
	data = convertToInteger(results, data, count); 
	sort(data, count); //sort data array; 
	printByRow(data, count); 
	highest = data[0]; //first index
	lowest = data[count-1]; //last index 
	avg = average(data, count); 
	above_average = aboveAverage(data, count, avg); 
	equal_average = equalAverage(data, count, avg); 
	below_average = belowAverage(data, count, avg); 
	mode(data,count,result); 
	printMode(result); //printing the mode 
	outToFile(data, count, highest, lowest, avg, above_average, below_average, 
	equal_average, negativeVal(data, count),zeroVal(data, count),positiveVal(data, count),
	Median(data,count), result); 
	//printf("Mode : %i\n", result[0]); 
	//printf("occurances: %i\n", result[1]); 
	 
	
	return 0;
}

void printMode(int *result) {
	printf("The mode value for this set:...... %i\n", result[0]); 
	printf("The number of occurances for mode: %i\n", result[1]);
}
void strInput(char str[], char *results[]) {

	printf("Enter a string of intergers, seperated by spaces\n");
	printf("Please note that only upto 80 characters are allowed\n");
	printf("per string. \n");

	int i = 0, k = 0, j=0; 
	int count =0; 
	int maxChar = 81; 

		 do {
		 	k = 0; 
		 	
		 	/*if(count> maxChar) {
		 		printf("Plase make sure you use less than 81 characters\n");
		 	}
		 	count=0; //resetting the count\ */
		 	
		    printf("Please Enter the string next of numbers: \n"); 
			while((str[i] = getchar()) != '\n' && count<maxChar)
			{
				i++; 
				k++; 
				count++; //holds the num of chars per string
			}	

			if(k>=1)
				str[i] = ' \t'; 
			else
				str[i] = '\n'; 

			i++; 
		 }while(k>=1);	
		 
		 //	printf("Numer of characters in string: %i\n", i); 
		 
				
}
int tokenize(char str[], char *results[]) {

	int i=0, count=0; 
	int j =0; 
	if (results[0] = strtok(str, " \t") ) {
			count++; 
		} 
		while (results[count] = strtok(NULL, " \t")) {
			count++; 
		}
		if(count ==1){ //treaing the case that there is only 1 item; 
			count=2; 
		}
	return count-1; 
}

int *convertToInteger(char *results[], int *data, int count){
	int i =0; 
	int size_of_array = count; 
	int initial_size = 10; 
	
	if(size_of_array > initial_size) {
		//allocate more memory; 
	data = (int *)malloc((size_of_array*2)*sizeof(int)); 
	
	}
	for(i=0; i<size_of_array; i++){
		data[i] = atoi(results[i]); 
	}
	
	return data; 
} 
void testPrint( int *data, int count) {
	int i; 

	printf("Here are the string of numbers: \n");
	for (i=0; i<count; i++) 
		printf("%i\n",data[i] );
}
void sort (int *data, int count) { 

	int i, j, temp; 
	for (i=0; i<count; i++){
		for(j=0; j<count-1-i; j++){
			
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
	int data_size = count; 
	k=0; 
//	printf("data count: %i , data size: %i \n", count, data_size); 
	printf("Printing Numbers in rows of 5 \n");
	while(data_size > num) {
	
		for(j=0; j<num; j++){
			printf("%i  ", data[k]);
			k++; 
		}
		printf("\n");
		data_size = data_size-num; 
	}

	for(j=0; j<data_size; j++){
		printf("%i  ", data[k]);
		k++; 
	}
	printf("\n");
}


double average(int *data, int count){

	double sum; 
	double average; 

	int i; 
	sum = 0; //initalizing sum
	for(i=0; i<count; i++){
		sum += data[i]; 
	}

	average = sum/count ; 
	printf("The average value for this set of numbers: %.2f\n", average); 

	return average; 

}

void mode(int *data, int count, int *result){

	int i,j; 
	int highest_repeated; 
	int index; 
	int answer[2]; 
	int *freq_arr = (int *)calloc(count,sizeof(int)); //to hold the number of occurances
	//finding the value that occurs the most
	i=0; 
	while( i< count){
		j=0; 
		while (j<count){
			if(data[i] == data[j])
				freq_arr[i] +=1; 
			j++; 
		}
		i++; 

	}

	/*for(i=0; i<count; i++){
		printf("Frequency Array %i has %i occurances\n", data[i], freq_arr[i] );
	}*/

	index = 0; 
	highest_repeated = freq_arr[index]; 
	for (i=0; i<count; i++){
		if(freq_arr[i]>highest_repeated){
			highest_repeated = freq_arr[i]; 
			index =i; 

		}
		
	} 
	result[0]= data[index]; 
	result[1] = freq_arr[index]; 
 
}


int Median(int *data, int count){
	
	int i; 
	int index;
	if(!(count%2)) { //checking to see if size is even
		index = count/2 -1; 
	}
	else{
		index = count/2 + 1; 
	}
	
	printf("The median for this set of numbers: %i\n", data[index]); 
	return data[index]; 
}

int  aboveAverage(int *data, int count, double average){
	int i; 
	int num; 
	num = 0; 
	for(i=0; i<count; i++){

		if(data[i]-average>=0.1)
			num++; 
	}
	printf("Values above the average: %i\n",num );
	return num; 
}

int belowAverage(int *data, int count, double average){

	int i, num; 
	num=0; 
	for(i=0; i<count; i++){
		if(average-data[i]>.01)
			num++; 
	}
	printf("Values below the average: %i\n", num );
	return num; 
}
int equalAverage(int *data, int count, double average) {
	int i; 
	int num = 0; 
	for(i=0; i<count; i++) {
		if(abs(average-data[i])<.01) //difference is less than 0.1
			num++; 
	}

	printf("Values equal to the average: %i\n", num);
	return num; 
}

int positiveVal(int *data, int count) {
	int i, num; 
	num = 0; 
	for(i=0; i<count; i++) {
		if(data[i]>0)
			num++; 
	}
	printf("The numbers of positive intergers in set: %i\n", num );
	return num; 
}


int zeroVal(int *data, int  count) {
	int i, num; 
	num = 0; 
	for(i=0; i<count; i++){
		if(data[i]==0) {
			num++; 
		}
	}

	printf("The number of zero valued integers in set: %i\n", num );
	return num; 
}

int negativeVal(int *data, int count) {
	int i, num; 
	num=0; 
	for(i=0; i<count; i++) {
		if(data[i]<0)
			num++; 
	}

	printf("The number of negative values in set: %i\n", num );
	return num; 
}

void outToFile(int *data, int count, int high, int low, double average, int above_average, int below_average, 
	int equal_average, int negative_val, int zero_val, int positive_val, int median, int *mode) {
	int i, j, k; 
	int data_size = count; 
	int num = 5; 
	FILE *fp; 
	k=0; 
	fp = fopen("231sA4_fred_code.txt","w"); 
	
	if(fp==NULL) {
		printf("File could not be open.\n"); 
	 
	}
	fprintf(fp, "Fred Saucedo\n" );
	fprintf(fp, "Number of values input:...........%i\n",count );

	fprintf(fp, "Printing Numbers in rows of 5:\n");

	while(data_size > num) {
	
		for(j=0; j<num; j++){
			fprintf(fp, "%i  ", data[k]);
			k++; 
		}
		fprintf(fp, "\n");
		data_size = data_size-num; 
	}

	for(j=0; j<data_size; j++){
		fprintf(fp, "%i  ", data[k]);
		k++; 
	}
	
	fprintf(fp,"\n");

	fprintf(fp, "The highest value in this set:....%i\n",high );
	fprintf(fp, "The lowest value in this set:.....%i\n",low );
	fprintf(fp, "The average value in this set:....%.2f\n",average );
	fprintf(fp, "Number of values above average:...%i\n", above_average);
	fprintf(fp, "Number of values eqal to average:.%i\n", equal_average);
	fprintf(fp, "Number of values below average:...%i\n", below_average);
	fprintf(fp, "Number of negative values:........%i\n", negative_val);
	fprintf(fp, "Number of values equal to zero:...%i\n", zero_val);
	fprintf(fp, "Number of postive values:.........%i\n", positive_val);
	fprintf(fp, "The median value for this set:....%i\n", median);
	fprintf(fp, "The mode value for this set:......%i\n", mode[0]);
	fprintf(fp, "The number of occurances for mode:%i\n", *(mode +1));
	fclose(fp); 
}
