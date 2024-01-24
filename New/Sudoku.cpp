
#include<iostream>
#include<iomanip>
#include<windows.h>
#include<conio.h>
#include<cmath>
using namespace std;
/// void functions
void playSudoku();
void exitMenu();
void checkGame();
void upKey();
void downKey();
void leftKey();
void rightKey();
void pausGame();
void helpSudoku(string located);
void setPuzzle(int level);
void makePuzzle(string target,string puzzle);
void setNumberKey(string value);
void showProgressHardMode(double final_progress);
void hideCursor(bool condition);
void gotoMenu(char choice);
void colorSet(int tint);
void gamePart(string part);
void mainGame();

/// Other functions
char gameLevel();

/// Global Variable
 int level=0,correct=0,sudokupointer=0,sudokuPuzzleSize,sudokuBuildNumber;
 double final_progress=0;
 string sudokuStatus, sudokuPuzzle[81],sudokuHighlight[81],sudokuSolution[81];
 ///Main Programe
 int main(){
     hideCursor(true);///hide cursor
     //SetConsolTitle(("Sudoku"));
     int choice; ///variable
     while(true){
        system("cls");
        colorSet(2); ///dark red
        gamePart("line_small_left");
        colorSet(15); ///white
        cout<<"SUDOKU";
        colorSet(2);
        gamePart("line_small_right");
        colorSet(15);
        cout<<"[1]";
        colorSet(10); ///light cyan
        cout<<"START"<<endl;
        colorSet(15);
        cout<<"[2]";
        colorSet(10);  /// yellow
        cout<<"INSTRUCTIONS"<<endl;
        colorSet(15);
        cout<<"[3]";
        colorSet(10); /// light red
        cout<<"EXIT"<<endl;
        colorSet(2);
        gamePart("seperator");
        colorSet(7);  /// light gray
        cout<<"Press the number of your choice!";
        colorSet(15);
          ///Get user choice
          char select = getch();
          if(!(select<'1'||select>'3'))
          {
              choice=select;
              break;
          }
     }
     gotoMenu(choice); /// go to menu of user choice
 }

void gotoMenu(char choice){
 if(choice=='1') playSudoku(); /// go to play menu
 else if(choice=='2') helpSudoku("main"); ///go to instructions menu
 else if(choice=='3') exitMenu(); /// go to exit menu

}
void playSudoku(){ /// Play
 char setlevel = gameLevel(); /// game level
 if(setlevel=='4') main();    /// go to main
 else{
    level = (int)setlevel-48; ///initialize level
    setPuzzle(level);         /// set level
    sudokuStatus ="playing";   /// set status
    sudokupointer = 0;        /// set pointer
    checkGame();              /// progress
    mainGame();               /// enter the game
 }
 getch();
 main();
}

char gameLevel(){
 char choice;
 do{
    system("cls");
    colorSet(2);
     gamePart("line_small_left");
    colorSet(15);
    cout<<"SUDOKU";
    colorSet(2);
     gamePart("line_small_right");
    colorSet(15);
     cout<<setw(29)<<right<<"SELECT A DIFFICULTY"<<endl;
    colorSet(2);
     gamePart("separator");
    colorSet(15);
     cout<<"[1]";
    colorSet(10);  /// light green
     cout<<"EASY"<<endl;
    colorSet(15);
     cout<<"[2]";
    colorSet(10);
     cout<<"MEDIUM"<<endl;
    colorSet(15);
     cout<<"[3]";
    colorSet(10); /// light red
     cout<<"HARD"<<endl;
    colorSet(2);
     gamePart("seperator");
    colorSet(7); /// light gray
     cout<<"Press the number of your choice! ";
    colorSet(15);
      char select = getch();
      if(!(select<'1'||select>'4')){
        choice = select;
        break;
      }
 }
   while(true);
 return choice;
}

void showProgressHardMode(double final_progress){
  if(final_progress >= 69){
    if(final_progress >= 84){
        if(final_progress >= 94){
            cout<<"Just a little bit";
        }
        else{
            cout<<"Almost there!";
        }
    }
    else{
        cout<<"Half-way-there!";
    }
  }
  else{
    cout<<"Unfinished";
  }
}


