#include <stdio.h>
#include <stdbool.h>

void main(void)
{
            float resultat = 0;
			bool valid = true;
			float operandLinks = 0;
			char operatore = ' ';
			float operandRechts = 0;

			printf("Geben sie Erste Zahl ein:");
			scanf("%f",&operandLinks);
			getchar(); //Eingabe Puffer leeren
			printf("Geben Sie den Operand ein [+,-,:,*]:");
			scanf("%c",&operatore);
			getchar(); //Eingabe Puffer leeren
            printf("Geben sie zweite Zahl ein:");
			scanf("%f",&operandRechts);


			switch (operatore)
			{
				case '+':
					resultat = operandLinks + operandRechts;
					break;
				case '-':
					resultat = operandLinks - operandRechts;
					break;
				case '*':
					resultat = operandLinks * operandRechts;
					break;
				case '/':
					resultat = operandLinks / operandRechts;
					break;
				default:
					valid = false;
					break;

			}

			if (valid)
			{
				printf(" = %f",resultat);
			}
			else
			{
				printf("ungültige Eingabe");
			}

}