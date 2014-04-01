#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "keyboard.h"
#include "xterm_control.h"

void startRipple();
void Zero(int);
void FortyFive(int);
void Ninety(int);
void OneThirtyFive(int);
void OneEighty(int);
void TwoTwentyFive(int);
void TwoSeventy(int);
void ThreeFifteen(int);
void Setup();
void PutInTerminal();
void ClearBoard();

char Board[23][81];
int RowArr[8];
int ColArr[8];
int Row, Col, Counter;
int mup, mdown, mleft, mright;
char *greeting = "Arrow keys work, F3 starts effect, and F9 terminates...";


void startRipple() {
    int Count = 1;
    int i, j;
    Counter = 0;
    mup = 1, mdown = 1, mleft = 1, mright = 1;
    for(i = 0; i < 23; i++) {
      for(j = 0; j < 80; j++) {
	if(Board[i][j] > '0' && Board[i][j] <= '9') {
	  Row = i;
	  Col = j;
	  Counter = Board[i][j] - '0';
	}
      }
    }

    if(Counter == 0)
      return;
    Setup();
    PutInTerminal();
    ClearBoard();
    while(--Counter) {
      Zero(Count);
      Ninety(Count);
      OneEighty(Count);
      TwoSeventy(Count);
      FortyFive(Count);
      OneThirtyFive(Count);
      TwoTwentyFive(Count);
      ThreeFifteen(Count);
      Count++;
      PutInTerminal();
      ClearBoard();
    }     
}                                    

void Zero(int Count) {
    int endIter = Count *2 + 1, Iter = 0, bcount = -1, flag = 0;
    //bcount is the counter for bouncing
    //flag marks that the wave has tried going beyond the boundary
    if(ColArr[0] != 0)
      ColArr[0]--;
    else
      endIter = Count*2;

    if(RowArr[0] == 0 && mup == 1) {
      mup = 0;
      return;
    } else if(mup == 0) {
      mup = -1;
    } else {
      RowArr[0] -= mup;
    }
    
    for(Iter = 0; Iter < endIter; Iter++) {
      if(ColArr[0] + Iter == 80) {
	flag = 1;
      }
      if(flag) {
	bcount += 2;
	Board[RowArr[0]][ColArr[0] + Iter - bcount] = '_';
      } else {
	Board[RowArr[0]][ColArr[0] + Iter] = '_';
      }
    }
}

void FortyFive(int Count) {
  int Iter = 0, hflag = 0, hbcount = -1, vflag = 0, vbcount = -1;
  //h for horizontal, v for vertical, b for bounce
  char slash = '\\';

  if(mright == -1 && ColArr[2] != 79) {
    ColArr[1] = ColArr[2] + 1;
    slash = '/';
  } else if(mright == -1) {
    ColArr[1] = ColArr[2];
    hbcount = 0;
  } else {
    ColArr[1] = ColArr[2] - 1;
  }

  for(Iter = 0; Iter < Count + 1; Iter++) {
    if(ColArr[1] - mright*Iter == 80) {
      hflag = 1;
      slash = '\\';
    }
    if(RowArr[1] - Iter < 0) {
      vflag = 1;
      slash = '/';
    }
    if(hflag) {
      hbcount += 2;
      Board[RowArr[1] - Iter][ColArr[1] - mright * Iter - hbcount] = slash;
    } else if(vflag) {
      vbcount += 2;
      Board[RowArr[1] - Iter + vbcount][ColArr[1] - mright * Iter] = slash;
    } else {
      Board[RowArr[1] - Iter][ColArr[1] - mright * Iter] = slash;
    }
  }
}

void Ninety(int Count) {
  if(ColArr[2] == 79 && mright == 1) {
    ColArr[2] = 78;
    mright = -1;
  } else if(ColArr[2] == 78 && mright == 1) {
    ColArr[2] = 79;
    mright = -1;
  } else {
    ColArr[2] = ColArr[2] + mright * 2;
  }
    Board[RowArr[2]][ColArr[2]] = '|';
}