void setPuzzle(int level){
 string dot =".";
 string puzzle,highlight,solution;

 if(level==1){  /// Easy Lavel
       puzzle =(" .7.8|3.1. | . . "+ dot
              + " .4. | .2.6|5. . "+ dot
              + "6. . |9.4.7|8. .1"+ dot

              + "2. . | . . | .4. "+ dot
              + "5. . |7. .1| . .2"+ dot
              + " .1. | . . | . .3"+ dot

              + "4. .5| . . | . .9"+ dot
              + " . .1|4.5. | .2. "+ dot
              + " . . | .9.2|4.7. " );


    highlight =("0.F.F|F.F.0|0.0.0"+ dot
              + "0.F.0|0.F.F|F.0.0"+ dot
              + "F.0.0|F.F.F|F.0.F"+ dot

              + "F.0.0|0.0.0|0.F.0"+ dot
              + "F.0.0|F.0.F|0.0.F"+ dot
              + "0.F.0|0.0.0|0.0.F"+ dot

              + "F.0.F|0.0.0|0.0.F"+ dot
              + "0.0.F|F.F.0|0.F.0"+ dot
              + "0.0.0|0.F.F|F.F.0" );


     solution =("9.7.8|3.1.5|2.6.4"+ dot
              + "1.4.3|8.2.6|5.9.7"+ dot
              + "6.5.2|9.4.7|8.3.1"+ dot

              + "2.3.7|5.8.9|1.4.6"+ dot
              + "5.6.4|7.3.1|9.8.2"+ dot
              + "8.1.9|2.6.4|7.5.3"+ dot

              + "4.2.5|6.7.8|3.1.9"+ dot
              + "7.9.1|4.5.3|6.2.8"+ dot
              + "3.8.6|1.9.2|4.7.5" );
 }
 else if(level==2){   /// Medium Level
       puzzle =(" .8.4|2. . | . .9"+ dot
              + "1. .2|8. . |5. . "+ dot
              + "9. . | .6. | . .3"+ dot

              + " .9. | . . |2.7. "+ dot
              + "5. . | . . | . .8"+ dot
              + " .4.8| . . | .3. "+ dot

              + "7. . | .2. | . .1"+ dot
              + " . .3| . .6|7. .4"+ dot
              + "4. . | . .5|3.9. " );


    highlight =("0.F.F|F.0.0|0.0.F"+ dot
              + "F.0.F|F.0.0|F.0.0"+ dot
              + "F.0.0|0.F.0|0.0.F"+ dot

              + "0.F.0|0.0.0|F.F.0"+ dot
              + "F.0.0|0.0.0|0.0.F"+ dot
              + "0.F.F|0.0.0|0.F.0"+ dot

              + "F.0.0|0.F.0|0.0.F"+ dot
              + "0.0.F|0.0.F|F.0.F"+ dot
              + "F.0.0|0.0.F|F.F.0" );


     solution =("3.8.4|2.5.7|1.6.9"+ dot
              + "1.6.2|8.3.9|5.4.7"+ dot
              + "9.7.5|1.6.4|8.2.3"+ dot

              + "6.9.1|3.4.8|2.7.5"+ dot
              + "5.3.7|6.9.2|4.1.8"+ dot
              + "2.4.8|5.7.1|9.3.6"+ dot

              + "7.5.9|4.2.3|6.8.1"+ dot
              + "8.2.3|9.1.6|7.5.4"+ dot
              + "4.1.6|7.8.5|3.9.2" );
 }
 else{   /// Hard Level
       puzzle =(" .8. |5.2. |6.4. "+ dot
              + "7. .6| . . | . .2"+ dot
              + "4.2. | . . | .3. "+ dot

              + " .5. | . .1| . . "+ dot
              + "6. . |7.8.3| . .9"+ dot
              + " . . |9. . | .6. "+ dot

              + " .3. | . . | .2.6"+ dot
              + "1. . | . . |3. .5"+ dot
              + " .9.2| .3.5| . . " );


    highlight =("0.F.0|F.F.0|F.F.0"+ dot
              + "F.0.F|0.0.0|0.0.F"+ dot
              + "F.F.0|0.0.0|0.F.0"+ dot

              + "0.F.0|0.0.F|0.0.0"+ dot
              + "F.0.0|F.F.F|0.0.F"+ dot
              + "0.0.0|F.0.0|0.F.0"+ dot

              + "0.F.0|0.0.0|0.F.F"+ dot
              + "F.0.0|0.0.0|F.0.F"+ dot
              + "0.F.F|0.F.F|0.0.0" );


     solution =("9.8.3|5.2.7|6.4.1"+ dot
              + "7.1.6|3.4.8|5.9.2"+ dot
              + "4.2.5|1.9.6|7.3.8"+ dot

              + "2.5.9|4.6.1|8.7.3"+ dot
              + "6.4.1|7.8.3|2.5.9"+ dot
              + "3.7.8|9.5.2|1.6.4"+ dot

              + "5.3.7|8.1.4|9.2.6"+ dot
              + "1.6.4|2.7.9|3.8.5"+ dot
              + "8.9.2|6.3.5|4.1.7" );
 }
 /// Create the Puzzle
 makePuzzle("puzzle_layout",puzzle);
 makePuzzle("highlight_layout",highlight);
 makePuzzle("solution_layout",solution);
}

