#include <stdio.h>
    
	const int MAXPRODUCTS = 100;
	const int MAXSTORES = 50;
	const int MARGIN = 50;
	const int ENDSEQ = -1;
	
	typedef struct tProduct { int productCode; int availableUnits; int minStock; int unitsRequested;} tProduct;
	typedef struct tStock{ tProduct products[100]; int numProd;} tStock;
	typedef struct tStoreOrder{ tProduct order [100] ; int numProducts; } tStoreOrder;
	typedef struct tChain { tStoreOrder stores [50]; int numStores;} tChain;
	 typedef enum {FALSE,TRUE} bool;

	void readProduct (tProduct *product);
    void initializeChain (tChain *chain);
    void updateWareHouse ( tStock *stock, tProduct product);
    void processOrder (tStock *stock, tChain *chain, int storeCode );
    void addProductToStore (tChain *chain, int storeCode, tProduct product);
    void addProductToStock (tStock *stock, tProduct product);
    void computeResults (tStock stock, tChain chain);


	


int main(int argc, char **argv)
{
	 
	 tStock stock;
	 tChain chain; 
	 int currentCode;
	 tProduct product;
	stock.numProd= 0;
	
	scanf( "%d", &currentCode);
	while (currentCode != -1) {
		product.productCode= currentCode;
		 readProduct(&product);
		 updateWareHouse(&stock, product);
		scanf("%d", &currentCode);
		}
     initializeChain(&chain);
	scanf("%d", &currentCode);
	while (currentCode != -1) {
		 processOrder(&stock,&chain,currentCode);
		scanf("%d", &currentCode);
	}
	computeResults(stock, chain);
	return 0;
}

void readProduct (tProduct *product)
{
	scanf("%d", &(*product).availableUnits);
	scanf("%d", &product->minStock);
}

void initializeChain (tChain *chain)
{
	 int i;
	for (i=1;i<50;i++)
	{
	chain->stores[i].numProducts= 0;	
	}
	chain->numStores= 0;
	
}
void updateWareHouse ( tStock *stock, tProduct product) {

	 int i;
	i=stock->numProd + 1;
	stock->products[i].productCode=product.productCode;
	stock->products[i].availableUnits=product.availableUnits;
	stock->products[i].minStock=product.minStock;
	stock->products[i].unitsRequested=0;
    stock->numProd=stock->numProd +1;
}
void processOrder(tStock *stock,tChain *chain,int storeCode)
{
	int numProducts;
	int j;
	tProduct product;
	
	scanf("%d",&numProducts);
	for (j=1;j<=numProducts;j++){
		scanf("%d", &product.productCode);
		scanf("%d", &product.unitsRequested);
		addProductToStore( chain, storeCode,product);
		addProductToStock(stock,product);
}}
 
void addProductToStore (tChain *chain, int storeCode,tProduct product)
{
	int i;
	bool found;
	found=FALSE;
	i=1;
	while(i<=chain->stores[storeCode].numProducts && found==FALSE){
		found= (chain->stores[storeCode].order[i].productCode==product.productCode);
		if (found==FALSE){
			i=i+1;
		}
		
		}
	chain->stores[storeCode].order[i].availableUnits=chain->stores[storeCode].order[i].availableUnits-product.unitsRequested;
	chain->stores[storeCode].order[i].unitsRequested=chain->stores[storeCode].order[i].unitsRequested+product.unitsRequested;
	if (found==FALSE){
		chain->stores[storeCode].numProducts=chain->stores[storeCode].numProducts+1;
		chain->stores[storeCode].order[i].productCode=product.productCode;
	}
	}
	
void addProductToStock (tStock *stock, tProduct product)
{
	 int i;
	 bool found;
	
	i=1;
	found=FALSE;
	while ((i<=stock->numProd) && (found==FALSE))
	{
     if (stock->products[i].productCode != product.productCode){
	 i=i+1;}
		 else{
	     found=TRUE;}
		 
	 } 
stock->products[i].availableUnits=stock->products[i].availableUnits-product.unitsRequested;	
stock->products[i].unitsRequested=stock->products[i].unitsRequested + product.unitsRequested;
} 
void computeResults (tStock stock, tChain chain)
{
	 int i;
	 int j;
	 
	 int maxProductUnits;
     int maxProductCode;
	maxProductUnits= 0;	
    maxProductCode= 0;
	for (i=1;i<=stock.numProd;i++){
		printf ("%d", stock.products[i].productCode);
		printf("%c", ' ');
		printf ("%d", stock.products[i].availableUnits);
		printf("%c", ' ');
		if( (stock.products[i].availableUnits)  >= (stock.products[i].minStock)  ){
		printf("%d",0);
		printf("%c", ' ');}
			else{
				
		printf("%d", stock.products[i].minStock  - stock.products[i].availableUnits + 50);
		printf("%c", ' ');}
		if (maxProductUnits < stock.products[i].unitsRequested){
			maxProductUnits=  stock.products[i].unitsRequested;
			maxProductCode=   stock.products[i].productCode;
			
		}
		
		}
		
		
	printf ("%d", ENDSEQ);
	printf("%c", ' ');
    printf ("%d", maxProductCode);
	printf("%c", ' ');
	printf ("%d", maxProductUnits);
	printf("%c", ' ');
	for(i=1;i<50;i++){
		for (j=1;j<=chain.stores[i].numProducts;j++){ 
			if (chain.stores[i].order[j].productCode == maxProductCode ) {
				printf("%d", i);
				printf("%c", ' ');
				printf("%d", chain.stores[i].order[j].unitsRequested);
				printf("%c", ' ');
			}
			
	}
	
}
printf("%d", ENDSEQ);

}
    


	



     
     
     	

