#include<iostream>
#include<Windows.h>
#include<ctime>    // for eachtime different random values
#include<time.h>   // for Timer    from stackoverflow.com
#include<chrono>   // for Timer
#include<future>   // for Timer

using namespace std;

void myLine3(int x1, int y1, int x2, int y2,int R ,int G , int B);
void gotoxy(int x, int y);
void myLine(int x1, int y1, int x2, int y2,int color);
bool isCursorKeyPressed(int &whichKey);
void myRect(int x1, int y1, int x2, int y2, int R, int G, int B , int w );
void myEllipse(int x1, int y1, int x2, int y2, int R, int G, int B);
void triange(int x1 , int y1 , int x2 , int y2 , int R , int G , int B);
void duotriangle(int x1 , int y1 , int x2 , int y2 , int R , int G , int B);
void cross(int x1 , int y1 , int x2 , int y2 , int R , int G , int B);
void background( int i );          // interface background
void board();        // grid
void revtriange(int y2 , int x2 , int y1 , int x1 , int R , int G , int B);
bool samecandies( int arr[][8] );   //  not used it
void scorecounter(int &score);
bool samecandiescursorcheck( int arr[][8] , int y , int x , bool &flame);
void timer();
void Specialgem(int x1 , int y1 , int x2 , int y2 ,int R , int G , int B );
void Specialgemdelition(int arr[][8] , int y , int x );
int main()
{
	HANDLE	color=GetStdHandle(STD_OUTPUT_HANDLE); // to color the text
	SetConsoleTextAttribute(color,6);
	srand(time(0));        // for eachtime different random values
	int sa , x =0  , y = 0;       //  sa intro screen cursor
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE),CONSOLE_FULLSCREEN_MODE,0);
		gotoxy(80,15);
		cout<<"Bejeweled - Blitz"<<endl;
		gotoxy(80,17);
		cout<<"  Rules "<<endl;
		gotoxy(80,19);
		cout<<"  Tips"<<endl;
		gotoxy(80,21);
		cout<<"  Start"<<endl;
	for (int i = 0 ; i < 200 ; i++)  // for backround display
	{
		background(i);
		if(i == 99)
			i = 0;
			sa=0;
		isCursorKeyPressed(sa);
		if (sa == 2 && y>0)
		{
			y = y - 50;
			sa = 0 ;
		//	cout <<"( "<<x + 100 <<" , " << y <<" ) " ;
		}
		
		else if (sa == 4 && y<100)
		{
			y = y + 50;
			sa = 0 ;
		//	cout <<"( "<<x + 100 <<" , " << y <<" ) " ;
		}
		else if(sa == 5)
		{
			system("cls");
			break;
		}
		if(i%2==0)   // for blicking behind the text
		{
		gotoxy(78,15);
		cout<<"--| Bejeweled - Blitz |--"<<endl;
		gotoxy(80,17);
		cout<<"|   -   Rules   -   |"<<endl;
		gotoxy(80,19);
		cout<<"|   -   Tips    -   |"<<endl;
		gotoxy(80,21);
		cout<<"|   -   Start   -   |"<<endl;
		}
		myRect(860,400+y,1130,450+y,200,0,0,3);
		Sleep(100);
		myRect(860,400+y,1130,450+y,0,0,0,3);
		Sleep(100);
	}
	if (y == 0)
	{
		rules:
		for (int i = 0 ; i < 200 ; i++)
		{
			background(i);
			if(i == 199)
				i = 0;
				sa=0;
		isCursorKeyPressed(sa);
		if (sa == 2 && y>0)
		{
			y = y - 50;
			sa = 0 ;
		//	cout <<"( "<<x + 100 <<" , " << y <<" ) " ;
		}
		
		else if (sa == 4 && y < 50)
		{
			y = y + 50;
			sa = 0 ;
		//	cout <<"( "<<x + 100 <<" , " << y <<" ) " ;
		}
		else if(sa == 5)
		{
			if(y == 0)
				goto tips;
			system("cls");
			break;
		}
		if(i%2==0)   // for blicking behind the text
		{
		gotoxy(78,15);
		cout<<"--| Bejeweled - Blitz |--"<<endl;
		gotoxy(80,17);
		cout<<"|   -   Rules   -   |"<<endl;
		gotoxy(78,19);
		cout<<"--> Move your Cursor with Arrows Keys "<<endl;
		gotoxy(78,21);
		cout<<"--> To Swap the Candies use the General Gaming Key ( A , D , S , W ) "<<endl;
		gotoxy(78,23);
		cout<<"--> W to Swap up , A to Swap Right , S to Swap Down , D to Swap Right "<<endl;
		gotoxy(78,25);
		cout<<"--> Match 3 or More Candies of Same types in Any Direction Expext Daigonal Direction "<<endl;
		gotoxy(80,27);
		cout<<"|   -   Tips    -   |"<<endl;
		gotoxy(80,29);
		cout<<"|   -   Start   -   |"<<endl;
		}
		myRect(860,650+y,1130,700+y,200,0,0,3);
		Sleep(100);
		myRect(860,650+y,1130,700+y,0,0,0,3);
		//Sleep(100);
	}
	}
	else if (y == 50)
	{
		tips:
		for (int i = 0 ; i < 200 ; i++)
		{
			background(i);
			if(i == 199)
				i = 0;
				sa=0;
		isCursorKeyPressed(sa);
		if (sa == 2 && y>0)
		{
			y = y - 50;
			sa = 0 ;
		//	cout <<"( "<<x + 100 <<" , " << y <<" ) " ;
		}
		
		else if (sa == 4 && y < 50)
		{
			y = y + 50;
			sa = 0 ;
		//	cout <<"( "<<x + 100 <<" , " << y <<" ) " ;
		}
		else if(sa == 5)
		{
			system("cls");
			if(y == 0)
				goto rules;
			break;
		}
		if(i%2==0)      // for blicking behind the text
		{
		gotoxy(78,15);
		cout<<"--| Bejeweled - Blitz |--"<<endl;
		gotoxy(80,17);
		cout<<"|   -   Tips   -   |"<<endl;
		gotoxy(78,19);
		cout<<"--> Try to Makes possible Combination in the Given Time "<<endl;
		gotoxy(78,21);
		cout<<"--> Be Quick and Smart with your Moves just like Sir Aamir Wali  "<<endl;
		gotoxy(78,23);
		cout<<"--> Pop as Many Candies as you can to Score better "<<endl;
		gotoxy(78,25);
		cout<<"--> ------------------------------------- "<<endl;
		gotoxy(80,27);
		cout<<"|   -   Rules    -   |"<<endl;
		gotoxy(80,29);
		cout<<"|   -   Start   -   |"<<endl;
		}
		myRect(860,650+y,1130,700+y,200,0,0,3);
		Sleep(100);
		myRect(860,650+y,1130,700+y,0,0,0,3);
		Sleep(100);
	}
	}
	system("cls");    // clear screen
	int a , score = 0 , time = 60 ;
	x = 0 , y = 0 ; 
	int grid[8][8] , rnum;
	for(int i = 0 ; i < 8 ; i++)
		for(int j = 0 ; j <8 ; j++)
		{
			grid[i][j] = rand()%5;   // random values int the array
		}
		for(int i = 0 ; i < 8 ; i++)   // to check for any consective same values
		{	
			for(int j = 0 ; j <8 ; j++)
			{
					if (grid[i][j] == grid[i][j-1] && grid[i][j-1] == grid[i][j-2])
					{
						rnum = rand()%5;
						if(rnum != grid[i][j])
							grid[i][j] = rnum;

					}
					if (grid[i][j] == grid[i-1][j] && grid[i-1][j] == grid[i-2][j])
					{
					rnum = rand()%5;
						if(rnum != grid[i][j])
							grid[i][j] = rnum;
					}
			}
		}
		// display countdown
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<< "\t\t\t\t\t\t\t\t\t        |||||||                     "<<endl;
	cout<< "\t\t\t\t\t\t\t\t\t      |||     |||                   "<<endl;
	cout<< "\t\t\t\t\t\t\t\t\t     |||      |||                   "<<endl;
	cout<< "\t\t\t\t\t\t\t\t\t             |||                    "<<endl;
	cout<< "\t\t\t\t\t\t\t\t\t            |||                     "<<endl;
	cout<< "\t\t\t\t\t\t\t\t\t           |||                      "<<endl;
	cout<< "\t\t\t\t\t\t\t\t\t            |||                     "<<endl;
	cout<< "\t\t\t\t\t\t\t\t\t     |||      |||                   "<<endl;
	cout<< "\t\t\t\t\t\t\t\t\t      |||    |||                    "<<endl;
	cout<< "\t\t\t\t\t\t\t\t\t       ||||||||                     "<<endl;
	Sleep(2000);
	system("cls");

	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<< "\t\t\t\t\t\t\t\t\t        ||||||\                    "<<endl;
	cout<< "\t\t\t\t\t\t\t\t\t      |||    |||                   "<<endl;
	cout<< "\t\t\t\t\t\t\t\t\t     |||     |||                   "<<endl;
	cout<< "\t\t\t\t\t\t\t\t\t            |||                    "<<endl;
	cout<< "\t\t\t\t\t\t\t\t\t           |||                     "<<endl;
	cout<< "\t\t\t\t\t\t\t\t\t           |||                     "<<endl;
	cout<< "\t\t\t\t\t\t\t\t\t          |||                      "<<endl;
	cout<< "\t\t\t\t\t\t\t\t\t         |||                       "<<endl;
	cout<< "\t\t\t\t\t\t\t\t\t       ||||                        "<<endl;
	cout<< "\t\t\t\t\t\t\t\t\t      ||||||||||||                 "<<endl;
	Sleep(2000);
	system("cls");

	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<< "\t\t\t\t\t\t\t\t\t        |||||                     "<<endl;
	cout<< "\t\t\t\t\t\t\t\t\t      |||  ||                     "<<endl;
	cout<< "\t\t\t\t\t\t\t\t\t     |||   ||                     "<<endl;
	cout<< "\t\t\t\t\t\t\t\t\t           ||                     "<<endl;
	cout<< "\t\t\t\t\t\t\t\t\t           ||                     "<<endl;
	cout<< "\t\t\t\t\t\t\t\t\t           ||                     "<<endl;
	cout<< "\t\t\t\t\t\t\t\t\t           ||                     "<<endl;
	cout<< "\t\t\t\t\t\t\t\t\t           ||                     "<<endl;
	cout<< "\t\t\t\t\t\t\t\t\t           ||                     "<<endl;
	cout<< "\t\t\t\t\t\t\t\t\t      ||||||||||||                "<<endl;
	Sleep(2000);
	system("cls");
	board();
	gotoxy(100, 1);
    cout<<"Your Score : " << score ;
	gotoxy(100,3);
	cout<<"Time Remaining : ";
	async(timer);  // timer call
	
	do
	{
		board();
		int key = 0 ;
		bool flame = 0;
		int zx = x/100 , zy = y/100 , zx1 = x/100 , zy1 = y/100 ;
		//Sleep(200);
		isCursorKeyPressed(a);
		if (a == 1 && x>= 0)
		{
			x = x - 100;
			a = 0 ;
		//	cout <<"( "<<x + 100 <<" , " << y <<" ) " ;
		}
		else if (a == 2 && y>0)
		{
			y = y - 100;
			a = 0 ;
		//	cout <<"( "<<x + 100 <<" , " << y <<" ) " ;
		}
		else if (a == 3 && x< 600)
		{
			x= x + 100;
			a = 0 ;
		//	cout <<"( "<<x + 100 <<" , " << y <<" ) " ;
		}
		else if (a == 4 && y<700)
		{
			y = y + 100;
			a = 0 ;
		//	cout <<"( "<<x + 100 <<" , " << y <<" ) " ;
		}
		else if (a == 6 && x>= -100 )            // if A key is Pressed to swap left
		{
			//cout << zy1 <<" , "<< zx1 <<" , " << zy << " , " << zx+1 <<endl;
			swap(grid[zy1][zx1],grid[zy][zx+1]);
			if(grid[zy1][zx1] == 5) 
				Specialgemdelition(grid,zy1,zx1);
			if(grid[zy1][zx1+1] == 5) 
				Specialgemdelition(grid,zy1,zx1+1);        // swaping at both idx
			if(samecandiescursorcheck(grid,zy1,zx1,flame) || samecandiescursorcheck(grid,zy,zx+1,flame))
			{
				Sleep(100);
				myRect(200 + x - 100,100 + y ,300 + x -100,200 + y ,255,255,255,3);
				scorecounter(score);
			}
			else
			{
				  Beep (100,100);  // beep sound
				//cout <<"\a";
				swap(grid[zy1][zx1],grid[zy][zx+1]);
			}
			a = 0;
		}

		else if (a == 7 && y>=0 )            // if W key is Pressed to swap up
		{
		//	cout << zx <<" , "<< zy <<" , " << zx1 +1 << " , " << zy1 <<endl;
			swap(grid[zy1 -1 ][zx1+1],grid[zy][zx+1]);
			if(grid[zy1-1][zx1+1] == 5) 
				Specialgemdelition(grid,zy1-1,zx1+1);
			if(grid[zy1][zx1+1] == 5) 
				Specialgemdelition(grid,zy1,zx1+1);   // swaping at both idx
			if(samecandiescursorcheck(grid,zy1-1,zx1+1,flame) || samecandiescursorcheck(grid,zy,zx+1,flame))
			{
				Sleep(100);
				myRect(200 + x ,100 + y -100 ,300 + x ,200 + y -100 ,255,255,255,3);
				scorecounter(score);
			}
			else
			{
				  Beep (100,100);
				//cout <<"\a";
				swap(grid[zy1 -1 ][zx1+1],grid[zy][zx+1]);
			}
			
			a=0;
		}
		else if (a == 8 && x <= 600)                   // if D key is Pressed to swap right
		{
			//cout << zx <<" , "<< zy <<" , " << zx1 +1 << " , " << zy1 <<endl;
			swap(grid[zy1][zx1+2],grid[zy][zx+1]);
			if(grid[zy1][zx1+2] == 5) 
				Specialgemdelition(grid,zy1,zx1+2);
			if(grid[zy1][zx1+1] == 5) 
				Specialgemdelition(grid,zy1,zx1+1);          // swaping at both idx
			if(samecandiescursorcheck(grid,zy1,zx1+2,flame) || samecandiescursorcheck(grid,zy,zx+1,flame))
			{
				Sleep(100);
				myRect(200 + x + 100,100 + y ,300 + x +100,200 + y ,255,255,255,3);
				scorecounter(score);
			}
			else
			{
				  Beep (100,100);
				//cout <<"\a";
				swap(grid[zy1][zx1+2],grid[zy][zx+1]);
			}
			a=0;
		}
		else if (a == 9 && y <= 700)                  // if S key is Pressed to swap down
		{
			//cout << zx <<" , "<< zy <<" , " << zx1 +1 << " , " << zy1 <<endl;
			swap(grid[zy1+1 ][zx1+1],grid[zy][zx+1]);
			if(grid[zy1+1][zx1+1] == 5) 
				Specialgemdelition(grid,zy1+1,zx1+1);
			if(grid[zy1][zx1+1] == 5) 
				Specialgemdelition(grid,zy1,zx1+1);    // swaping at both idx
			if(samecandiescursorcheck (grid,zy1+1,zx1+1,flame) || samecandiescursorcheck(grid,zy,zx+1,flame))
			{
				Sleep(100);
				myRect(200 + x ,100 + y + 100 ,300 + x ,200 + y + 100 ,255,255,255,3);
				scorecounter(score);
			}
			else
			{
				  Beep (100,100);
				//cout <<"\a";
				swap(grid[zy1+1][zx1+1],grid[zy][zx+1]);
			}
			a=0;
		}
		for(int i = 7 ; i >=0 ; i--)   // check after swaping any other combination
		{
			for(int j = 7 ; j >=0 ; j--)
			{
				if(samecandiescursorcheck(grid,i,j,flame))
					score = score + 300; // combo score
			}
		}

		//Sleep(200);
		myRect(200 + x,100 + y,300 + x,200 + y,0,240,240,10);   // tracking rect of cursor
		//Sleep(100);
	for(int i = 0 ; i < 8 ; i++)  // shapes printing on the grid
	{
		for(int j = 0 ; j < 8 ; j++)
		{
			int x1 = 100 + j*100 , y1 = 100 + (i+1)*100, x2 = 100 + (j+1)*100 , y2 = 100 + i*100;
			if (grid[i][j] == 0)
			{
				triange(x1 + 30,y1 -30,x2 - 30,y2 +30,240, 200,0);
				triange(x1 + 40,y1 -40,x2 - 40,y2 +40,240, 200,0);
				if(flame == 1)
				{
					triange(x1 + 40,y1 -40,x2 - 40,y2 +40,240,0,0);
				}
			}
			else if (grid[i][j] == 1)
			{
				myEllipse(x1 + 25,y1 -25,x2 - 25,y2 +25,0, 0,240);
				myEllipse(x1 + 39,y1 -39,x2 - 39,y2 +39,0, 0,240);
				if(flame == 1)
				{
					myEllipse(x1 + 39,y1 -39,x2 - 39,y2 +39,240,0, 0);
						flame = 0 ;
				}

			}
			else if (grid[i][j] == 2)
			{
				cross(x1 + 30,y1 -30,x2 - 30,y2 +30,0, 255,0);
					if(flame == 1)
					{
						cross(x1 + 25,y1 -25,x2 - 25,y2 +25, 255,0,0);
						flame = 0 ;
					}
			}
			else if (grid[i][j] == 3)
			{
				duotriangle(x1 + 30,y1 -30,x2 - 30,y2 +30,255,0,0);	
				if(flame == 1)
				{
					duotriangle(x1 + 20,y1 -20,x2 - 20,y2 +20,255,255,0);
						flame = 0 ;
				}
			}
			else if (grid[i][j] == 4)
			{
				myRect(x1 + 30,y1 -30,x2 - 30,y2 +30,200,200,200,10);
				myRect(x1 + 40,y1 -40,x2 - 40,y2 +40,200,200,200,10);
				if(flame == 1)
				{
					myRect(x1 + 20,y1 -20,x2 - 20,y2 +20,200,200,0,10);
						flame = 0 ;
				}
			}
			else if (grid[i][j] == 5)
			{
				Specialgem(x1 + 20,y1 -20,x2 - 20,y2 +20,255,255,255);
			}
		}
	}
			//Sleep(100);
			
			
			myRect(200 + x,100 + y,300 + x,200 + y,255,255,255,10);
			//triange(100,100,200,200,230,230,45);
			
			
			//myLine3(300+time*30,100 ,330+time*30, )
	}while(1);
	system("pause");
	return 0 ;
}
// sir help file
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
void cross(int x1 , int y1 , int x2 , int y2 , int R , int G , int B)
{
	myLine3(x1,y1,x2,y2,R,G,B);
	myLine3(x2,y1,x1,y2,R,G,B);

}
void myLine(int x1, int y1, int x2, int y2,int color) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen =CreatePen(PS_SOLID,2,RGB(color,color,color)); //2 is the width of the pen
    SelectObject(device_context,pen);
	MoveToEx(device_context,x1,y1,NULL);
    LineTo(device_context,x2, y2);
	ReleaseDC(console_handle, device_context);  
	DeleteObject(pen);
	
}
void myLine3(int x1, int y1, int x2, int y2,int R ,int G , int B) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen =CreatePen(PS_SOLID,12,RGB(R,G,B)); //2 is the width of the pen
    SelectObject(device_context,pen);
	MoveToEx(device_context,x1,y1,NULL);
    LineTo(device_context,x2, y2);
	ReleaseDC(console_handle, device_context);  
	DeleteObject(pen);
	
}


