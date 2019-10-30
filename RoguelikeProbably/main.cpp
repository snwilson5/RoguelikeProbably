#include <iostream>
#include <windows.h>
#include <winuser.h>
using namespace std;

void KeyDetection();
void Repaint();

int main()
{
	cout << "Hello";
	while (true)
	{
		Repaint();
		KeyDetection();//Player Action

	}
}


void KeyDetection()
{
	//This is essentially a stop point. The game will not continue until the user chooses an action

	bool bPressed = false;
	while (!bPressed)
	{
		if (GetAsyncKeyState(VK_UP))
		{
			cout << "up" << endl;
			bPressed = true;
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			cout << "down" << endl;
			bPressed = true;
		}
		else if (GetAsyncKeyState(VK_LEFT))
		{
			cout << "left" << endl;
			bPressed = true;
		}
		else if (GetAsyncKeyState(VK_RIGHT))
		{
			cout << "right" << endl;
			bPressed = true;
		}
	}
}

void Repaint()
{
	system("cls");
	cout << "Hello";
}
