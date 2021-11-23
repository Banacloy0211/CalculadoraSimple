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
bool run = true;

int main()
{
	RellenarMapa();
	ImprimirPantalla();
	while (run)
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
	case 'w':
		personaje_y--;
		break;
	case 'A':
	case 'a':	
		personaje_x--;
		break;
	case 'S':
	case 's':
		personaje_y++;
		break;		
	case 'D':
	case 'd':
		personaje_x++;
		break;
	case 'Q':
	case 'q':
		run = false;
		break;
	default:
		break;
	}

}


void ImprimirPantalla(){
	system("CLS");
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