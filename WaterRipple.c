#include <unistd.h> 

char Board[23][80];
int RowArr[8];
int ColArr[8];
int Row, Col;

int main() {
    void Start();

}

void Start() {
    //For Loop To Find Position
    Row = 10, Col = 20;
    int Counter = 7;
    int Count = 1;
    Setup();
    Board[Row-1
    while(Counter--) {
        usleep(1000000);
        Zero(Count);
        FortyFive(Count);
        Ninety(Count);
        OneThirtyFive(Count);
        OneEighty(Count);
        TwoTwentyFive(Count);
        TwoSeventy(Count);
        ThreeFifteen(Count);
        Count++;
    }

}

void Zero(int Count) {
    int Iter = 0;
    RowArr[0]--;
    ColArr[0]--;
    for(Iter; Iter < Count * 2 + 1; Iter++) {
        Board[RowArr[0]][ColArr[0] + Iter] = "_";
    }
}

void FortyFive(int Count) {
    int Iter = 0;
    RowCol[1] = RowCol[1] + 2;
    for(Iter; Iter < Count * 2 + 1; Iter++) {
        Board[RowArr[1] - Iter][ColArr[1] - Iter] = "\\";
    }
}

void Ninety(int Count) {
    RowCol[2] = RowCol[2] + 2;
    Board[RowArr[2]][RowCol[2]] = "|";
}

void OneThirtyFive(int Count) {
    int Iter = 0;
    RowCol[3] = RowCol[3] + 2;
    for(Iter; Iter < Count * 2 + 1; Iter++) {
        Board[RowArr[3] - Iter][ColArr[3] - Iter] = "/";
    }
}

void OneEighty(int Count) {
    int Iter = 0;
    RowArr[4]++;
    RowCol[4]--;
    for(Iter; Iter < Count * 2 + 1; Iter++) {
        Board[RowArr[4]][ColArr[4] + Iter] = "_";
    }
}

void TwoTwentyFive(int Count) {
    int Iter = 0;
    RowCol[5] = RowCol[5] - 2;
    for(Iter; Iter < Count * 2 + 1; Iter) {
        Board[RowArr[5] + Iter][ColArr[5]] = "\\";
    }
}

void TwoSeventy(int Count) {
    RowCol[6] = RowCol[6] - 2;
    Board[RowArr[6]][RowCol[6]] = "|";
}

void ThreeFifteen(int Count) {
    int Iter;
    ColArr[7] = ColArr[7] - 2;
    for(Iter; Iter < Count * 2 + 1; Iter) {
        Board[RowArr[7] - Iter][ColArr[7] + Iter];
    }
}

void Setup() {
    RowArr[0] = Row - 2;
    ColArr[0] = Col;
    Board[RowArr[0]][ColArr[0]] = "_";

    RowArr[1] = Row - 1;
    ColArr[1] = Col + 1;
    Board[RowArr[1]][ColArr[1]] = "\\";

    RowArr[2] = Row;
    ColArr[2] = Col + 2;
    Board[RowArr[2]][ColArr[2]] = "|";

    RowArr[3] = Row + 1;
    ColArr[3] = Col + 1;
    Board[RowArr[3]][ColArr[3]] = "/";

    RowArr[4] = Row + 2;
    ColArr[4] = Col;
    Board[RowArr[4]][ColArr[4]] = "_";

    RowArr[5] = Row + 1;
    ColArr[5] = Col - 1;
    Board[RowArr[5]][ColArr[5]] = "\\";

    RowArr[6] = Row;
    ColArr[6] = Col - 2;
    Board[RowArr[6]][ColArr[6]] = "|";

    RowArr[7] = Row - 1;
    ColArr[7] = Col - 1;
    Board[RowArr[7]][ColArr[7]] = "/";

}









