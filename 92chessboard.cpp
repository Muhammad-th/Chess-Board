
#include <iostream>

using namespace std;

bool ok(int q[], int c) {
	for (int i = 0; i < c; ++i)
    	if (q[i] == q[c] || abs(q[i] - q[c]) == c - i)
        	return false;
  	return true;
}

void print(int q[]) {
	static int solution = 0;
	int i, j, k, l;
	typedef char box[5][7];   
	box bb, wb, *board[8][8];

	for(i=0; i<5; i++)
		for(j=0; j<7; j++)
			{wb[i][j]=' ';
			bb[i][j]=char(219);
		}
	static box bq = { {char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
                     {char(219),' '      ,char(219),' '      ,char(219),' '      ,char(219)},
                     {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                     {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                     {char(219),char(219),char(219),char(219),char(219),char(219),char(219)} };
               
  	static box wq = { {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      },
                     {' '      ,char(219),' '      ,char(219),' '      ,char(219),' '      },
                     {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                     {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                     {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      } };
	
	for(i=0; i<8; i++)
		for(j=0; j<8; j++)
			if((i+j)%2==0)
				board[i][j]=&wb;
			else
				board[i][j]=&bb;
	for(i=0; i<8; i++)
     	if((i+q[i])%2 == 0)
        	board[q[i]][i] = &bq;
     	else
        	board[q[i]][i] = &wq;

  	cout << "Solution #" << ++solution << ":\n ";
				
	for(i=0; i<7*8; i++)
		cout<<'_';
	cout <<endl;

	for(i=0; i<8; i++)
		for(k=0; k<5; k++)
			{cout <<"  " <<char(179);
		for(j=0; j<8; j++)
			for(l=0; l<7; l++)
				cout <<(*board[i][j])[k][1];
		cout <<char(179)<<endl;
		}

	cout<<"  ";
	for(i=0; i<7*8; i++)
		cout <<char(196);
	cout <<endl;
}
	void next(int q[], int c) {
  		if (c == 8)
     		print(q);
  		else for (q[c] = 0; q[c] < 8; ++q[c])
     		if (ok(q, c))
        		next(q, c+1);
}

int main() {
  	int q[8];
  	next(q, 0);
  	return 0;
}