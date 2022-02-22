#include<stdio.h>
#include<math.h>

int getDigitValue(int number, int digit){
	
	int value = number  / pow(10 , digit);
	value = value % 10;
	return value;
}

void functionB(int totalList[],int totalCount,int foundList[],int * foundCount, int departmentNumber){
	int studentIndex;

	for(studentIndex = 0; studentIndex < totalCount; studentIndex++){
		int departmentNumberDigit4=0,departmentNumberDigit5=0,departmentNumberDigit6=0;
		departmentNumberDigit4 =  getDigitValue(totalList[studentIndex], 5);
		departmentNumberDigit5 =  getDigitValue(totalList[studentIndex], 4);
		departmentNumberDigit6 =  getDigitValue(totalList[studentIndex], 3);
		
		if(departmentNumberDigit4 == 3 && departmentNumberDigit5 == 0 && departmentNumberDigit6 == departmentNumber ){
			foundList[*foundCount] = totalList[studentIndex];
			(*foundCount)++;
		}
	}
}
void functionA(int totalList[],int totalCount,int foundList[],int * foundCount, int entranceYear){
	
	int studentIndex;
	int entranceYearDigit1 = getDigitValue(entranceYear, 1);
	int entranceYearDigit2 = getDigitValue(entranceYear, 0);
	
	for(studentIndex = 0; studentIndex < totalCount; studentIndex++){
		int studentYearDigit1, studentYearDigit2 = 0;
		studentYearDigit1 =  getDigitValue(totalList[studentIndex], 8);
		studentYearDigit2 =  getDigitValue(totalList[studentIndex], 7);
		if(studentYearDigit1 == entranceYearDigit1 && studentYearDigit2 == entranceYearDigit2){
			foundList[*foundCount] = totalList[studentIndex];
			(*foundCount)++;
		}
	}
}


int main(){
	
	int studentNumber,choice,entranceYear,departmentNumber;
	int studentIndex,foundStudentCount =0,foundIndex;
	
	printf("How many students you want to enter: ");
	scanf("%d",&studentNumber);
	
	int studentList[studentNumber];
	int foundStudentList[studentNumber];
	
		for(studentIndex = 0; studentIndex < studentNumber; studentIndex++ ){
			printf("Enter %d. student id: ", studentIndex+1); 
			scanf("%d",&studentList[studentIndex]);
		}
		
	printf("List Students\n");
	printf("     1. Entrance Year\n");
	printf("     2. Department\n");
	printf("Enter your choice: ");
	scanf("%d",&choice);
	
		if(choice == 1){
			printf("Choose the entrance year between (2018-2020): ");
			scanf("%d",&entranceYear);
			printf("The students with entrance year %d:\n", entranceYear);
			functionA(studentList,studentNumber,foundStudentList, &foundStudentCount,entranceYear);			
			int foundIndex = 0;
			for(foundIndex = 0; foundIndex < foundStudentCount; foundIndex++){
				printf("%d\n",foundStudentList[foundIndex]);
			}
		}
		else if(choice == 2){
			printf("Choose a department, enter 0 for CMPE, 1 for SE and 2 for ISE: ");
 			scanf("%d",&departmentNumber);
 			printf("The students in this department:\n");
			functionB(studentList,studentNumber,foundStudentList, &foundStudentCount,departmentNumber);
			for(foundIndex = 0; foundIndex < foundStudentCount; foundIndex++){
				printf("%d\n",foundStudentList[foundIndex]);
			}
			
		}
		else{
			printf("Error!");
		}
	return (0);
}


