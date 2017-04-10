#include <stdio.h>
#include <math.h>

const char SQUARE= 'S';
const char RECTANGLE ='R';
const char CIRCLE= 'C';
const char ELIPSE= 'E';
const char END= 'F';

float CalculateAreaForEllipse (float a, float b);
float CalculateAreaForCircle ( float r);
float CalculateAreaForRectangle (float b, float h);
float CalculateAreaForSquare (float l);
float CalculateAreaForTriangle (float  b, float h);
float CalculateAreaForRombo (float  D, float d);



int main(int argc, char **argv)
{
	
	char type,blank;
	float l,r,a,b,h,D,d;
	float area;
	
	area = 0.0;
	scanf("%c",&type);
	while (type != END)
	{
    switch(type) {
		case 'S' :
			scanf ("%f",&l);
			b= l;
			h= l;
			area=CalculateAreaForRectangle ( b, h );
			break;
		case 'R' :
			scanf ("%f%f",&b,&h);
			area=CalculateAreaForRectangle( b, h );
			break;
		case 'C' :
			scanf ("%f",&r);
			a= r;
			b= r;
			area=CalculateAreaForEllipse( a, b );
			break;
		case 'E' :
			scanf ("%f %f",&a,&b);
			area=CalculateAreaForEllipse( a, b );
			break;
		case 'T' :
			scanf ("%f %f",&b,&h);
			area=CalculateAreaForTriangle( b, h );
			break;
		case 'B' :
			scanf ("%f %f",&D,&d);
			area=CalculateAreaForRombo( D, d );
			break;	
		default :
			printf("No existeix aquesta fórmula");
}
	 
	
	printf ("%.1f", area);
	scanf ("%c",&blank);
	scanf ("%c",&type);
	}
	 
printf ("%C", END);
return 0;
}
 
 float CalculateAreaForSquare (float l)
 {
       float area;
	   if (l>0.0)
	   {area= l*l;
	   }
       else { area= 0.0;}

       return area;
 
 }
 
 float CalculateAreaForRectangle (float b, float h)
 {
	 float area;
	 if (b>0.0 && h>0.0)
	 {area= b*h;
	 }
	 else { area= 0.0;}
	 
	 return area;
	 }
	 
float CalculateAreaForCircle ( float r)
{
	float area;
	if (r>0.0)
	{
     area=M_PI*r*r;
    }
    else {
		area=0.0;
	}
	return area;
	} 
 
float CalculateAreaForEllipse (float  a, float b)
{   float area;
	if (a>0.0 && b>0.0)
	{
		area=M_PI*a*b;
	}
	else{
		area=0.0;
	}
	return area;
}   	

float CalculateAreaForTriangle (float  b, float h)
{   float area;
	if (b>0.0 && h>0.0)
	{
		area=(b*h)/2;
	}
	else{
		area=0.0;
	}
	return area;
}   	
float CalculateAreaForRombo (float  D, float d)
{   float area;
	if (D>0.0 && d>0.0)
	{
		area=(D*d)/2;
	}
	else{
		area=0.0;
	}
	return area;
}   	
