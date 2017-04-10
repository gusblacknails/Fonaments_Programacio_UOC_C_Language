
#include <stdio.h>

#define END '#'

typedef enum {FALSE, TRUE} bool;

void ReadTheKey( int *key, char *car );
char EncryptChar( char car, int key );
char decryptChar( char car, int key );

int main(void)

{
	
int key;

char car, encryptedCar,decryptedCar;

ReadTheKey(&key,&car);

while (car != END)

{
 scanf("%c", &car);
 encryptedCar= EncryptChar(car,key);
 printf( "%c", encryptedCar );
 
  

}

 
 return 0;

}
char EncryptChar( char car, int key ){

int code, encrypted; 
char encryptedCar;

    code= (int)(car);
    encrypted= (256 + code + key) % 256; 
	encryptedCar= (char)( encrypted );

return encryptedCar;

}

void ReadTheKey( int *key, char *car )

{

scanf("%d", &key); 
scanf("%s\n", &car);
scanf("%s", &car);

}
char decryptChar( char car, int key )

{
 int code, encrypted; 
 char encryptedCar;
encryptedCar=0;
encryptedCar= (int)( encrypted );
code=(256 + encrypted + key) % 256;  
code= (char)(car);

return code;

}