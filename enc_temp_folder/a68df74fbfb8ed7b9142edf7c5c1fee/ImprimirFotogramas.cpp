#include <iostream>
using namespace std;
#define CONSOLE_HEIGHT 29
#define CONSOLE_WIDTH 119

void RellenarMapa();
void Inputs();
void ImprimirPantalla();

char ConsoleScreen[CONSOLE_HEIGHT][CONSOLE_WIDTH];
char personaje = 'O';
int personaje_x = 10;
int personaje_y = 5;

int main()
{
	RellenarMapa();
	while (true)
	{
		Inputs();
		ImprimirPantalla();
	}
}

void RellenarMapa() {
	for (int i = 0; i < CONSOLE_HEIGHT; i++)
	{
		for (int j = 0; j < CONSOLE_WIDTH; j++)
		{
			if (i == 0 || i == CONSOLE_HEIGHT - 1 || j == 0 || j == CONSOLE_WIDTH - 1)
			{
				ConsoleScreen[i][j] = '#';
			}
			else {
				ConsoleScreen[i][j] = '-';
			}
		}

	}

}

void Inputs() {
	char input;
	cin >> input;
	switch (input)
	{
	case 'W':
		personaje_y--;
		break;
	case 'A':
		personaje_x--;
		break;
	case 'S':
		personaje_y++;
		break;		
	case 'D':
		personaje_x++;
		break;
			
	default:
		break;
	}

}


void ImprimirPantalla() {
	for (int i = 0; i < CONSOLE_HEIGHT; i++)
	{
		for (int j = 0; j < CONSOLE_WIDTH; j++)
		{
			if (personaje_x == j && personaje_y == i) {
				cout << personaje;

			}
			else
			{
				cout << ConsoleScreen[i][j];
			}

		}
		cout << endl;
	}
}