// This function checks if any of the 4 cursor keys are pressed. 
// If any cursor key is pressed, then the function returns true, and whichKey identifies which of the 4 cursor keys is pressed.
// whichkey is assigned following values if any cursor key is pressed. 1 for left, 2 for up, 3 for right and 4 for left.
bool isCursorKeyPressed(int& whichKey)   //whichKey passed as reference.... 
{
	char key;
	key = GetAsyncKeyState(37);
	if (key == 1)
	{
		whichKey = 1;		// 1 if left key is pressed 
		return true;
	}
	key = GetAsyncKeyState(38);
	if (key == 1)
	{

		whichKey = 2;		// 2 if up key is pressed
		return true;
	}
	
	key = GetAsyncKeyState(39);
	if (key == 1)
	{

		whichKey = 3; // 3 if right key is pressed
		return true;
	}
	key = GetAsyncKeyState(40);
	if (key == 1)
	{

		whichKey = 4;   // 4 if down key is pressed
		return true;
	}
	key = GetAsyncKeyState(VK_RETURN);
	if (key == 1)
	{
		whichKey = 5;   // 5 if Enter key is pressed
		return true;
	}
	key = GetAsyncKeyState('A');
	if (key == 1)
	{
		whichKey = 6;   // 6 to Swap the the candies left A key is pressed
		return true;
	}
	key = GetAsyncKeyState('W');
	if (key == 1)
	{
		whichKey = 7;   // 7 to Swap the the candies up W key is pressed
		return true;
	}
	key = GetAsyncKeyState('D');
	if (key == 1)
	{
		whichKey = 8;   // 8 to Swap the the candies right D key is pressed
		return true;
	}
	key = GetAsyncKeyState('S');
	if (key == 1)
	{
		whichKey = 9;   // 9 to Swap the the candies Down s key is pressed
		return true;
	}

return false;
}