void OneThirtyFive(int Count) {
  int Iter = 0, hflag = 0, vflag = 0, hbcount = -1, vbcount = -1;
  char slash = '/';

  if(mright == -1 && ColArr[2] != 79) {
    ColArr[3] = ColArr[2] + 1;
    slash = '\\';
  } else if(mright == -1) {
    ColArr[3] = ColArr[2];
    hbcount = 0;
  } else {
    ColArr[3] = ColArr[2] - 1;
  }

  for(Iter = 0; Iter < Count + 1; Iter++) {
    if(ColArr[3] - mright * Iter == 80 ) {
      hflag = 1;
      slash = '/';
    }
    if(RowArr[3] + Iter == 23) {
      vflag = 1;
      slash = '\\';
    }
    if(hflag) {
      hbcount += 2;
      Board[RowArr[3] + Iter][ColArr[3] - mright * Iter - hbcount] = slash;
    } else if(vflag) {
      vbcount += 2;
      Board[RowArr[3] + Iter - vbcount][ColArr[3] - mright * Iter] = slash;
    } else {
      Board[RowArr[3] + Iter][ColArr[3] - mright * Iter] = slash;
    }
  }
}

void OneEighty(int Count) {
    int endIter = Count *2 + 1, Iter = 0, bcount = -1, flag = 0;
    //bcount is the counter for bouncing
    //flag marks that the wave has tried going beyond the boundary
    if(RowArr[4] == 22 && mdown == 1) {
      mdown = -1;
    }
    RowArr[4] += mdown;
    if(ColArr[4] != 0)
      ColArr[4]--;
    else
      endIter = Count*2;
    for(Iter = 0; Iter < endIter; Iter++) {
      if(ColArr[0] + Iter == 80) {
	flag = 1;
      }
      if(flag) {
	bcount += 2;
	Board[RowArr[4]][ColArr[4] + Iter - bcount] = '_';
      } else {
	Board[RowArr[4]][ColArr[4] + Iter] = '_';
      }
    }
}

void TwoTwentyFive(int Count) {
  int Iter = 0, hflag = 0, vflag = 0, hbcount = -1, vbcount = -1;
  char slash = '\\';

  if(mleft == -1 && ColArr[6] != 0) {
    ColArr[5] = ColArr[6] - 1;
    slash = '/';
  } else if(mleft == -1) {
    ColArr[5] = ColArr[6];
    hbcount = 0;
  } else {
    ColArr[5] = ColArr[6] + 1;
  }

  for(Iter = 0; Iter < Count + 1; Iter++) {
    if(ColArr[5] + mleft * Iter == -1) {
      hflag = 1;
      slash = '\\';
    }
    if(RowArr[5] + Iter == 23) {
      vflag = 1;
      slash = '/';
    }
    if(hflag) {
      hbcount += 2;
      Board[RowArr[5] + Iter][ColArr[5] + mleft * Iter + hbcount] = slash;
    } else if(vflag) {
      vbcount += 2;
      Board[RowArr[5] + Iter - vbcount][ColArr[5] + mleft *Iter] = slash;
    } else {
      Board[RowArr[5] + Iter][ColArr[5] + mleft * Iter] = slash;
    }
  }
}

void TwoSeventy(int Count) {
  if(ColArr[6] == 0 && mleft == 1) {
    ColArr[6] = 1;
    mleft = -1;
  } else if(ColArr[6] == 1 && mleft == 1) {
    ColArr[6] = 0;
    mleft = -1;
  } else {
    ColArr[6] = ColArr[6] - mleft * 2;
  }
    Board[RowArr[6]][ColArr[6]] = '|';
}


void ThreeFifteen(int Count) {
  int Iter = 0, hflag = 0, vflag = 0, hbcount = -1, vbcount = -1;
  char slash = '/';

  if(mleft == -1 && ColArr[6] != 0) {
    ColArr[7] = ColArr[6] - 1;
    slash = '\\';
  } else if(mleft == -1) {
    ColArr[7] = ColArr[6];
    hbcount = 0;
  } else {
    ColArr[7] = ColArr[6] + 1;
  }

  for(Iter = 0; Iter < Count + 1; Iter++) {
    if(ColArr[7] + mleft * Iter == -1) {
      hflag = 1;
      slash = '/';
    }
    if(RowArr[7] - Iter < 0) {
      vflag = 1;
      slash = '\\';
    }
    if(hflag) {
      hbcount += 2;
      Board[RowArr[7] - Iter][ColArr[7] + mleft * Iter + hbcount] = slash;
    } else if(vflag) {
      vbcount += 2;
      Board[RowArr[7] - Iter + vbcount][ColArr[7] + mleft * Iter] = slash;
    } else {
      Board[RowArr[7] - Iter][ColArr[7] + mleft * Iter] = slash;
    }
  }
}

