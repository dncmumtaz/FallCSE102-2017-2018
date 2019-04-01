                        /*MUMTAZ DANACI*/
                        /*161044002    */
                        /*HW03         */
                        
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu(); /*The function  gives options to user. */
int getInt(int mini, int maxi);/*the function get a number.*/
int numberGeneratorBetweenRange(int min, int max);/*the function generator 
between range.*/
void horseRacingGame();/*the function  is horse racing game. */
void countOccurrence(); /*This function computes number of occurrences
 of searchNumber in bigNumber. */
int digt_number(int search_number);/*the function calculate number of digit
in countOccurance funtion.*/
void triangleOfSequences(); /*It generates a triangle of sequences .*/

int main(){
	
	srand(time(NULL)); /* Function generates random number.*/
	
	menu();
	
	return 0;
}

void menu(){

	int number;
	
	do{
		printf("1. Horse Racing Game\n");    /*This is menu.*/
		printf("2. Occurrence Counter\n");
		printf("3. Triangle of Sequences\n");
		printf("0. Exit\n");
		printf("Enter A Number:");
		scanf("%d", &number);
		printf("\n");
		
		switch(number){      /*This switch case  provides to make a selection.*/
			case 0 :				
				break;
			case 1 :
				horseRacingGame();
				break;
			case 2 :
				countOccurrence();
				break;
			case 3 :
				triangleOfSequences();
				break;
			default :
				printf("Wrong input is entered.\n");
				break;
		}
		
	}while(number);
}

int getInt(int mini, int maxi){
	
	int number, control;
	
	for(control=0 ; control < 1 ; ){  /*this loop get a number between mini and 
	maxi from user*/

		scanf("%d", &number);
		
		if(number >= mini && number <= maxi)
			control=1;
	}
	
	return 	number;
}

int numberGeneratorBetweenRange(int min, int max){
	                           /*the function generator between max and min.*/
	int i, number;
	
	number = rand() % ( max - min ) + min;

	return number;
}

void horseRacingGame(){    /*the function  is horse racing game. */
	
	int i, j, temp_range=0, range, winner=20+1; 
	int temp, number_of_horse, guess_of_horse;

	number_of_horse = numberGeneratorBetweenRange(3 , 5);/*number of horse 
	should be between 3 and 5.*/
	
	printf("Number of Horse: %d\n", number_of_horse);
	printf("Horse Number: ");
	
	guess_of_horse = getInt(0,number_of_horse);

	printf("Racing stars..\n");
	
	for( i = 1 ; i <= number_of_horse ; i++){
		
		temp=numberGeneratorBetweenRange(10 , 20);
		printf("%d.Horse:",i);
		
		for( j=0 ; j<temp ; j++ ){
			printf(".");
		}
		
		printf("\n");
		
		if(winner>temp){ /*this statement finds winner.*/
			range=i;
			winner=temp;	
		}
		
		else if(winner==temp)/*this statement finds equivalent */
			range=-1;
	}
	
	int degree=1;
	
	for(i=0;i<number_of_horse;i++){
		degree++;
	}	
	
	if(range == -1){
		printf("No Winner!");
	}
	
	else if(guess_of_horse == range)
		printf("You Win!");
		
	else if(guess_of_horse != range && range != -1){
		printf("You lose! Winner is Horse %d.", range);
	}
	printf("\n\n");
}

void countOccurrence(){
	
	int i, j=0, k=0, digit, controller=1, search_number, temp;
	int occurance=0, result, big_number=0;
	
    printf("Big Number:");
    scanf("%d",&big_number);
    
    printf("\nSearch Number:");
    scanf("%d",&search_number);
        
    digit = digt_number(search_number);/*this row calculated digit of search
	number.*/
   
    for(i=0;i<digit;i++){       /*While i calculated mod , i use this integer
	'controller'.*/
        controller=controller*10;        
    }
    
    temp=big_number;
    
    while(k==0){
    	
        result = big_number % controller; /*this row calculates mod.*/
        
        if(result == search_number){     /*if  mod equal to search number 
		increase occurance.*/
            occurance++;
        }
        
        big_number = ( big_number - result ) / controller;
        
        if(big_number<1) k++;
    }
   
    big_number=temp;
    big_number=big_number-(big_number%10);
    big_number=big_number/10;

    if(digit>1){
    	
    	while(j==0){
    		
        result=big_number%controller;
        
        if(result==search_number){
            occurance++;
        }
        
        big_number=(big_number-result)/controller;
        
        if(big_number<1) j++;
    	}
    }
    
    printf("\nOccurance:%d\n\n",occurance);
}

int digt_number(int search_number){/*This function calculates digit of search 
	number*/
	
    int dgt;

    dgt=1;
    
	while(search_number>=10){
    	search_number = search_number/10;
        dgt++;
	}
    
    return dgt;
}

void triangleOfSequences(){/*It generates a triangle of sequences .*/
	
	int i, j, key=1, number;
	
	number = numberGeneratorBetweenRange(2,10);/*this row generate between
	2 and 10 .*/
	
	for(i=0 ; i <= number ; i++){
		
		key=i;
		
		for(j=0 ; j<i ; j++){
		
			printf("%d ",key);
			key = i + key;
		}	
		printf("\n");
	}
	printf("\n\n");
}