void makePuzzle(string target, string puzzle){
int size = puzzle.size();
char cpuzzle[size];
int pointer = 0;
for(int i=0; i<sizeof(cpuzzle);i++){
    cpuzzle[i]= puzzle[i];
    if(!(cpuzzle[i]=='.' || cpuzzle[i]=='|')){
        string sudokuNumber(1,cpuzzle[i]);
        if(target == "puzzle_layout"){
            sudokuPuzzle[pointer] = sudokuNumber;  ///cout<<"["<<pointer<<"]: "<<sudokuNumber<<" ";
        }
        else if(target == "highlight_layout"){
             sudokuHighlight[pointer] = sudokuNumber;
        }
        else if(target == "solution_layout"){
            sudokuSolution[pointer] = sudokuNumber;
        }
        pointer++;
    }
}
cout<<endl<<endl;
}

void mainGame(){
   system("cls");
   colorSet(2);
    gamePart("line_small_left");
   colorSet(15);
    cout<<"SUDOKU";
   colorSet(2);
    gamePart("line_small_right");
   switch(level)  /// Level Part
   {
   case 1:
    colorSet(15);
    cout<<setw(24)<<right<<"EASY LEVEL"<<endl;
    break;
   case 2:
     colorSet(15);
    cout<<setw(25)<<right<<"MEDIUM LEVEL"<<endl;
    break;
   default:
     colorSet(15);
     cout<<setw(24)<<right<<"HARD LEVEL"<<endl;
     break;
   }

   colorSet(2);
    gamePart("seperator");
    cout<<endl;

    int colorTable = 2; /// Table color
    sudokuPuzzleSize = (sizeof(sudokuPuzzle)/sizeof(sudokuPuzzle[0]));
    if(sudokuStatus == "quitted"){  /// Fetch solution
        for(int checker=0; checker<sudokuPuzzleSize; checker++){
            sudokuPuzzle[checker] = sudokuSolution[checker];
        }
    }

    sudokuBuildNumber = 0;
    for(int tpart=1; tpart<=182; tpart++){
        if(tpart==1 || tpart==62 || tpart==122 || tpart==182){
            colorSet(colorTable);
            gamePart("sudoku_outer_border");
        }
        else if(tpart==2 || tpart==8 || tpart==14 || tpart==22 || tpart==28 ||
                tpart==34|| tpart==42 || tpart==49 || tpart==55 || tpart==63 ||
                tpart==69 || tpart==75 || tpart==83 || tpart==89 || tpart==95 ||
                tpart==103 || tpart==109 ||tpart==115 || tpart==123 || tpart==129 ||
                tpart==135 || tpart==143 || tpart==149 || tpart==155 || tpart==163 ||
                tpart==169 || tpart==175){
                    colorSet(colorTable);
                    gamePart("sudoku_outer_vertical_border_small");
                }
        else if(tpart==20 || tpart==40 ||tpart==61 || tpart==81 || tpart==101 ||
                tpart==121 || tpart==141 || tpart==161 || tpart==181){
                    colorSet(colorTable);
                    gamePart("sudoku_outer_vertical_border_next_line");
                }
        else if(tpart ==   3 || tpart ==   5 || tpart ==   7 || tpart ==   9 || tpart ==  11 || tpart ==  13 ||
					tpart ==  15 || tpart ==  17 || tpart ==  19 || tpart ==  23 || tpart ==  25 || tpart ==  27 ||
					tpart ==  29 || tpart ==  31 || tpart ==  33 || tpart ==  35 || tpart ==  37 || tpart ==  39 ||
					tpart ==  43 || tpart ==  45 || tpart ==  47 || tpart ==  50 || tpart ==  52 || tpart ==  54 ||
					tpart ==  56 || tpart ==  58 || tpart ==  60 || tpart ==  64 || tpart ==  66 || tpart ==  68 ||
					tpart ==  70 || tpart ==  72 || tpart ==  74 || tpart ==  76 || tpart ==  78 || tpart ==  80 ||
					tpart ==  84 || tpart ==  86 || tpart ==  88 || tpart ==  90 || tpart ==  92 || tpart ==  94 ||
					tpart ==  96 || tpart ==  98 || tpart == 100 || tpart == 104 || tpart == 106 || tpart == 108 ||
					tpart == 110 || tpart == 112 || tpart == 114 || tpart == 116 || tpart == 118 || tpart == 120 ||
					tpart == 124 || tpart == 126 || tpart == 128 || tpart == 130 || tpart == 132 || tpart == 134 ||
					tpart == 136 || tpart == 138 || tpart == 140 || tpart == 144 || tpart == 146 || tpart == 148 ||
					tpart == 150 || tpart == 152 || tpart == 154 || tpart == 156 || tpart == 158 || tpart == 160 ||
					tpart == 164 || tpart == 166 || tpart == 168 || tpart == 170 || tpart == 172 || tpart == 174 ||
					tpart == 176 || tpart == 178 || tpart == 180){

				colorSet(15);

				///COLOR
				if(sudokuHighlight[sudokuBuildNumber]=="0"){
					colorSet(15);
				}
				else if(sudokuHighlight[sudokuBuildNumber]=="F"){
					colorSet(11);
				}

				//DISPLAY POINTER OR NOT
				if(sudokuStatus == "quitted" || sudokuStatus == "finished"){
					//OUTPUT NUMBER
					cout<<sudokuPuzzle[sudokuBuildNumber];
				}
				else{

					//POINTER
					if(sudokuBuildNumber == sudokupointer){
						colorSet(10);
						if(sudokuHighlight[sudokupointer]=="F")
						 {
						 	colorSet(10);
							cout<<sudokuPuzzle[sudokuBuildNumber];
						 }
						 else{

						 	if(sudokuPuzzle[sudokuBuildNumber] ==  "1" || sudokuPuzzle[sudokuBuildNumber] ==  "2" ||
							   sudokuPuzzle[sudokuBuildNumber] ==  "2" || sudokuPuzzle[sudokuBuildNumber] ==  "3" ||
							   sudokuPuzzle[sudokuBuildNumber] ==  "4" || sudokuPuzzle[sudokuBuildNumber] ==  "5" ||
							   sudokuPuzzle[sudokuBuildNumber] ==  "6" || sudokuPuzzle[sudokuBuildNumber] ==  "7" ||
							   sudokuPuzzle[sudokuBuildNumber] ==  "8" || sudokuPuzzle[sudokuBuildNumber] ==  "9"){
									cout<<sudokuPuzzle[sudokuBuildNumber];
							}
							else{
									cout<<"x";
							}

						 }

					}
					else{
						//OUTPUT NUMBER
						cout<<sudokuPuzzle[sudokuBuildNumber];
					}

				}
				//ADD
				sudokuBuildNumber++;

			}
        else if(tpart ==   4 || tpart ==   6 || tpart ==  10 || tpart ==  12 || tpart ==  16 || tpart ==  18 ||
					tpart ==  24 || tpart ==  26 || tpart ==  30 || tpart ==  32 || tpart ==  36 || tpart ==  38 ||
					tpart ==  44 || tpart ==  46 || tpart ==  51 || tpart ==  53 || tpart ==  57 || tpart ==  59 ||
					tpart ==  65 || tpart ==  67 || tpart ==  71 || tpart ==  73 || tpart ==  77 || tpart ==  79 ||
					tpart ==  85 || tpart ==  87 || tpart ==  91 || tpart ==  93 || tpart ==  97 || tpart ==  99 ||
					tpart == 105 || tpart == 107 || tpart == 111 || tpart == 113 || tpart == 117 || tpart == 119 ||
					tpart == 125 || tpart == 127 || tpart == 131 || tpart == 133 || tpart == 137 || tpart == 139 ||
					tpart == 145 || tpart == 147 || tpart == 151 || tpart == 153 || tpart == 157 || tpart == 159 ||
					tpart == 165 || tpart == 167 || tpart == 171 || tpart == 173 || tpart == 177 || tpart == 179){
				colorSet(colorTable);
				gamePart("sudoku_inner_vertical_border_small");
			}
			//SUDOKU INNER BORDER
			else if(tpart == 21 || tpart == 41 || tpart == 82 || tpart == 102 || tpart == 142 || tpart == 162){
				colorSet(colorTable);
				gamePart("sudoku_inner_border");
			}
		}
		cout<<endl;

		final_progress = round(((double(correct)/81.0)*100.0));

		if(sudokuStatus == "playing"){
            colorSet(11);
            cout<<"Progress: ";
            colorSet(15);

            switch(level){
            case 1:
                cout<<correct<<"/81";
                break;
            case 2:
                cout<<final_progress<<"%";
                break;
            default:
                showProgressHardMode(final_progress);
            }
            cout<<endl;
            colorSet(14);
            cout<<"Press";
            colorSet(12);
            cout<<"[Esc]";
            colorSet(15);
            cout<<" or ";
            colorSet(12);
            cout<<"[P]";
            colorSet(14);
            cout<<"to pause the game";
		}
		else if(sudokuStatus == "quitted"){
            colorSet(10);
            cout<<" Sorry you did not finish"<<endl;
            cout<<" the sudoku puzzle."<<endl;
            colorSet(10);
            cout<<"Better luck next time!"<<endl;
            colorSet(10);
            cout<<"By the way, thats the solutioon."<<endl;
            colorSet(7);
            cout<<"[Press any ley to exit the game]";
            getch();
            main();
		}
		else  if(sudokuStatus == "finished"){
            colorSet(10);
            cout<<"Congratulation you solve"<<endl;
            cout<<" the sudoku puzzle."<<endl;
            colorSet(13);
            cout<<"Your sudoku skills are"<<endl;
            cout<<" quite impressive!"<<endl;
            colorSet(7);
            cout<<" [Press any key to exit the game]";
            getch();
            main();
		}
		else{ /// hidden details
            cout<<"pointer: "<<sudokupointer<<endl;
            cout<<"Highlight: "<<sudokuHighlight[sudokupointer]<<endl;
		}

		while(true){
            int keyPress;
            colorSet(15);
             keyPress = 0;   /// reset
             keyPress = getch();  /// get nuber
            if(keyPress==0 || keyPress==224){
                keyPress = 256 + getch();  /// Convert key code
                if(keyPress==328){
                    upKey();
                    break;
                }
                else if(keyPress==336){
                    downKey();
                    break;
                }
                else if(keyPress == 331){
                    leftKey();
                    break;
                }
                else if(keyPress == 333){
                    rightKey();
                    break;
                }
                else if(keyPress == 339){
                    setNumberKey("clear");
                    break;
                }
            }
            else{ /// Movement key
                if(keyPress == 119 || keyPress == 87){ /// up (w)
                    upKey();
                    break;
                }
                else if(keyPress == 115 || keyPress == 83){ /// down (s)
                    downKey();
                    break;
                }
                else if(keyPress == 97 || keyPress == 65){  /// left (a)
                    leftKey();
                    break;
                }
                else if(keyPress == 100 || keyPress == 68){   /// right (d)
                    rightKey();
                    break;
                }
                /// Number Key
                if(keyPress == 49){
                    setNumberKey("1");
                    break;
                }
                else if(keyPress == 50){
                    setNumberKey("2");
                    break;
                }
                 else if(keyPress == 51){
                    setNumberKey("3");
                    break;
                }
                 else if(keyPress == 52){
                    setNumberKey("4");
                    break;
                }
                 else if(keyPress == 53){
                    setNumberKey("5");
                    break;
                }
                 else if(keyPress == 54){
                    setNumberKey("6");
                    break;
                }
                 else if(keyPress == 55){
                    setNumberKey("7");
                    break;
                }
                 else if(keyPress == 56){
                    setNumberKey("8");
                    break;
                }
                else if(keyPress == 57){
                    setNumberKey("9");
                    break;
                }
                else if(keyPress == 8){  /// Backspace
                    setNumberKey("clear");
                }
                else if(keyPress == 27 || keyPress == 112 || keyPress == 80){  /// Escape (Esc) or P
                    pausGame();
                    break;
                }
                else{
                    continue;
                }
            }
		}

		checkGame();
}