void myRect(int x1, int y1, int x2, int y2, int R, int G, int B , int w )
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
	HPEN pen =CreatePen(PS_SOLID,w,RGB(R,G,B)); 
    SelectObject(device_context,pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(0,0,0)); //Fill color can also be passed as parameter to the function!!!
	
	SelectObject(device_context,brush);
	
	Rectangle(device_context,x1,y1,x2,y2);
	ReleaseDC(console_handle, device_context); 
	DeleteObject(pen);
	DeleteObject(brush);
}
void myEllipse(int x1, int y1, int x2, int y2, int R, int G, int B)
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
    HPEN pen =CreatePen(PS_SOLID,11,RGB(R,G,B)); 
    SelectObject(device_context,pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(0, 0, 0));  //Fill color is black
	SelectObject(device_context,brush);
	Ellipse(device_context,x1,y1,x2,y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}
// end of sir help file
void triange(int x1 , int y1 , int x2 , int y2 , int R , int G , int B)
{
	int	x3 = (x1 + x2)/2 , y3 = y1 ;
	myLine3(x1, y1, x2, y3 ,R ,G ,B );
    myLine3(x1, y1, x3, y2 ,R ,G ,B );
    myLine3(x2, y3, x3, y2 , R ,G ,B );
}
void duotriangle(int x1 , int y1 , int x2 , int y2 , int R , int G , int B)
{
	triange(x1 , y1-5 , x2 , y2-5 , R , G , B);
	revtriange(x1 , y1+5 , x2 , y2+5 , R , G , B);
}
void background( int i )  // background style
{
	myLine3(20+i*20, 20,20 +i*20 + 10,40,i*2,i*2,150+i);
	myLine3(1900 - i*20  - 10, 60,1900 -i*20,80,0,0,150+i);
	myLine3(20+i*20, 100,20 +i*20 + 10,120,0,150+i,0);
	myLine3(1900 - i*20  - 10,140 , 1900 -i*20 , 160 ,150+i,0,240);
	myLine3(20+i*20, 180,20 +i*20 + 10,200,230,0,150+i);
	myLine3(1900 - i*20  - 10,220 , 1900 -i*20 , 240 ,i,150+i,i);
	myLine3(20+i*20, 260,20 +i*20 + 10,280,230,i*20,240);
	myLine3(1900 - i*20  - 10,300 , 1900 -i*20 , 320 ,230,i*20,240);
	myLine3(20+i*20, 340,20 +i*20 + 10,360,230,239,i*20);
	myLine3(1900 - i*20  - 10,380 , 1900 -i*20 , 400 ,230,i*20,240);
	myLine3(20+i*20, 420,20 +i*20 + 10,440,230,239,i*20);
	myLine3(1900 - i*20  - 10,460 , 1900 -i*20 , 480 ,230,i*20,240);
	myLine3(20+i*20, 500,20 +i*20 + 10,520,230,239,i*20);
	myLine3(1900 - i*20  - 10, 540,1900 -i*20,560,230,i*20,240);
	myLine3(20+i*20, 580,20 +i*20 + 10,600,230,239,i*20);
	myLine3(1900 - i*20  - 10,620 , 1900 -i*20 , 640 ,230,i*20,240);
	myLine3(20+i*20, 660,20 +i*20 + 10,680,230,i*20,240);
	myLine3(1900 - i*20  - 10,700 , 1900 -i*20 , 720 ,230,i*20,240);
	myLine3(20+i*20, 740,20 +i*20 + 10,760,230,i*20,240);
	myLine3(1900 - i*20  - 10,780 , 1900 -i*20 , 800 ,230,i*20,240);
	myLine3(20+i*20, 820,20 +i*20 + 10,840,230,239,i*20);
	myLine3(1900 - i*20  - 10,860 , 1900 -i*20 , 880 ,230,i*20,240);
	myLine3(20+i*20, 900,20 +i*20 + 10,920,200,239,i*20);
	myLine3(1900 - i*20  - 10,940 , 1900 -i*20 , 960 ,230,i*20,240);

}
void board()   // grid of 8 by 8
{
	for(int i = 0 ; i <= 8 ; i++)
		myLine(100,100 + i*100,900,100 + i*100,255);
	for(int j = 0 ; j <=8 ; j++)
		myLine(100 + j*100,100 ,100 + j*100,900,255);
}
void revtriange(int y2 , int x2 , int y1 , int x1 , int R , int G , int B)
{
	int	x3 , y3;
	swap(x1,y1);     
	swap(x2,y2);
	swap(x3,y3);
	x3 = (x1 + x2)/2; 
	y3 = y1 ;
	myLine3( x1 , y1 , x2 , y3 , R , G , B ); 
    myLine3( x1 , y1 , x3 , y2 , R , G , B );
    myLine3( x2 , y3 , x3 , y2 , R , G , B );

}
void scorecounter(int &score)   // score calculator
{
	score = score + 250;
	gotoxy(100, 1);
    cout<<flush;
	gotoxy(100, 1);
    cout<<"Your Score : " << score ;

}
bool samecandiescursorcheck( int arr[][8] , int y , int x ,bool &flame )   //  swaping check 
{
	int plus = 0 ;
	flame = 0;
	if(x > 1 && x < 6)    // out of bound check
		if (arr[y][x] == arr[y][x+1] && arr[y][x+1] == arr[y][x+2])
		{
			if (arr[y][x] == arr[y][x-1] && arr[y][x-1] == arr[y][x-2])
			{
				arr[y][x] = 5 ;
				for(int a = y ; a >= 0 ; a-- )
				{
					swap(arr[a-1][x],arr[a][x]);     // hashir start x to y ;
					swap(arr[a-1][x+1],arr[a][x+1]);
					swap(arr[a-1][x+2],arr[a][x+2]);
					swap(arr[a-1][x],arr[a][x]);
					swap(arr[a-1][x-1],arr[a][x-1]);
					swap(arr[a-1][x-2],arr[a][x-2]);  // deleting rects to prevent overlaping of shapes
					myRect( x*100 + 200   , (a+1)*100 , x*100 +100 , (a+1)*100+100,255,255,255,3);
					myRect( x*100 +100 , (a+1)*100 , x*100  , (a+1)*100+100,255,255,255,3);
					myRect( x*100  , (a+1)*100 , x*100 - 100 , (a+1)*100+100,255,255,255,3);
					//cout << x*100 <<" , " <<a*100 <<" , "<<x*100 + 100 <<a*100;
					myRect( x*100 + 100 , (a+1)*100 , x*100 + 200 , (a+1)*100+100,255,255,255,3);
					myRect( x*100 + 200 , (a+1)*100 , x*100 + 300 , (a+1)*100+100,255,255,255,3);
					myRect( x*100 + 300 , (a+1)*100 , x*100 + 400 , (a+1)*100+100,255,255,255,3);
				}
				arr[0][x+1] = rand()%5;
				arr[0][x+2] = rand()%5;
				arr[0][x] = rand()%5;
				arr[0][x-1] = rand()%5;
				arr[0][x-2] = rand()%5;
			return true;
		}
	}
	if (arr[y][x] == arr[y-1][x] && arr[y-1][x] == arr[y-2][x])
	{
		if (arr[y][x] == arr[y+1][x] && arr[y+1][x] == arr[y+2][x])
		{
			
			for(int b = y ; b >= 0 ; b--  )
			{
				swap(arr[b-4][x],arr[b-1][x]);
				swap(arr[b-5][x],arr[b-2][x]);
				swap(arr[b-3][x],arr[b][x]);
				swap(arr[b-2][x],arr[b+1][x]);
				swap(arr[b-1][x],arr[b+2][x]);   // deleting rects to prevent overlaping of shapes
				myRect( x*100 + 100 , (b+2)*100 , x*100 + 200 , (b+2)*100 + 100,255,255,255,3);
				myRect( x*100 + 100 , (b+1)*100 , x*100 + 200 , (b+1)*100 + 100,255,255,255,3);
				myRect( x*100 + 100 , (b+3)*100 , x*100 + 200 , (b+3)*100 + 100,255,255,255,3);
			}
			myRect( x*100 + 100 , (3)*100 , x*100 + 200 , (3)*100 + 100,255,255,255,3);
			myRect( x*100 + 100 , (2)*100 , x*100 + 200 , (2)*100 + 100,255,255,255,3);
			myRect( x*100 + 100 , (1)*100 , x*100 + 200 , (1)*100 + 100,255,255,255,3);
			arr[0][x] = rand()%5;
			arr[1][x] = rand()%5;
			arr[2][x] = rand()%5;
			arr[3][x] = rand()%5;
			arr[y][x] = 5;
		}
	}

	if(x <=5)    // out of bound check
	{
		if (arr[y][x] == arr[y][x+1] && arr[y][x+1] == arr[y][x+2])
		{
			plus=0;
			if(arr[y][x] == arr[y][x-1])
			{
				flame = 1;
				//cout<<"4right";
				//plus--;
				//myRect( x*(plus)*100 + 50 , (y+1)*100 , x*(plus)*100 + 150 , (y+1)*100+100,255,255,255,3);
			}
			for(int a = y ; a >= 0 ; a-- )
			{
				swap(arr[a-1][x+plus],arr[a][x+plus]);    // index swaping for shapes swap
				swap(arr[a-1][x+1],arr[a][x+1]);
				swap(arr[a-1][x+2],arr[a][x+2]);    // deleting rects to prevent overlaping of shapes
				//cout << x*100 <<" , " <<a*100 <<" , "<<x*100 + 100 <<a*100;
				myRect( x*100 + 100+(plus)*100 , (a+1)*100 , x*100 + 200+(plus)*100 , (a+1)*100+100,255,255,255,3);
				myRect( x*100 + 200 , (a+1)*100 , x*100 + 300 , (a+1)*100+100,255,255,255,3);
				myRect( x*100 + 300 , (a+1)*100 , x*100 + 400 , (a+1)*100+100,255,255,255,3);
			}
			arr[0][x+plus] = rand()%5;
			arr[0][x+1] = rand()%5;
			arr[0][x+2] = rand()%5;
		//	cout << "Right";

			return true;
		}
	}
	if(x > 1)     // out of bound check
	{
		if (arr[y][x] == arr[y][x-1] && arr[y][x-1] == arr[y][x-2])
		{
			plus = 0;
			if (x <=7)
			if (arr[y][x] == arr[y][x+1])
			{
				flame = 1;
			//	cout<<"4left";
				plus++;

			}
			for(int a = y ; a >=0 ; a-- )
			{
				swap(arr[a-1][x],arr[a][x]);      // index swaping for shapes swap
				swap(arr[a-1][x-1],arr[a][x-1]);
				swap(arr[a-1][x-2],arr[a][x-2]);     // deleting rects to prevent overlaping of shapes
				myRect( x*100 + 200  , (a+1)*100 , x*100 +100 , (a+1)*100+100,255,255,255,3);
				myRect( x*100 +100 , (a+1)*100 , x*100  , (a+1)*100+100,255,255,255,3);
				myRect( x*100  , (a+1)*100 , x*100 - 100 , (a+1)*100+100,255,255,255,3);
			}
			arr[0][x] = rand()%5;
			arr[0][x-1] = rand()%5;
			arr[0][x-2] = rand()%5;

		//	cout <<"Left";
			return true;
		}
	}
	if(y > 1)               // out of bound check
	{	
		if (arr[y][x] == arr[y-1][x] && arr[y-1][x] == arr[y-2][x])
		{
			if (arr[y][x] == arr[y+1][x])
			{
				flame = 1;
			//	cout<<"4up";
				plus++;
			}
			for(int b = y ; b >= 0 ; b--  )
			{
				swap(arr[b-3][x],arr[b][x]);    // index swaping for shapes swap
				swap(arr[b-4][x],arr[b-1][x]);
				swap(arr[b-5][x],arr[b-2][x]);           // deleting rects to prevent overlaping of shapes
				myRect( x*100 + 100 , (b+1)*100 , x*100 + 200 , (b+1)*100 + 100,255,255,255,3);
			}
			myRect( x*100 + 100 , (3)*100 , x*100 + 200 , (3)*100 + 100,255,255,255,3);
			myRect( x*100 + 100 , (2)*100 , x*100 + 200 , (2)*100 + 100,255,255,255,3);
			myRect( x*100 + 100 , (1)*100 , x*100 + 200 , (1)*100 + 100,255,255,255,3);
			arr[0][x] = rand()%5;
			arr[1][x] = rand()%5;
			arr[2][x] = rand()%5;
		//	cout << "up";
			return true;
		}
	}
	if(y <=5)         // out of bound check
	{
		if (arr[y][x] == arr[y+1][x] && arr[y+1][x] == arr[y+2][x])
		{
			if (arr[y][x] == arr[y-1][x])
			{
				flame = 1;
			//	cout<<"4down";
				plus--;
			}
			for(int b = y ; b >= 0 ; b--  )
			{
				swap(arr[b-3][x],arr[b][x]);// index swaping for shapes swap
				swap(arr[b-2][x],arr[b+1][x]);
				swap(arr[b-1][x],arr[b+2][x]); // deleting rects to prevent overlaping of shapes
				myRect( x*100 + 100 , (b+2)*100 , x*100 + 200 , (b+2)*100 + 100,255,255,255,3);
				myRect( x*100 + 100 , (b+1)*100 , x*100 + 200 , (b+1)*100 + 100,255,255,255,3);
				myRect( x*100 + 100 , (b+3)*100 , x*100 + 200 , (b+3)*100 + 100,255,255,255,3);
			}
			myRect( x*100 + 100 , (3)*100 , x*100 + 200 , (3)*100 + 100,255,255,255,3);
			myRect( x*100 + 100 , (2)*100 , x*100 + 200 , (2)*100 + 100,255,255,255,3);
			myRect( x*100 + 100 , (1)*100 , x*100 + 200 , (1)*100 + 100,255,255,255,3);
			arr[0][x] = rand()%5;
			arr[1][x] = rand()%5;
			arr[2][x] = rand()%5;
		//	cout << "Down";
			return true;
		}
	}
	if(y > 0 && y <= 6)   // out of bound check
	{
		if(arr[y-1][x]==arr[y][x] && arr[y][x] == arr[y+1][x])
		{
			for(int b = y ; b >=0 ; b-- )
			{
				swap(arr[b-4][x],arr[b-1][x]);// index swaping for shapes swap
				swap(arr[b-3][x],arr[b][x]);
				swap(arr[b-2][x],arr[b+1][x]); // deleting rects to prevent overlaping of shapes
				myRect( x*100 + 100 , (b+2)*100 , x*100 + 200 , (b+2)*100 + 100,255,255,255,3);
				myRect( x*100 + 100 , (b+1)*100 , x*100 + 200 , (b+1)*100 + 100,255,255,255,3);
				//myRect( x*100 + 100 , (b)*100 , x*100 + 200 , (b)*100 + 100,255,255,255);
			}
			myRect( x*100 + 100 , (3)*100 , x*100 + 200 , (3)*100 + 100,255,255,255,3);
			myRect( x*100 + 100 , (2)*100 , x*100 + 200 , (2)*100 + 100,255,255,255,3);
			myRect( x*100 + 100 , (1)*100 , x*100 + 200 , (1)*100 + 100,255,255,255,3);
			arr[0][x] = rand()%5;
			arr[1][x] = rand()%5;
			arr[2][x] = rand()%5;
		//	cout <<"mid up-down";
			return true;
		}
	}
	if(x > 0 && x <= 6)     // out of bound check
	{
		if(arr[y][x-1]==arr[y][x] && arr[y][x] == arr[y][x+1])
		{
			for(int a = y ; a >=0 ; a-- )
			{          
				swap(arr[a-1][x-1],arr[a][x-1]);   // index swaping for shapes swap
				swap(arr[a-1][x],arr[a][x]);
				swap(arr[a-1][x+1],arr[a][x+1]);        // deleting rects to prevent overlaping of shapes
				myRect( x*100   , (a+1)*100 , x*100 + 100 , (a+1)*100+100,255,255,255,3);
				myRect( x*100 + 100 , (a+1)*100 , x*100 + 200  , (a+1)*100+100,255,255,255,3);
				myRect( x*100 +200 , (a+1)*100 , x*100 + 300 , (a+1)*100+100,255,255,255,3);
			}
			arr[0][x-1] = rand()%5;
			arr[0][x] = rand()%5;
			arr[0][x+1] = rand()%5;
		//	cout <<"mid right-left";
			return true;
		}
	}
	return false;
}
void timer() {//to set timer
    auto start = chrono::high_resolution_clock::now();
	int sec=1000;
    for(int i=0;i<=sec;i++)// Loop from 0 to 60
    {
		// Calculate remaining sections
		gotoxy(116,3);
		cout<<(sec-i)<<" ";
		if(sec-i<10)
		{
			cout<<"\b\b";
		}
		else if(sec-i<100)
		{
			cout<<"\b\b\b";
		}
		else
		{
			cout<<"\b\b\b\b";
		}
        
        this_thread::sleep_until(start + (i+1)*chrono::seconds(1));
    }
    exit(0);//when timer ends programme will exit
}
void Specialgem(int x1 , int y1 , int x2 , int y2 ,int R , int G , int B )
{	int x3 = (x1+x2)/2 , y3 = (y1 + y2)/2;
	myRect(x3,y1,x1,y3,255,0,0,9);
	myEllipse(x1,y3,x3,y2,0,0,255);
	myRect(x3,y2,x2,y3,255,0,0,9);
	myEllipse(x2,y3,x3,y1,0,0,255);
	myRect(x1 + 30,y1+30,x2 - 30,y2 -30,R,G,B,9);
}
void Specialgemdelition(int arr[][8] , int y , int x )
{
	system("cls");
	arr[y][x]= rand()%5;
	for(int i = 0 ; i < 8 ; i++)
		arr[y][i] = rand()%5;
	for(int i = 0 ; i < 8 ; i++)
		arr[i][x] = rand()%5;

}
// end of game 
//Asadullah (21L-1762)
//Hashir (21L-7742)
