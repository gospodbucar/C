#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	//ustvarim nov pointer za delo z datotekami
	FILE * datoteka;

	//odpre rezultati2.txt in nadaljuje shranjevanje, če bi hotel na novo bi dal ""w
	datoteka = fopen("rezultati2.txt", "a");
	
	int i, x, y, ponovitev = 0,stevilo, suma  = 0;
	
	printf("Vnesite zeljeno stevilo elementov \t");
	scanf("%d", &i);
	int tabela[i];

	//vnos vseh elementov v tabelo
	for (int j = 0; j < i ; j++)
		{ 
			printf("vpisite element %d \t\t\t", j+1); // j+1 da ne pise vnesi element 0
			scanf("%d", &x);
			tabela[j] = x;
		}

	printf("vnesi celo stevilo za iskanje \t\t\t");
	scanf("%d", &y);

	//izpis v datoteko
	fprintf(datoteka, "Stevilo elementov polja: %d\n", i);
	fprintf(datoteka, "Vneseno polje je: ");
  
	//izpis celotne tabele
	for (int z = 0; z < i ; z++)
                {
                fprintf(datoteka, "%d, ", tabela[z]);
                }
	fprintf(datoteka, "\nStevilo za iskanje je: %d\n", y);

	//preverjanje stevila ponovitev st. za iskanje v tabeli
	for (int j = 0; j < i; j++)
               {
                        if (y == tabela[j])
				{
                        		ponovitev++;
                		}

               }

	fprintf(datoteka, "Celo stevilo %d se pojavi v polju %d krat \n", y, ponovitev);

	//preverjanje kolikokrat se vsak element ponovi v tabeli
	
	for (int j = 0; j < i ; j++)
		{
			stevilo = 0;
			int true = 1;
			
			for (int k = 0; k < i ; k++)
				{
				   if (tabela[k] == tabela[j])
                                	{                               
                                       		stevilo++;
                                	}
				}
                        if (stevilo == 1)
                                        {
              fprintf(datoteka, "stevilo %d se ponovi %d krat\n",tabela[j], stevilo);
                                        }
			else
				{
		                        for (int z = 0; z < j ; z++)
						{
							if (tabela[j] == tabela[z]){
								true = 0;
							}

	
						}
						
					if (true  == 1){
              fprintf(datoteka, "stevilo %d se ponovi %d krat\n",tabela[j], stevilo);
				true = 1;
										     					}
                }
                }

			//zapis prvega elementa v tabeli
			fprintf(datoteka, "pozicija minimalnega elementa je 0 ter njegova vrednost je %d\n", tabela[0]);

//sestejem vse elemente

	for(int j = 0 ; j < i; j++)
		{
		suma += tabela[j];
		}
	
	
fprintf(datoteka, "suma vseh elementov polja je %d \n\n", suma);

//zaprem datoteko
fclose(datoteka);
return 0;

	

 }
