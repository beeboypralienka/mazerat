#include <iostream>
#define ROW 7
#define COL 7
using namespace std;

// Fachrul Pralienka Bani Muhamad (5115201044)

void mazeSekarang ( char maze[ROW][COL] , int a, int b,int x,int y ,int i,int j ); 
void cetakMaze ( const char[ROW][COL] );
bool validMove ( const char [ROW][COL], int, int ); 
bool notStuck ( char maze[ROW][COL],int x,int y, int i,int j );

int main()
{
	char maze[ ROW ][ COL ]={		
		{'.','O','.','.','.','.','.'},
		{'.','.','.','O','.','O','O'},
		{'.','O','.','O','.','.','.'},
		{'.','O','.','O','.','O','O'},
		{'.','O','.','O','.','O','.'},
		{'.','O','.','O','.','.','.'},
		{'.','O','.','O','O','.','.'}
	}; 
	int xStart, yStart, x, y;
	xStart=0;
	yStart=0; 
	x = xStart;  // starting row
	y = yStart;  // starting col
   
   mazeSekarang(maze,xStart,yStart,x,y,-1,-1  );
   return 0;
}

void mazeSekarang(char maze[ROW][COL], int a, int b,int x,int y,int i,int j ){	
	bool c = false; 
	maze[ x ][ y ] = 'x';  // insert X at current location
	cout<<x;
	cout<<y;	
	cout<<(" \n" );
	cetakMaze( maze );
	cout <<endl<<"Tekan enter untuk melihat langkah tikus selanjutnya!";
    cin.get();
	
    if (x== ROW-1 && y== COL-1){   //goal
    		cetakMaze(maze);
			cout <<endl<<"Alhamdulillah.. Tikus berhasil sampai tujuan :D\n\n"; 
			return ;   // maze is complete
	}else {  
			c = true;
			// move right
			if ( validMove( maze, x , y + 1  ) ) { 
				if ( x != i || y + 1 != j ) {
					mazeSekarang( maze, a, b, x , y + 1, x, y );
   					return; 
				}else { 
					if ( notStuck (maze,x,y,i,j)) {
					}else{
						maze[ x ][ y ] = 'F';
						mazeSekarang( maze, a, b, x , y + 1, x, y );
   						return; 
					}
				}									
            }  
			// move down
	 		if ( validMove( maze, x + 1 , y  ) ) { 
	 		 	if ( x + 1 != i || y != j ) {
	 		 		mazeSekarang( maze,a,b, x + 1, y, x , y );
            		return;
				}else { 
					if ( notStuck (maze,x,y,i,j)) {
					}else{
						maze[ x ][ y ] = 'F';
						mazeSekarang( maze , a , b , x + 1, y, x , y );
            			return;
					}
				}				
			}             
			// move up
			if ( validMove( maze, x - 1 , y   )  ) {
     			if ( x-1 != i || y != j ) {
     				mazeSekarang( maze,a,b, x - 1, y, x,y );
            		return;
				}else { 
					if ( notStuck (maze,x,y,i,j)) {
					}else{
						maze[ x ][ y ] = 'F';
						mazeSekarang( maze , a , b , x - 1, y, x,y );
            			return;
					}
				} 
            } 
			// move left
			if ( validMove( maze, x , y-1 ) ) {
            	if ( x != i || y-1 != j ) {
            			mazeSekarang( maze, a , b , x, y - 1,x,y );
						return ;
					}else { 
					if ( notStuck (maze,x,y,i,j)) {
					}else{
						maze[ x ][ y ] = 'F';
						mazeSekarang( maze, a , b , x, y - 1,x,y );
						return ;
					}
				}						
			}										 
    }
}

bool validMove( const char maze[ROW][ COL ], int r, int c ){	
   	return ( r >= 0 && r <= ROW-1 && c >= 0 && c <= COL-1 && maze[ r ][ c ] != 'O' && maze[ r ][ c ] != 'F' );
}

void cetakMaze( const char maze[ROW][ COL ] ) {	
 	system("cls");
   	for ( int x = 0; x < ROW; ++x ) {
      for ( int y = 0; y < ROW; ++y )
         cout << maze[ x ][ y ] << ' ';
      cout << '\n';
   	}   	    
}

bool notStuck(char maze[ROW][COL],int x,int y, int i,int j ){	
	return(	(validMove( maze, x , y + 1  )&&( x != i || y + 1 != j ))  ||
	 (validMove( maze, x + 1 , y )&&( x + 1 != i || y != j ) )|| 
	 (validMove( maze, x - 1 , y )&& ( x-1 != i || y != j ))||
	 (validMove( maze, x , y-1 )&&( x != i || y-1 != j ))) ;
}