void Setup() {
    RowArr[0] = Row - 2;
    ColArr[0] = Col;
    Board[RowArr[0]][ColArr[0]] = '_';

    RowArr[1] = Row - 1;
    ColArr[1] = Col + 1;
    Board[RowArr[1]][ColArr[1]] = '\\';

    RowArr[2] = Row;
    ColArr[2] = Col + 2;
    Board[RowArr[2]][ColArr[2]] = '|';

    RowArr[3] = Row + 1;
    ColArr[3] = Col + 1;
    Board[RowArr[3]][ColArr[3]] = '/';

    RowArr[4] = Row + 1;
    ColArr[4] = Col;
    Board[RowArr[4]][ColArr[4]] = '_';

    RowArr[5] = Row + 1;
    ColArr[5] = Col - 1;
    Board[RowArr[5]][ColArr[5]] = '\\';

    RowArr[6] = Row;
    ColArr[6] = Col - 2;
    Board[RowArr[6]][ColArr[6]] = '|';

    RowArr[7] = Row - 1;
    ColArr[7] = Col - 1;
    Board[RowArr[7]][ColArr[7]] = '/';

}

void PutInTerminal() {
  int i, j;
  xt_par2(XT_SET_ROW_COL_POS,1,1);
  for(i = 0; i < 23; i++) {
    //for(j = 0; j < 80; j++) {
    //if (Board[i][j] != ' ') {
	//xt_par2(XT_SET_ROW_COL_POS, i, j);
	//putchar(Board[i][j]);
	//}
      //}
  printf("%s\n", Board[i]);

  }
  usleep(1000000);
}

void ClearBoard() {
  int i,j;
  for (i = 0; i < 23; i++) {
    for (j = 0; j < 80; j++) {
      Board[i][j] = ' ';
    }
  }
  xt_par0(XT_CLEAR_SCREEN);
  xt_par2(XT_SET_ROW_COL_POS,24,1);
  printf("%s",greeting);
  xt_par2(XT_SET_ROW_COL_POS,1,1);
}

void main() {
	int c, row, col;
	int i, j;
	xt_par2(XT_BG_BLUE,row=1,col=1);
	row = col = 1;
	xt_par0(XT_CLEAR_SCREEN);
	xt_par2(XT_SET_ROW_COL_POS,row=24,col=1);
  printf("%s", greeting);
	xt_par2(XT_SET_ROW_COL_POS,row=1,col=1);
	
	for (i = 0; i < 23; i++) {
	  for (j = 0; j < 80; j++) {
	    Board[i][j] = ' ';

	  }
	  Board[i][80] = '\0';
	}

	while (1) {
	  while ((c = getkey()) == KEY_NOTHING) ;
	  if(c == KEY_F9) break;
	  else if (c == KEY_F3)
	    startRipple();
	  else if (c == KEY_UP && row > 3) 
	    xt_par2(XT_SET_ROW_COL_POS,--row,col);
	  else if (c == KEY_DOWN && row < 21)
	    xt_par2(XT_SET_ROW_COL_POS,++row,col);
	  else if (c == KEY_RIGHT && col < 78)
	    xt_par2(XT_SET_ROW_COL_POS,row,++col);
	  else if (c == KEY_LEFT && col > 3)
	    xt_par2(XT_SET_ROW_COL_POS,row,--col);
	  else if (c == KEY_ENTER) 
	    xt_par2(XT_SET_ROW_COL_POS,++row,col=1);
	  else if (c == KEY_BACKSPACE && col > 1) {
	    xt_par2(XT_SET_ROW_COL_POS,row,--col);
	    putchar(' ');
	    Board[row - 1][col - 1] = ' ';
	    xt_par2(XT_SET_ROW_COL_POS,row,col);
	  } else if (c == KEY_DELETE) {
	    Board[row - 1][col - 1] = ' ';
	    putchar(' ');
	    xt_par2(XT_SET_ROW_COL_POS,row,col);
	  } else if (c >= '1' && c <= '9') {
	    putchar(c);
	    Board[row-1][col-1] = c;
	    if (col < 80) {
	      ++col;
	    } else if (row < 23) {
	      xt_par2(XT_SET_ROW_COL_POS,++row,col=1);
	    } else {
	      xt_par2(XT_SET_ROW_COL_POS,row,col);
	    }
	  }
	}
	getkey_terminate();

	xt_par2(XT_BG_DEFAULT,row=1,col=1);
	xt_par0(XT_CLEAR_SCREEN);
}
