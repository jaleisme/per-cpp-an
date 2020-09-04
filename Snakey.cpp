#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <unistd.h>
using namespace std;

//Variables
bool gameOver;
const int width = 50; //Ukuran map ke samping
const int height = 20; //Ukuran map ke atas
int x, y, fruitX, fruitY, score; // x&&y : Kepala Objek; fruitX&&fruitY : Objek 2; score : nilai
int tailX[100], tailY[100]; //Array objek tail
int nTail; //Jumlah Ekor
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup(){
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void Draw(){
	system("cls"); //Clear screen
	
	//Tembok Atas
	for(int i = 0; i < width+4; i++) {
		cout << "=";
	}
	
	cout << endl;
	
	// Tembok Pinggir
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++){
			
			if (j == 0)
				cout << "||";
			if (i == y && j == x)
				cout << "O";
			else if(i == fruitY && j == fruitX)
				cout << "H";
			else
			{
				bool print = false;				
				for (int k = 0; k < nTail; k++){
					if(tailX[k] == j && tailY[k] ==i){
						cout << "o";
						print = true;
					}
				}
				
				if(!print)
					cout << " ";
			}
			
			if (j == width - 1 )
				cout << "||";
			
		}
		cout << endl;
	}
	
	
	
	//Tembok Bawah
	for(int i = 0; i < width+4; i++) {
		cout << "=";
	}
	
	cout << endl;
	//Nampilin Score
	cout << "Score : " << score << endl;
}

void Input(){
	//Kalo mencet Keyboard
	if(_kbhit()){
		//Kalo mencet tombol arah
		switch(_getch()){
			case 'a' :
				dir = LEFT;
				break;
			case 'd' :
				dir = RIGHT;
				break;	
			case 's' :
				dir = DOWN;
				break;
			case 'w' :
				dir = UP;
				break;
			case 'x' :
				gameOver = true;
				break;
		}
	}
}

void Logic(){
	int prevX = tailX[0]; //Mengingat Arah Horizontal Objek 1 Sebelum pindah
	int prevY = tailY[0]; //Mengingat Arah Vertical Objek 1 Sebelum pindah
	int prev2X, prev2Y; //Mengingat Arah Horizontal dan Vertical dari Tail Objek 1 Sebelum pindah
	tailX[0] = x; //Objek Tail index pertama ngikut Objek 1 ke arah Horizontal
	tailY[0] = y; //Objek Tail index pertama ngikut Objek 1 ke arah Vertical
	
	for(int i = 1; i < nTail; i++){
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	
	
	// eventListener buat mindahin arah
	switch(dir){
		case LEFT :
			x--;
			break;
		case RIGHT :
			x++;
			break;
		case UP :
			y--;
			break;
		case DOWN :
			y++;
			break;
		default :
			break;
	}
	
	//Nabrak tembok
	if(x > width || x < 0 || y > height || y < 0){
		gameOver = true;
	}
	
	//!Nabrak tembok
//	if(x >= width) x = 0; else if(x < 0) x = width - 1;
//	if(y >= height) y = 0; else if(y < 0) y = height - 1;
	
	//Objek 1 Nabrak Tail
	for(int i = 0; i < nTail; i++)
		if(tailX[i] == x && tailY[i] == y)
			gameOver  = true;
	
	// Makan Buah
	if(x == fruitX && y == fruitY){
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}
	
}

int main(){
	//Setup
	Setup();
	
	//Selama Game On!
	while(!gameOver){
		Draw(); //Gambar Map dan Objek
		Input(); //Nambahin eventListener
		Logic(); //Nerapin Rule
		Sleep(1); //Mengurangi speed
	}
	return 0;
	
}
