//C++ MINI PORJECT
#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<graphics.h>
#include<alloc.h>
#include<fstream.h>
#include<string.h>
char name[20];
char name1[20];
char name2[20];
int i;

void pro();
void us(char b4[25]);

char s[10]={'0','1','2','3','4','5','6','7','8','9'};

class play_board
{
	public:
	void instructions();
	void about();
	int  exit1();
	void getname();
	void winname(char a[10]);
 void showwin();
	void menu();
	 void back()
	  {
			int c;
			cout<<"\n For returning to menu press 1";
			cin>>c;
			if(c==1)
			{
			   menu();
			}
			else
			{
				back();
			}
	 }

};
void play_board::getname()
{
	clrscr();
	cleardevice();
	cout<<"\nEnter the player 1 name";
	cin>>name1;
	cout<<"\nenter the player 2 name";
	cin>>name2;
}


void play_board::winname(char a[15])
{
	ofstream ofs;
	ofs.open("TCT_WINNERS.txt",ios::trunc);

	ofs<<a;
	ofs.close();
}

void play_board::showwin()
{
	fstream ifs;

	char line[80];
	ifs.open("TCT_WINNERS.txt",ios::in);
	cout<<"***WINNER***\n";
	char ch;
	while(ifs)
	{
		ifs.get(ch);
		cout<<ch;
	}
	cout<<"press 1 for menu";
	int pp;
	cin>>pp;
	if(pp==1)
	{ menu();   }

	else
	ifs.close();
}
void play_board :: instructions()
{
	cout<<"\n    		HOW TO PLAY..";
	cout<<"\n 1. The game is played on grid that's 3 squares by 3 squares.";
	cout<<"\n 2. Player one is X ,Player two is O.\n players take turns putting their makes in empty squares";
	cout<<"\n 3. The first player to get of her marks in a row\n\t(up,down,accross or diagonally) is the winner!!!";
	cout<<"\n 4. When all 9 squares are full,the game is over.\n\tIf no player has 3 marks in a row ,the game ends with draw";
}

class logic : public play_board        //inheritance
{
	public:
	logic()
	{

		s[0]='0';
		s[1]='1';
		s[2]='2';
		s[3]='3';
		s[4]='4';
		s[5]='5';
		s[6]='6';
		s[7]='7';
		s[8]='8';
		s[9]='9';
	}

	void disp_board();
	void  game();
	int checkwin();
};

void logic :: game()
{
	int player=1,choice;

	char mark;
	do
	{
	   disp_board();
	   player=(player%2)?1:2;

	   cout<<"PLAYER "<<player<<" , choose the box\t";
	   cin>>choice;

	   mark=(player==1)?'X':'O';

	   if(choice==1 && s[1]=='1')
	   {
		s[1]=mark;
	   }
	  else if(choice==2 && s[2]=='2')
	   {
		s[2]=mark;
	   }
	  else if(choice==3 && s[3]=='3')
	   {
		s[3]=mark;
	   }
	   else if(choice==4 && s[4]=='4')
	   {
		s[4]=mark;
	   }
	   else if(choice==5 && s[5]=='5')
	   {
		s[5]=mark;
	   }
	   else if(choice==6 && s[6]=='6')
	   {
		s[6]=mark;
	   }
	   else if(choice==7 && s[7]=='7')
	   {
		s[7]=mark;
	   }
	   else if(choice==8 && s[8]=='8')
	   {
		s[8]=mark;
	   }
	   else if(choice==9 && s[9]=='9')
	   {
		s[9]=mark;
	   }
	   else
	   {
		cout<<"\n Invalid move";

		player--;
		cin.ignore();
		cin.get();
	   }

	   i=checkwin();

	   player++;
	 }while(i==-1);

	 disp_board();
	 if(i==1)
	 {
	       cout<<"==>\a Player"<<--player<<"  WIN";
	       delay(1000);
	       cleardevice();
	       if(player==1)
	       {
		      //	name=name1;
			play_board p1;
			p1.winname(name1);
		      //	outtextxy(250,300,"Player 1");
		      char b1[24]="CONGRATULATIONS \0";
		      strcat(b1,name1);
			us(b1);
	       }
	       else
	       {
			play_board p2;
			p2.winname(name2);
		    //	outtextxy(250,300,"Player 2");
		      char b2[24]="CONGRATULATIONS \0";
		      strcat(b2,name2);
			us(b2);
	       }
	       menu();
	  //     cout<<"\n loading....";
	      // delay(5000)
	 }
	 else
	 {
		cout<<"==>\a Game Draw";
		delay(500);
	     //	cout<<"\n loading....";
	       //	delay(5000);
		menu();
	 }
	 cin.ignore();  //ignores characters
	 cin.get();
   //	return 0;

}
void us(char buf[25])
{
//     "CONGRATULATIONS";
       int grd, grm;
      int  xmax, ymax,color,j;
      int bgcolor;

      detectgraph(&grd,&grm);
      initgraph(&grd, &grm,"C:\TC\BGI");

      bgcolor=9;
      setbkcolor(LIGHTBLUE);

      xmax = getmaxx();
      ymax = getmaxy();

      setcolor(WHITE);
      rectangle(0,0,xmax,ymax);

      settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
      color = GREEN;

      for(j = 0; j <= 10; j++)
      {
	    if( (j % 2) == 0)
	    {
		  setcolor(color++);
		  outtextxy(5,100,buf);
		  delay(400);
		  if(color > WHITE)
			color = GREEN;
	    }
	    else
	    {
		  setcolor(bgcolor);
		  outtextxy(5,100,buf);
		  delay(400);
	    }
      }
//      getch();
}
void pro()
{
	void *buffer;
	unsigned int size;
	cleardevice();
	setbkcolor(LIGHTBLUE);
	 setcolor(RED);

	//us();
	line(230,330,370,330);
	line(230,350,370,350);
	line(226,335,226,345);
	line(226,335,230,330);
	line(226,345,230,350);
	line(374,335,374,345);
	line(374,335,370,330);
	line(374,345,370,350);
	settextstyle(7,0,6);
	outtextxy(100,150,"TIC - TAC - TOE");

	settextstyle(6,0,2);
	outtextxy(275,365,"LOADING");
	int x=232,y=336;
	int x1=236,y1=344;
	for(int i=1;i<5;i++)
	{
		setfillstyle(1,BLUE);
		bar(x,y,x1,y1);
		x=x1+2;
		x=x1+6;
	}
	size=imagesize(232,336,256,344);
	buffer=malloc(size);
	getimage(232,336,256,344,buffer);
	x=232;
	int m=0;
	while(!kbhit())
	{
		putimage(x,336,buffer,XOR_PUT);
		x=x+2;
		if(x>=350)
		{
			m++;
			x=232;
			if(m==5)
			return;
		}
		putimage(x,336,buffer,XOR_PUT);
		delay(15);
	}

}