void checkGame(){
 sudokuPuzzleSize =(sizeof(sudokuPuzzle)/sizeof(sudokuPuzzle[0]));
 correct = 0; /// rest total of correct number in the gride
 for(int sudokuPointing = 0; sudokuPointing < sudokuPuzzleSize; sudokuPointing++){
    if(sudokuPuzzle[sudokuPointing]==sudokuSolution[sudokuPointing]){
        correct++;
    }
 }
 if(correct == sudokuPuzzleSize){  /// Game finishrd
    sudokuStatus = "finished";
 }
 mainGame(); /// Resume to the game
}
/// Game control function
void upKey(){
    sudokupointer = sudokupointer - 9;
        if(sudokupointer==-9){
            sudokupointer = 72;
        }
        else if(sudokupointer == -8){
            sudokupointer = 73;
        }
        else if(sudokupointer == -7){
            sudokupointer = 74;
        }
        else if(sudokupointer == -6){
            sudokupointer = 75;
        }
        else if(sudokupointer == -5){
            sudokupointer = 76;
        }
        else if(sudokupointer == -4){
            sudokupointer = 77;
        }
        else if(sudokupointer == -3){
            sudokupointer = 78;
        }
        else if(sudokupointer == -2){
            sudokupointer = 79;
        }
        else if(sudokupointer == -1){
            sudokupointer = 80;
        }
}

