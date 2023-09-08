 #include<stdio.h>

int main(){
	int entero = 10, *p_entero = &entero;
	float flotante = 20.5, *p_flotante = &flotante;
	char caracter = 'a', *p_caracter = &caracter;
	
	printf("Variable Entera:\n");
	printf("Dato: %i",*p_entero);  
	printf("\nPosicion: %p",p_entero); 
	
	printf("\n\nVariable Flotante:\n");
	printf("Dato: %.2f",*p_flotante);
	printf("\nPosicion: %p",p_flotante);
	
	printf("\n\nVariable Caracter:\n");
	printf("Dato: %c",*p_caracter);
	printf("\nPosicion: %p",p_caracter);	
	
	
	return 0;
}

