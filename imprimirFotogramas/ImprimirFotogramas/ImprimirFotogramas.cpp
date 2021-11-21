#include <iostream>
using namespace std;
#define CONSOLE_HEIGHT 29
#define CONSOLE_WIDTH 119
int main()
{
	char ConsoleScreen[CONSOLE_HEIGHT][CONSOLE_WIDTH];
	
	for (int i = 0; i < CONSOLE_HEIGHT; i++)
	{
		for (int j = 0; j < CONSOLE_WIDTH; j++)
		{
			ConsoleScreen[i][j] = '-';
		}
		
	}
	for (int i = 0; i < CONSOLE_HEIGHT; i++)
	{
		for (int j = 0; j < CONSOLE_WIDTH; j++)
		{
			cout << ConsoleScreen[i];
		}
		cout << endl;
	}
}