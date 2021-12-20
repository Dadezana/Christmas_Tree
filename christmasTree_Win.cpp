#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


#define DEC1 "#"
#define DEC2 "*"
#define MAX_VOID 5


const int RESET = 0x07;
const int GREEN = 0x02;
const int RED = 0x04;
const int YELLOW = 0x06;
const int WHITE = 0x07;

/*
0 = Black       8 = Gray
1 = Blue        9 = Light Blue
2 = Green       A = Light Green
3 = Aqua        B = Light Aqua
4 = Red         C = Light Red
5 = Purple      D = Light Purple
6 = Yellow      E = Light Yellow
7 = White       F = Bright White
*/

void Color(int color=0x07)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int randomColor(){
	int color = rand()%4;

	switch(color){

		case 0:
			return RED;

		case 1:
			return YELLOW;

		case 2:
			return RED;

		case 3:
			return WHITE;
	}
	return WHITE;
}

int main(int argc, char **argv) {

	int n, i, j, r;

	if (argc > 1)
		n = atoi(argv[1]);
	else
		n = 10;

	srand(time(NULL));

	bool canAddDec = true;
	int numVoid = 0;

	for(i = 1; i <= n; i++) {

	//* Spazi vuoti prima dell'albero
		for (j = 1; j <= n-i; j++){
			cout <<  " ";
		}
		for (j = 1; j <= i; j++) {

			if (i == n){
                Color(GREEN);
				cout << "*";

			}else {
				if (j == 1){
                    Color(GREEN);
					cout << "*";

				}
				else {

				//* genera addobbi random
					r = rand()%n;
					if (r == 0){
                        Color(randomColor());
						cout << (canAddDec ? DEC1 : " ");

						canAddDec = !canAddDec;

					} else if (r == 1) {
						Color(randomColor());
						cout << (canAddDec ? DEC2 : " ");

						canAddDec = !canAddDec;

					}else if(numVoid > MAX_VOID){
						numVoid = 0;
						canAddDec = false;
						r = rand()%2;

						switch(r){
							case 0:
								Color(randomColor());
                                cout << DEC1;

								break;

							case 1:
								Color(randomColor());
                                cout << DEC2;

								break;
						}

					}else {
						cout << " ";
						canAddDec = true;
						numVoid++;
					}
				}
			}


		}
		for (j = 1; j < i; j++) {
			if (i == n){
				Color(GREEN);
				cout << "*";

			}else {
				if (j == i-1){
					Color(GREEN);
                    cout << "*";

				}
				else {
					r = rand()%n;
					if (r == 0){
						Color(randomColor());
						cout << (canAddDec ? DEC1 : " ");

						canAddDec = !canAddDec;

					} else if (r == 1) {
						Color(randomColor());
						cout << (canAddDec ? DEC2 : " ");

						canAddDec = !canAddDec;

					}else if(numVoid > MAX_VOID){
						numVoid = 0;
						canAddDec = false;
						r = rand()%2;

						switch(r){
							case 0:
								Color(randomColor());
                                cout << DEC1;

								break;

							case 1:
								Color(randomColor());
                                cout << DEC2;

								break;
						}

					}else {
						cout << " ";
						canAddDec = true;
						numVoid++;
					}
				}
			}
		}
		cout << endl;
	}
	for (i = 1;i <= 3; i++) {
		for(j = 1; j <= n-2; j++){
			cout << " ";
		}
		Color(GREEN);
		cout << "***";

		cout << endl;
	}

	Color(RESET);
	return 0;
}
