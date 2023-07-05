// 200403623 Elif SAKAL

#include <stdio.h>
#define boyut 10 //dizinin boyut deðiþkenini 10 kapasiteli yaptým


char dizi[boyut];                              
char stack[boyut];
int top = -1;                                 
char eleman;                                     


void push(char eleman){                           
	if(top == boyut-1){                       
		puts("\n Üzgünüm stack doldu");
	}else{
		top++;                                 
		stack[top] = eleman;
	}
}

char peek(){                                     
	return stack[top];                       
}

char pop(){                                    
	eleman = stack[top];                         
	top--;
}

bool bosmu(){                                    
	if(top ==-1 ){                             
		return true;                            
	}else{
		return false;
	}
}

void yazdir(){                                   
	int j;                                       
	for(j = 0; j<=top; j++){
		printf("\nStack : %c", stack[j]);
	}
}

bool dogruMu(){
	int i;
	while(dizi[i] != '\0'){
		char d = dizi[i];
		printf("\neleman; %c", d);
		char peekd = peek();
		
		if(d== '(' || d== '{' || d== '['){
			push(d);
			printf("\npush edilen: %c", d);
		}
		else if(d== ')' || d== '}' || d== ']'){
			if(bosmu() == true){
				puts("\nstack bostur..");
				return false;
			}
		
			else if(d == ')' && peekd== '('){
				pop();
				
				printf("\npop edilen: %c", '(');
			}
			else if(d == '}' && peekd== '{'){
				pop();
				
					printf("\npop edilen: %c", '{');
			}		
			else if(d == ']' && peekd== '['){
				pop();
			
					printf("\npop edilen: %c", '[');
			}else{
				return false;
			}
		}
		i+=1;
	}
	return bosmu();
}

int main(int argc, char *argv[]){
	
	puts("\nDegerleri giriniz");
	fgets(dizi, sizeof(dizi), stdin);
	yazdir();
	
if(dogruMu()== true){
	puts("\n Parantezler eþleþti");
}else{
	puts("\n Parantezler eslesmedi");
}	
yazdir();	
}