int logic :: checkwin()
{
	if(s[1]==s[2] && s[2]==s[3])
	{
		return 1;
	}
	else if(s[4]==s[5] && s[5]==s[6])
	{
		return 1;
	}
	else if(s[7]==s[8] && s[8]==s[9])
	{
		return 1;
	}
	else if(s[1]==s[4] && s[4]==s[7])
	{
		return 1;
	}
	else if(s[2]==s[5] && s[5]==s[8])
	{
		return 1;
	}
	else if(s[3]==s[6] && s[6]==s[9])
	{
		return 1;
	}
	else if(s[1]==s[5] && s[5]==s[9])
	{
		return 1;
	}
	else if(s[3]==s[5] && s[5]==s[7])
	{
		return 1;
	}
	else if(s[1]!='1' && s[2]!='2' && s[3]!='3' && s[4]!='4' && s[5]!='5'
	       && s[6]!='6' && s[7]!='7' && s[8]!='8' && s[9]!='9')
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

void logic :: disp_board()
{
	clrscr();
	cleardevice();
	setbkcolor(LIGHTBLUE);

	cout<<"\n\n\t		    ***** TIC - TAC - TOE*****    	  \n\n" ;

	cout<<"\nPlayer 1 = (X)";
	cout<<"\nPlayer 2 = (O)";
	cout<<endl<<endl;

	cout<<"			     |     |        "<<endl;
	cout<<"  		        "<<s[1]<<"    |  "<<s[2]<<"  |  "<<s[3]<<endl;

	cout<<"		      _______|_____|_______"<<endl;
	cout<<"			     |     |       "<<endl;

	cout<<"			     |     |        "<<endl;
	cout<<"  		        "<<s[4]<<"    |  "<<s[5]<<"  |  "<<s[6]<<endl;

	cout<<"		      _______|_____|_______"<<endl;
	cout<<"			     |     |       "<<endl;

	cout<<"			     |     |        "<<endl;
	cout<<"  		        "<<s[7]<<"    |  "<<s[8]<<"  |  "<<s[9]<<endl;

	cout<<"			     |     |        "<<endl<<endl;
}
void play_board :: about()
{
	cout<<"		       _____CREDITDS____	";
	cout<<"\n\n\t Project Made By : ";
	cout<<"\n\n            Pratik Korde.        56";

}
int play_board :: exit1()
{
	char ans;
	cout<<"\n\n\t Sure!!! \n You Want QUIT??? ";
	cin>>ans;
	if(ans=='y'|| ans=='Y')
	{
		exit(0);
	}
	else
	{
		menu();
	}
	return 0;
}

void play_board :: menu()
{
	clrscr();
	cleardevice();
	int ch;

      //	play_board p;
       //	setbkcolor(WHITE);
       setcolor(BLUE);
       setcolor(0);
	cout<<"\n			******MENU******     "<<endl<<endl;
	cout<<"\n 1.Game \n 2.CREDITS \n 3.HELP \n 4.Last WINNER \n 5.EXIT";

	cout<<"\n SELECT ";
	cin>>ch;
	switch(ch)
	{
		case 1:
		     cout<<" \nGAME";
		     play_board p3;
		     p3.getname();

		     logic l;
		     l.game();
		 //    exit1();
		     break;
		case 2:
		     cout<<"\n CREDITS";
		     about();
		     back();
		     break;
		case 3:
		     cout<<"\n HELP";
		     instructions();
		     back();
		     break;

		case 4:
			play_board p;
			p.showwin();
			back();
			break;

		case 5:
		     cout<<"\nEXIT";
		     exit1();
		     break;
	   }

}


void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\BGI");
	setbkcolor(9);
	setcolor(RED);
	pro();
	logic p;
	p.menu();
	getch();
	closegraph();
}