							/*MÜMTAZ DANACI*/
							/*  161044002  */
							/*The program calculate
				the area of the largest circle that fits inside a rectangle, 
				the area of the largest square that fits inside the rectangle,
				the area of the smallest circle that surrounds the same rectangle, 
				the area of the smallest square that surrounds the same rectangle.*/
							
							
#include <stdio.h>			/*Standart io library*/					
#include <math.h>			/*math library*/
#define PI 3.14			/* The cosntant value*/

double circle_area(double radius);
double calc_hypotenuse(int side1, int side2);
double calc_radius_of_smallest_circle(int side1, int side2);
double calc_radius_of_largest_circle(int side1, int side2);
double calc_area_of_smallest_circle(int side1, int side2);
double calc_area_of_largest_circle(int side1, int side2);
double calc_area_of_smallest_square(int side1, int side2);
double calc_area_of_largest_square(int side1, int side2);
double calc_area_of_square (int side);
void display_results(double largest_circle, double largest_square, double smallest_circle, double smallest_square);

int main() {

	int side, side1, side2;
	double radius;
    double largest_circle, largest_square,	smallest_circle,smallest_square;
	printf("Please, Enter first side of rectangle:\n ");
	scanf("%d",&side1);
	printf("Please, Enter second side of rectangle:\n ");
	scanf("%d",&side2);
	
	largest_circle=calc_area_of_largest_circle(side1, side2);	
	largest_square=calc_area_of_largest_square(side1,side2);
	smallest_circle=calc_area_of_smallest_circle(side1,side2);
	smallest_square=calc_area_of_smallest_square(side1, side2);
	
	display_results(largest_circle, largest_square,	smallest_circle,smallest_square);
	return 0;	
}

double circle_area(double radius){	/*The function calculete area of circle.*/
	double area;						
	area= PI*pow(radius,2); /*Area is equal to PI*r*r*/
	return area;
}

double calc_hypotenuse(int side1, int side2){ /*The function calculate  hypotenus.*/ 
	int poww, hypotenuse;
	poww=pow(side1,2)+pow(side2,2);	
	hypotenuse=sqrt(poww);
	return hypotenuse;
}

double calc_radius_of_smallest_circle(int side1, int side2){ /* The funtion calculate  radius of smallest circle*/
	int radius;
	if(side1<side2){          /*via if,edges were  compared .*/
		radius=side1;      
	}
	if(side1>side2){
		radius=side2;
	}
	else{
		radius=side1;
	}
	return radius;	
}

double calc_radius_of_largest_circle(int side1, int side2){ /*the funtion calculated radius of largest circle.*/
	int hypo, radius;
	hypo=calc_hypotenuse(side1, side2);	
	radius=hypo/2;
	return radius;
}

double calc_area_of_smallest_circle(int side1, int side2){ /*The funtion calculate area of smallest circle.*/
	int radius1;
	double area; 
	radius1=calc_radius_of_smallest_circle(side1, side2);
	area=PI*(pow(radius1,2));	
	return area;
}

double calc_area_of_largest_circle(int side1, int side2){ /*The funtion calculate area of largest circle.*/
	int radius1;
	double area;
	radius1=calc_radius_of_largest_circle(side1,side2);
	area=PI*(pow(radius1,2)); 
	return area;
}

double calc_area_of_smallest_square(int side1, int side2){ /*The funtion calculate area of smallest square.*/
	double radius;
	if(side1<side2){
		radius=side1;
	}							/*via if,edges were  compared .*/
	if(side1>side2){
		radius=side2;
	}
	else{
		radius=side1;
	}
	int side, area;
	side=radius;
	area=calc_area_of_square (side);
	return area;
}

double calc_area_of_largest_square(int side1, int side2){ /*The funtion calculate area of largest square.*/
	double radius;
	if(side1>side2){
		radius=side1;
	}
	if(side1<side2){
		radius=side2;
	}							/*via if,edges were  compared .*/
	else{
		radius=side1;
	}
	int area, side;
	side=radius;
	
	area= calc_area_of_square (side);
	return area;
}

double calc_area_of_square (int side){ /*The funtion calculate area of square.*/
	int area=pow(side,2);
	return area;
}

void display_results(double largest_circle, double largest_square, double smallest_circle, double smallest_square){	 /*The funtion had print function work. */
	printf("Area of Largest Circle : %lf \n",largest_circle);
	printf("Area of Largest Square: %lf \n",largest_square);
	printf("Area of Smallest Circle: %lf \n",smallest_circle);
	printf("Area of Smallest Square: %lf \n",smallest_square);	
}	
