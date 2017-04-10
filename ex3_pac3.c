#include <stdio.h>

const int ENDSEQ = -1;

const int PROMO_LOYALTY = 0.95;

typedef enum {FALSE,TRUE} bool;

void addToAmound (float *amount, float price,int qtt, char promo, float VAT);
float computeNoPromoPrice (float price, int qtt, float VAT);
float computeNxMPromoPrice (int N,int M,float price,int qtt, float VAT);
float computeHalfPromoPrice (float price, int qtt, float VAT);

bool loyaltyCard;
int code,qtt,percent;
char promo,card,blank;
float price,VAT,amount;

int main(int argc, char **argv)
{
amount= 0.0;
scanf("%c",&card);
loyaltyCard = (card=='S');
scanf("%c", &blank);
scanf("%d", &code);
while (code!=ENDSEQ)
{
	scanf("%f",&price);
	scanf("%d",&qtt);
	scanf("%c",&blank);
	scanf("%c",&promo);
	scanf("%c",&blank); 
	scanf("%d",&percent);
	VAT= 1.0 + (((float)(percent) / 100.0)); 
	addToAmound( &amount, price, qtt, promo, VAT ); 
	scanf("%d",&code);
	}

  if (loyaltyCard){
	amount=amount*0.95;
}	
printf("%.2f" , amount);

	return 0;
}

void addToAmound (float *amount, float price,int qtt, char promo, float VAT){
 
	float productPrice;
	productPrice=0.0;
	switch (promo) {
		case 'N':
			productPrice= computeNoPromoPrice( price, qtt, VAT );
			break;
		case 'T':
			productPrice= computeNxMPromoPrice( 3, 2, price, qtt, VAT );
			break;
		case 'D':
			productPrice= computeNxMPromoPrice( 2, 1, price, qtt, VAT );
			break;
		default :
			productPrice= computeHalfPromoPrice( price, qtt, VAT );
	}
		*amount=*amount + productPrice;
	
 	
}
 float computeNoPromoPrice (float price, int qtt, float VAT)
 {
	 return price * (float)(qtt) * VAT;
 }
 float computeNxMPromoPrice (int N,int M,float price,int qtt, float VAT)
 {
	 float promo,nopromo;
	 promo= (float)(qtt/N) * (float)(M) * price * VAT;
	 nopromo= (float )(qtt % N) * price * VAT;
	 
	 return promo + nopromo;
 }
 
float computeHalfPromoPrice (float price, int qtt, float VAT)
{
	float promo,nopromo;
	nopromo=((float)(qtt/2)+(float)(qtt % 2)) * price * VAT;
	promo= (float)(qtt/2) * price* 0.5 * VAT;
	
	return promo + nopromo;
	
 
} 