void downKey(){
    sudokupointer = sudokupointer + 9;
        if(sudokupointer == 81){
            sudokupointer = 0;
        }
        else if(sudokupointer == 82){
            sudokupointer = 1;
        }
        else if(sudokupointer == 83){
            sudokupointer = 2;
        }
        else if(sudokupointer == 84){
            sudokupointer = 3;
        }
        else if(sudokupointer == 85){
            sudokupointer = 4;
        }
        else if(sudokupointer == 86){
            sudokupointer = 5;
        }
        else if(sudokupointer == 87){
            sudokupointer = 6;
        }
        else if(sudokupointer == 88){
            sudokupointer = 7;
        }
        else if(sudokupointer == 89){
            sudokupointer = 8;
        }
        else if(sudokupointer == 90){
            sudokupointer = 9;
        }
}

void leftKey(){
    sudokupointer = sudokupointer - 1;
        if(sudokupointer == 62){
            sudokupointer = 71;
        }
        else if(sudokupointer == 71){
            sudokupointer = 80;
        }
        else if(sudokupointer == 53){
            sudokupointer = 62;
        }
        else if(sudokupointer == 44){
            sudokupointer = 53;
        }
        else if(sudokupointer == 35){
            sudokupointer = 44;
        }
        else if(sudokupointer == 26){
            sudokupointer = 35;
        }
        else if(sudokupointer == 17){
            sudokupointer = 26;
        }
        else if(sudokupointer == 8){
            sudokupointer = 17;
        }
        else if(sudokupointer == -1){
            sudokupointer = 8;
        }
}

