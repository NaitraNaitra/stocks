#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

#define FALSE 0
#define TRUE !FALSE

struct stock_data {
       char name[30];
       float buy_price;
       float current_price;
       };
       
void write_info(void);
void read_info(void);


void main()
{
  char c;
  int done=FALSE;
  
  while(!done){
               puts("\nStock Portfolio Thing\n");
               puts("A - Add new stock\n");
               puts("L - List stocks\n");
               puts("Q - Quit\n");
               printf("Your choice:");
               
               c= getch();
               c=toupper(c);
               
               switch(c){
                         case('A'):
                                   puts("Add new stock\n");
                                   write_info();
                                   break;
                         case('L'):
                                   puts("List stock\n");
                                   read_info();
                                   break;
                         case('Q'):
                                   puts("Quit\n");
                                   done = TRUE;
                                   break;
                          default:
                                  puts("\n\n\t\t\t?");
                                  break;
                                  }          
  
  
}
  system("PAUSE");	
  
}

void write_info(void){
     FILE *stocks;
     struct stock_data stock;
     char input[12];
     
     printf("Enter stock name: ");
     gets(stock.name);
     printf("How much did you pay for it? $");
     stock.buy_price = (float)atof(gets(input));
     stock.current_price = stock.buy_price/11;
     
     stocks = fopen("stock.dat","a");
     if(stocks==NULL){
                      puts("Error opening file");
                      system("PAUSE");
                      exit(1);}
                      
     fwrite(&stock,sizeof(stock),1,stocks);
     
     fclose(stocks);
     puts("Stock added. ");   
     
     }
     
     
     
void read_info(void){
     FILE *stocks;
     struct stock_data stock;
     int x;
     
     stocks = fopen("stock.dat","r");
     if(stocks == NULL){
               puts("No data in file");
               
               return;
     }
     
     while(TRUE){
                 x = fread(&stock,sizeof(stock),1,stocks);
                 
                 if(x==0) break;
                 
                 printf("\nStock name: %s\n",stock.name);
                 printf("Purchased for:$%.2f\n", stock.buy_price);
                 printf("Current price: $%.2f\n",stock.current_price);
                 }
                 fclose(stocks);
                 }
