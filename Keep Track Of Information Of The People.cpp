#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <iostream>
#include <string>


struct people_info{
	char name_surname[20];
	int id_number;
	char sport[20];
	char city[10];
};
void get_info(int number_of_people,people_info people[]){
	int i;
		for(i = 0 ; i < number_of_people ; i ++){
			printf("Enter name and surname: ");
			scanf(" %[^\n]%*c",&people[i].name_surname);
			printf("Enter ID: ");
			scanf(" %d",&people[i].id_number);
			printf("Enter sport: ");
			scanf(" %s",&people[i].sport);
			printf("Enter city: ");
			scanf(" %s",&people[i].city);
		}
}
void get_city(char city[], people_info people[]){
	int i;
	FILE * fptr;
	fptr = fopen("Results.txt","w");

		for(i = 0 ; i < sizeof(people) ; i ++){
			if(strcmp(city,people[i].city) == 0){
				fprintf(fptr,"%s lives in %s with ID %d \n", people[i].name_surname, people[i].city , people[i].id_number);
			}
		}
		fclose(fptr);
}
void get_sport(char sport[], people_info people[]){
	int i;
	FILE * fptr;
	fptr = fopen("Results.txt","a");

		for(i = 0 ; i < sizeof(people) ; i ++){
			if(strcmp(sport,people[i].sport) == 0){
				fprintf(fptr,"%s likes %s with ID %d \n", people[i].name_surname, people[i].sport , people[i].id_number);
			}
		}
		fclose(fptr);
}
void get_character(char character, people_info people[]){
	int i;
	FILE * fptr;
	fptr = fopen("Results.txt","a");
		for(i = 0 ; i < sizeof(people) ; i ++){
			if(character == people[i].city[0]){
				fprintf(fptr,"%s lives in %s with ID %d \n", people[i].name_surname, people[i].city , people[i].id_number);
			}
		}
		fclose(fptr);
}

int main(){
	int number_of_people,i;
	char searched_city[20], searched_sport[20];
	std::string searched;
	char searched_character;
	printf("Enter the number of people: ");
	scanf("%d",&number_of_people);
	struct people_info people[number_of_people];
	get_info(number_of_people, people);

	printf("What do you want to search (city, branch of sport, first character of the city)? \n");
	while(std::getline (std::cin,searched) > 0){
	
		if(strcmp(searched.c_str(), "city") == 0){
			printf("Please enter the city to be searched: ");
			scanf("%s",&searched_city);
			get_city(searched_city, people);
			printf("What do you want to search (city, branch of sport, first character of the city)?\n");
		}
		else if(strcmp(searched.c_str(), "sport") == 0){
			printf("Please enter the branch of sport to be searched: ");
			scanf("%s",&searched_sport);
			get_sport(searched_sport, people);
			printf("What do you want to search (city, branch of sport, first character of the city)?\n");
		}
		else if(strcmp(searched.c_str(), "first char of city") == 0){
			printf("Please enter the first character of the city to be searched: ");
			scanf(" %c",&searched_character);
			get_character(searched_character, people);
			printf("What do you want to search (city, branch of sport, first character of the city)?\n");
		}
		else if(strcmp(searched.c_str(),"") != 0){
			printf("Bye...");
			return 0;
		}	
	}
}
