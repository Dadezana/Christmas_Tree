#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


#define DEC1 "#"
#define DEC2 "•"
#define MAX_VOID 5

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLDYELLOW  "\033[1m\033[33m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDWHITE   "\033[1m\033[37m"
#define BOLDRED     "\033[1m\033[31m"

string randomColor(){
	int color = rand()%4;

	switch(color){

		case 0:
			return BOLDRED;

		case 1:
			return BOLDYELLOW;

		case 2:
			return RED;

		case 3:
			return BOLDWHITE;
	}
	return WHITE;
}

int main(int argc, char **argv) {

	int n, i, j, r;

	if (argc > 1)
		n = atoi(argv[1]);
	else
		n = 20;
	
	srand(time(NULL));

	bool canAddDec = true;
	int numVoid = 0;

	for(i = 1; i <= n; i++) {
		
	// Empty spaces before tree
		for (j = 1; j <= n-i; j++){
			cout <<  " ";
		}
		
		for (j = 1; j <= i; j++) {

			if (i == n){
				
				cout << BOLDGREEN << "*" << RESET;
			}else {
				if (j == 1)
					cout << BOLDGREEN << "*" << RESET;
				else {

				//* genera addobbi random
					r = rand()%n;
					if (r == 0){
						cout << randomColor() << (canAddDec ? DEC1 : " ") << RESET;
						canAddDec = !canAddDec;

					} else if (r == 1) {
						cout << randomColor() << (canAddDec ? DEC2 : " ") << RESET;
						canAddDec = !canAddDec;
					
					}else if(numVoid > MAX_VOID){
						numVoid = 0;
						canAddDec = false;
						r = rand()%2;

						switch(r){
							case 0:
								cout << randomColor() << DEC1 << RESET;
								break;

							case 1:
								cout << randomColor() << DEC2 << RESET;
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
				cout << BOLDGREEN << "*" << RESET;
			}else {
				if (j == i-1)
					cout << BOLDGREEN << "*" << RESET;
				else {
					r = rand()%n;
					if (r == 0){
						cout << randomColor() << (canAddDec ? DEC1 : " ") << RESET;
						canAddDec = !canAddDec;

					} else if (r == 1) {
						cout << randomColor() << (canAddDec ? DEC2 : " ") << RESET;
						canAddDec = !canAddDec;
					
					}else if(numVoid > MAX_VOID){
						numVoid = 0;
						canAddDec = false;
						r = rand()%2;

						switch(r){
							case 0:
								cout << randomColor() << DEC1 << RESET;
								break;

							case 1:
								cout << randomColor() << DEC2 << RESET;
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
		cout << BOLDGREEN << "***" << RESET;
		cout << endl;
	}
	
	return 0;
}
