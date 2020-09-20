#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

#define MAX 4

using namespace std;

int Board[MAX][MAX];

int score;

int dirLine[] = { 1,0,-1,0 };
int dirColumn[] = { 0,1,0,-1 };

pair<int, int> generateUnoccupiedPosition() { // gan ket 2 thanh phan(chi so i va phan tu) - map // tao vi tri ngau nhien
	int occ = 1;
	int line, column;
	while (occ) {
		line = rand() % MAX;
		column = rand() % MAX;
		if (Board[line][column] == 0)
			occ = 0;
	}
	return make_pair(line, column);
}

void addPiece() {
	//tao bang ngau nhien
	pair<int, int> pos = generateUnoccupiedPosition();
	Board[pos.first][pos.second] = 2; // tao mot so 2 ngau nhien trong bang
}

void newGame() {
	score = 0;
	int i, j;
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			Board[i][j] = 0;
		}
	}
	addPiece();
}

void printUI()  {
	system("cls"); // xoa man hinh
	cout << "--------------------Play 2048 Game--------------------" << endl << endl;
	cout << "Score: " << score << endl;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (Board[i][j] == 0)
				cout << setw(MAX) << ".";
			else
				cout << setw(MAX) << Board[i][j];
		}
		cout << endl;
	}
	cout << endl << "n: new game, w: up, s: down, d: right, a: left, q: quit" << endl;
}

bool canDoMove(int line, int column, int nextLine, int nextColumn) {
	if (nextLine < 0 || nextColumn < 0 || nextLine >= MAX || nextColumn >= 4
		|| (Board[line][column] != Board[nextLine][nextColumn] && Board[nextLine][nextColumn] != 0) )
		return false;
	return true;
}

void applyMove(int dir) { //direction dieu hướng
	 // bat dau se = 0
	int startLine = 0, startColumn = 0, lineStep = 1, columnStep = 1; // gt lineStep, columnStep se quet dinh di xuong hay di len 
	if (dir == 0) { // neu di xuong phim s
		startLine = 3; // dong bat dau
		lineStep = -1; // neu di tu duoi len thi buoc = -1
	}
	if (dir == 1) {
		startColumn = 3;
		columnStep = -1;
	}
	int movePossible, canAddPiece = 0;;
	do { // cong don 
		movePossible = 0;
		for (int i = startLine; i >= 0 && i < MAX; i += lineStep) {
			for (int j = startColumn; j >= 0 && j < MAX; j += columnStep) {
				int nextI = i + dirLine[dir];
				int nextJ = j + dirColumn[dir];
				//cout << i << " " << j << " " << nextI << " " << nextJ << endl;
				if (Board[i][j] && canDoMove(i, j, nextI, nextJ)) {// kiem tra de di chuyen
					
					Board[nextI][nextJ] += Board[i][j];
					if (Board[nextI][nextJ] > 2)
						score += Board[nextI][nextJ];
					Board[i][j] = 0; // di chuyen se bang 0
					movePossible = canAddPiece = 1;
				}
			}
		}
		printUI();
	} while (movePossible);
	if (canAddPiece)
		addPiece();
}

int main() {
	srand(time(0));
	char cmdToDir[128]; //ASCI // setup keyboard
	cmdToDir['s'] = 0;
	cmdToDir['d'] = 1;
	cmdToDir['w'] = 2;
	cmdToDir['a'] = 3;
	newGame();
	while (1) {
		printUI();
		char cmd;
		cin >> cmd;
		if (cmd == 'n')
			newGame();
		else if (cmd == 'q')
			break;
		else {
			int curDir = cmdToDir[cmd]; // Phim hien tai
			//cout << curDir << endl;
			applyMove(curDir);
		}
	}
	cout << endl << "Your score: " << score << endl;
	cout << endl << "Thank you for playing!" << endl;
	return 0;
}