void rightKey(){
    sudokupointer = sudokupointer + 1;
        if(sudokupointer == 81){
            sudokupointer = 72;
        }
        else if(sudokupointer == 72){
            sudokupointer = 63;
        }
        else if(sudokupointer == 63){
            sudokupointer = 54;
        }
        else if(sudokupointer == 54){
            sudokupointer = 45;
        }
        else if(sudokupointer == 45){
            sudokupointer = 36;
        }
        else if(sudokupointer == 36){
            sudokupointer = 27;
        }
        else if(sudokupointer == 27){
            sudokupointer = 18;
        }
        else if(sudokupointer == 18){
            sudokupointer = 9;
        }
        else if(sudokupointer == 9){
            sudokupointer = 0;
        }
}
/// Set number key or clear the number in the grid
void setNumberKey(string value){
    if(!(value == "clear")){
        if(sudokuHighlight[sudokupointer]=="0"){
            sudokuPuzzle[sudokupointer] = value;
        }
    }
    else{
        if(sudokuHighlight[sudokupointer] == "0"){
            sudokuPuzzle[sudokupointer] = " ";
        }
    }
}
/// Pause game
void pausGame(){
    do{ /// Display
        system("cls");
        colorSet(2);
         gamePart("line_small_left");
        colorSet(15);
         cout<<"SUDOKU";
        colorSet(2);
         gamePart("line_small_right");
        colorSet(10);
         cout<<setw(24)<<right<<"GAME PAUSED"<<endl;
        colorSet(2);
         gamePart("seperator");
        colorSet(15);
         cout<<"[1]";
        colorSet(10);
         cout<<"RESUME"<<endl;
        colorSet(15);
         cout<<"[2]";
        colorSet(10);
         cout<<"INSTRUCTIONS"<<endl;
        colorSet(15);
         cout<<"[3]";
        colorSet(10);
         cout<<"QUIT"<<endl;
        colorSet(2);
         gamePart("seperator");
        colorSet(7);
         cout<<"Press the number of your choice!";
        colorSet(15);
        /// Get the user choice
        char select = getch();
        if(!(select<'1' || select>'3')){
            cout<<endl;
            if(select == '2'){
                helpSudoku("In-game");
            }
            else if(select == '3'){
                sudokuStatus = "quitted";
                break;
            }
            else{
                break;
            }
        }

    }
    while(true);
}
/// Instruction
void helpSudoku(string located){
        system("cls");
        colorSet(4);
         gamePart("line_small_left");
        colorSet(15);
         cout<<"SUDOKU";
        colorSet(4);
         gamePart("line_small_right");
        colorSet(13);
         cout<<setw(24)<<right<<"INSTRUCTIONS"<<endl;
        colorSet(4);
         gamePart("seperator");
        colorSet(10);
         cout<<"How to play: "<<endl;
        colorSet(15);
         cout<<" * The sudoku puzzle is consist of a 9x9 grid, you have to fill the empty squares using the numbers 1 to 9."<<endl;
         cout<<" * Use the 1-9 keys in your keyboard to fill the sudoku puzzle."<<endl;
         cout<<" * To move arround the sudoku puzzle, use the WASD letter keys or the arrow keys."<<endl;
         cout<<" * Use backspace or delete key to clear the number selected in the sudoku puzzle."<<endl;
         cout<<" * Once you finish the sudoku puzzle, it will prompt you can press P then you can choose \"Quuit\" in the pause menu  if you having a hard time."<<endl;
        colorSet(2);
         gamePart("seperator");
        colorSet(7);
         cout<<"Press any key to go back!"<<endl;
        colorSet(15);
        getch(); /// Pause
        if(located == "main"){
            main();
        }
}
/// Exit
void exitMenu(){
    do{  /// Display
        system("cls");
        colorSet(2);
         gamePart("line_small_left");
        colorSet(15);
         cout<<"SUDOKU";
        colorSet(2);
         gamePart("line_small_right");
        colorSet(10);
         cout<<setw(24)<<right<<"DO YOU WANT TO EXIT"<<endl;
        colorSet(2);
         gamePart("seperator");
        colorSet(15);
         cout<<"[1]";
        colorSet(10);
         cout<<"YES"<<endl;
        colorSet(15);
         cout<<"[2]";
        colorSet(10);
         cout<<"NO"<<endl;
        colorSet(2);
         gamePart("seperator");
        colorSet(7);
         cout<<"Press the number of your choice!";
        colorSet(15);
        /// Get user choice
        char select = getch();
        if(!(select<'1' || select>'2')){
            cout<<endl;
            if(select == '1'){
                exit(0);
            }
            else{
                main();
            }
        }
    }
    while(true);
}

void colorSet(int tint){ /// Color set
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),tint);
}

void gamePart(string part){
 if(part == "line_small_left"){
    cout<<"=============";
 }
 else if(part=="line_small_right"){
    cout<<"==============="<<endl;;
 }
 else if(part=="seperator"){
    cout<<"=================================="<<endl;
 }
 else if(part == "sudoku_outer_border"){
    cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
 }
 else if(part =="sudoku_outer_vertical_border_small"){
    cout<<"$";
 }
 else if(part =="sudoku_outer_vertical_border_next_line"){
    cout<<"$"<<endl;
 }
 else if(part == "sudoku_inner_vertical_border_small"){
    cout<<"  | ";
 }
 else if(part=="sudoku_inner_border"){
    cout<<"$---*---*---$---*---*---$---*---*---$"<<endl;
 }
 else{
    cout<<"";
 }
}

void hideCursor(bool condition){  /// Hide Cursor in the Console
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = (!(condition)); /// set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}
