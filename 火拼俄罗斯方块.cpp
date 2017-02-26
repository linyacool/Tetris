#include <iostream>
#include <string>
#include <time.h>
#include <graphics.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
class Cshape				//方块类
{
private:
	int headx,heady;				//在底盘中的左上角坐标（行列）     
	int look[4][4];					//形状
	int color;
public:
	Cshape()
	{
		headx=0;
		heady=0;
		look[0][0]=0;
	}

	~Cshape()
	{
	}

	int getheadx()
	{
		return headx;
	}

	int getheady()
	{
		return heady;
	}

	void setheadx(int x)
	{
		headx=x;
	}

	void setheady(int y)
	{
		heady=y;
	}

	Cshape(Cshape& shape)			//拷贝
	{
		headx=shape.headx;
		heady=shape.heady;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				look[i][j]=shape.look[i][j];
		color=shape.color;
	}

	void setshape  (int num)					//7种方块  19个形态
	{
		int i,j;
		for(i=0;i<4;i++)
			for(j=0;j<4;j++) 
				look[i][j]=0;
		if(num==1)
			{
				look[0][0]=1;
				look[1][0]=1;
				look[2][0]=1;
				look[3][0]=1;
				color=RED;
			}
		else if(num==2)
			{
				look[3][0]=1;
				look[3][1]=1;
				look[3][2]=1;
				look[3][3]=1;
				color=RED;
			}
		else if(num==3)
			{
				look[2][1]=1;
				look[2][2]=1;
				look[3][1]=1;
				look[3][2]=1;
				color=BROWN;
			}
		else if(num==4)
			{
				look[2][0]=1;
				look[2][1]=1;
				look[2][2]=1;
				look[1][1]=1;
				color=MAGENTA;
			}
		else if(num==5)
			{
				look[1][1]=1;
				look[2][1]=1;
				look[3][1]=1;
				look[2][2]=1;
				color=MAGENTA;
			}
		else if(num==6)
			{
				look[2][0]=1;
				look[2][1]=1;
				look[2][2]=1;
				look[3][1]=1;
				color=MAGENTA;
			}
		else if(num==7)
			{
				look[2][0]=1;
				look[1][1]=1;
				look[2][1]=1;
				look[3][1]=1;
				color=MAGENTA;
			}
		else if(num==8)
			{
				look[1][1]=1;
				look[2][1]=1;
				look[2][2]=1;
				look[2][3]=1;
				color=YELLOW;
			}
		else if(num==9)
			{
				look[1][1]=1;
				look[2][1]=1;
				look[3][1]=1;
				look[1][2]=1;
				color=YELLOW;
			}
		else if(num==10)
			{
				look[1][0]=1;
				look[1][1]=1;
				look[1][2]=1;
				look[2][2]=1;
				color=YELLOW;
			}
		else if(num==11)
			{
				look[2][1]=1;
				look[2][2]=1;
				look[1][2]=1;
				look[0][2]=1;
				color=YELLOW;
			}
		else if(num==12)
			{
				look[1][2]=1;
				look[2][0]=1;
				look[2][1]=1;
				look[2][2]=1;
				color=CYAN;
			}
		else if(num==13)
			{
				look[1][1]=1;
				look[1][2]=1;
				look[2][2]=1;
				look[3][2]=1;
				color=CYAN;
			}
		else if(num==14)
			{
				look[2][0]=1;
				look[1][0]=1;
				look[1][1]=1;
				look[1][2]=1;
				color=CYAN;
			}
		else if(num==15)
			{
				look[0][1]=1;
				look[1][1]=1;
				look[2][1]=1;
				look[2][2]=1;
				color=CYAN;
			}
		else if(num==16)
			{
				look[1][1]=1;
				look[2][1]=1;
				look[2][2]=1;
				look[3][2]=1;
				color=GREEN;
			}
		else if(num==17)
			{
				look[1][2]=1;
				look[1][1]=1;
				look[2][1]=1;
				look[2][0]=1;
				color=GREEN;
			}
		else if(num==18)
			{
				look[1][2]=1;
				look[2][2]=1;
				look[2][1]=1;
				look[3][1]=1;
				color=RGB(255,192,203);					//粉红
			}
		else if(num==19)
			{
				look[1][1]=1;
				look[1][2]=1;
				look[2][2]=1;
				look[2][3]=1;
				color=RGB(255,192,203);
			}
	}

	int getlook(int i,int j)
	{
		return look[i][j];
	}

	int getcolor()
	{
		return color;
	}

	void setcolor(int c)
	{
		color=c;
	}

	int shapeid()		//判断方块的种类类共7种，分1 2为第一种 3   4567   891011     1213141516  1718 1920
	{
		if(look[0][0]==1)  return 1;
		else if(look[3][0]==1) return 2;
		else if(look[2][1]==1&&look[2][2]==1&&look[3][1]==1&&look[3][2]==1) return 3;
		else if(look[2][0]==1&&look[2][1]==1&&look[2][2]==1&&look[1][1]==1) return 4;
		else if(look[1][1]==1&&look[2][1]==1&&look[3][1]==1&&look[2][2]==1) return 5;
		else if(look[2][0]==1&&look[2][1]==1&&look[2][2]==1&&look[3][1]==1) return 6;
		else if(look[2][0]==1&&look[1][1]==1&&look[2][1]==1&&look[3][1]==1) return 7;
		else if(look[1][1]==1&&look[2][1]==1&&look[2][2]==1&&look[2][3]==1)	return 8;
		else if(look[1][1]==1&&look[2][1]==1&&look[3][1]==1&&look[1][2]==1) return 9;
		else if(look[1][0]==1&&look[1][1]==1&&look[1][2]==1&&look[2][2]==1) return 10;
		else if(look[2][1]==1 && look[2][2]==1 && look[1][2]==1 && look[0][2]==1) return 11;
		else if(look[1][2]==1 && look[2][0]==1 && look[2][1]==1 && look[2][2]==1) return 12;
		else if(look[1][1]==1 && look[1][2]==1 && look[2][2]==1 && look[3][2]==1) return 13;
		else if(look[2][0]==1 && look[1][0]==1 && look[1][1]==1 && look[1][2]==1) return 14;
		else if(look[0][1]==1 && look[1][1]==1 && look[2][1]==1 && look[2][2]==1) return 15;
		else if(look[1][1]==1 && look[2][1]==1 && look[2][2]==1 && look[3][2]==1) return 16;
		else if(look[1][2]==1 && look[1][1]==1 && look[2][1]==1 && look[2][0]==1) return 17;
		else if(look[1][2]==1 && look[2][2]==1 && look[2][1]==1 && look[3][1]==1) return 18;
		else if(look[1][1]==1 && look[1][2]==1 && look[2][2]==1 && look[2][3]==1) return 19;
	}

	void change()						//旋转方块
	{
		int num=shapeid();
		if(num==1)  setshape(2);
		else if(num==2)  setshape(1);
		else if(num==3)  return ;
		else if(num==4||num==5||num==6) setshape(num+1);
		else if(num==7)  setshape(4);
		else if(num==8||num==9||num==10) setshape(num+1);
		else if(num==11) setshape(8);
		else if(num==12||num==13||num==14) setshape(num+1);
		else if(num==15) setshape(12);
		else if(num==16) setshape(17);
		else if(num==17) setshape(16);
		else if(num==18) setshape(19);
		else if(num==19) setshape(18);
	}

};

class Cplace              //底盘类
{
private:
	int base[27][14];					//游戏区域：行4-25，列1-10
	int hx,hy;							//底盘数组左上角在屏幕上的像素坐标（相对于坐标原点）
	int tipx,tipy;						//下一个方块提示栏的左上角像素坐标（相对于坐标原点）
public:
	
	Cplace()
	{
		int i,j;
		for( i=0;i<27;i++)
			for(j=0;j<14;j++)
				base[i][j]=0;
	}

	~Cplace()
	{
	}   

	int gethx()
	{
		return hx;
	}

	void  sethx(int x)
	{
		hx=x;
	}

	int gethy()
	{
		return hy;
	}

	void sethy(int y)
	{
		hy=y;
	}

	void settipx(int x)
	{
		tipx=x;
	}

	void settipy(int y)
	{
		tipy=y;
	}

	int getbase(int i,int j)
	{
		return base[i][j];
	}

	Cplace (Cplace& place)						//拷贝
	{
		int i,j;
		for(i=0;i<25;i++)
			for(j=0;j<14;j++)
				base[i][j]=place.base[i][j];
		hx=place.hx;
		hy=place.hy;
		tipx=place.tipx;
		tipy=place.tipy;
	}

	void startbase()				//初始化游戏底盘 数组全部置0,全部底盘色
	{
		int i,j;
		for(i=0;i<27;i++)
			for(j=0;j<14;j++)
				base[i][j]=0;
		setfillcolor(BLUE);
		for(i=4;i<26;i++)
			for(j=1;j<11;j++)
				bar(hx+j*20,hy+i*20,hx+(j+1)*20-1,hy+(i+1)*20-1);
	}

	void cancelshape(Cshape &shape)						//在屏幕上抹除一个方块,传入底盘数组左上角在屏幕上的像素坐标（相对于坐标原点）
	{
		int i,j,k=shape.getheadx(),l=shape.getheady();
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
					if(shape.getlook(i,j)==1&&(k+i)>3)
					{
						setfillcolor(BLUE);
						bar(hx+(l+j)*20,hy+(k+i)*20,hx+(l+j+1)*20-1,hy+(k+i+1)*20-1);
					}
	}

	void setshape(Cshape &shape)							//在游戏底盘上显示一个方块
	{
		int i,j,k=shape.getheadx(),l=shape.getheady();
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
					if(shape.getlook(i,j)==1&&(k+i)>3)
					{
						setfillcolor(shape.getcolor());
						bar3d(hx+(j+l)*20+2,hy+(k+i)*20+2,hx+(j+l+1)*20-4,hy+(k+i+1)*20-4,3,true);
					}
	}

	void setline(int i,int color,int color2)										//在屏幕上显示第i行（底盘数组的行）,传入底盘颜色,和1的颜色
	{
		int j=1;
		for(j;j<=10;j++)
			if(base[i][j]==1)
			{
				setfillcolor(color2);
				bar3d(hx+j*20+2,hy+i*20+2,hx+(j+1)*20-4,hy+(i+1)*20-4,3,true);
			}
			else if(base[i][j]==0)
			{
				setfillcolor(color);
				bar(hx+j*20,hy+i*20,hx+(j+1)*20-1,hy+(i+1)*20-1);
			}
	}	

	void inshape(Cshape &shape)							//把方块放入底盘中  通过修改1,0,并显示
	{
		int i,j,k=shape.getheadx(),l=shape.getheady();
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
					if(shape.getlook(i,j)==1)
						base[k+i][l+j]=1;
		setshape(shape);
	}

	void movenewshape(Cshape &shape)					//把新的方块移到游戏底盘上方
	{
		for(int i=4;i>0;i--)								
		{
			int yon=0;
			for(int j=0;j<4;j++)
				if(shape.getlook(i,j)==1)
					yon=1;
			if(!yon)
				movedown(shape);
			else break;
		}
	}  

	void outshape (Cshape &shape)						//删除某个在底盘中的方块
	{
		int i,j,k=shape.getheadx(),l=shape.getheady();
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
					if(shape.getlook(i,j)==1)
						base[k+i][l+j]=0;
		cancelshape(shape);
	}

	bool candown (Cshape shape)						//判断能否下移方块
	{
		int x=shape.getheadx(),y=shape.getheady(),i,j;
		for(i=0;i<4;i++)
		{
			for(j=3;shape.getlook(j,i)!=1&&j>0;j--) { }
			if(shape.getlook(j,i)==1)
				if(x+j+1>25||base[x+j+1][y+i]==1)
					return false;
		}
		return true;
	}

	bool canleft (Cshape shape)							//判断能否左移方块
	{
		int x=shape.getheadx(),y=shape.getheady(),i,j;
		for(i=0;i<4;i++)
		{
			for(j=0;shape.getlook(i,j)!=1&&j<3;j++) { }
			if(shape.getlook(i,j)==1)
				if(y+j-1<1||base[x+i][y+j-1]==1)
					return false;
		}
		return true;
	}

	bool canright (Cshape shape)			//判断方块能否右移
	{
		int x=shape.getheadx(),y=shape.getheady(),i,j;
		for(i=0;i<4;i++)
		{
			for(j=3;shape.getlook(i,j)!=1&&j>0;j--) { }
			if(shape.getlook(i,j)==1)
				if(y+j+1>10||base[x+i][y+j+1]==1)
					return false;
		}
		return true;
	}

	bool canchange (Cshape shape)						//判断方块能否变换
	{
		outshape(shape);
		int x=shape.getheadx(),y=shape.getheady(),i,j;
		shape.change();
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				if(shape.getlook(i,j)==1)
					if(x+i>25||y+j<1||y+j>10||base[x+i][y+j]==1)
						return false;
		return true;
	}

	bool candeleline (int i)
	{
		int j;
		for(j=1;j<=10;j++)
			if(base[i][j]==0)
				return false;
		return true;
	}

	void movedown(Cshape &shape)					//方块下移
	{
		if(candown(shape))
		{
			outshape(shape);
			shape.setheadx(shape.getheadx()+1);
			inshape(shape);
		}
	}

	void movedownend(Cshape &shape)					//把方块移动到最下方
	{
		while(candown(shape))
			movedown(shape);
	}

	void moveleft(Cshape &shape)
	{
		if(canleft(shape))
		{
			outshape(shape);
			shape.setheady(shape.getheady()-1);
			inshape(shape);
		}
	}

	void moveright(Cshape &shape)
	{
		if(canright(shape))
		{
			outshape(shape);
			shape.setheady(shape.getheady()+1);
			inshape(shape);
		}
	}

	void shapechange(Cshape &shape)
	{
		if(canchange(shape))
		{
			shape.change();
			inshape(shape);
		}
		inshape(shape);
	}

	void deleteline(int i)					//删除第i行
	{
		if(candeleline(i))
		{
			int j,k;
			for(j=0;i-j>4;j++)
				for(k=1;k<=10;k++)
					base[i-j][k]=base[i-j-1][k];
			for(k=1;k<=10;k++)
					base[i-j][k]=0;
			setfillcolor(BLUE);
			bar(hx+20,hy+i*20+10,hx+220,hy+i*20+13);				//标记被消除的行
			PlaySound("music\\bomb.wav", NULL, SND_FILENAME | SND_ASYNC); 
			Sleep(300);
			for(i;i>3;i--)
				setline(i,BLUE,BLACK);
		}
	}

	Cshape newshape(int i)             //随机生成一个方块		,传入随机数种子
	{
		Cshape shape;
		shape.setheadx(0);
		shape.setheady(4);
		srand(i);
		int id=0;					//方块id
		while(true)					//控制每种方块出现的概率一样				
		{
			id=rand()%19+1;
			if(id==1||id==3||id==4||id==8||id==12||id==16||id==18)
				break;
		}
		shape.setshape(id);
		return shape;
	}

	void setnewshape(Cshape &shape)               //把新方块放入提示栏
	{
		int i,j;
		setfillcolor(BLACK);
		bar(tipx,tipy,tipx+4*20-1,tipy+4*20-1);
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				if(shape.getlook(i,j)==1)
				{
					setfillcolor(shape.getcolor());
					bar3d(tipx+j*20+2,tipy+i*20+2,tipx+(j+1)*20-1-4,tipy+(i+1)*20-4,3,true);
				}
	}

	void newline(int*line)				//随机产生一个新列（1,0数组）双人对战时用于给对手添加压力
	{
		srand(GetTickCount());
		for(int i=0;i<10;i++)
			line[i]=rand()%2;
	}

	bool die()									//判断是否加一行直接挂
	{
		int i,j,yon;
		for(i=4;i<=25;i++)
		{
			yon=0;
			for(j=1;j<=10;j++)
			{
				if(base[i][j]==1) 
				{
					yon+=1;
					break;
				}
			}
			if(yon==0)   return false;
		}
		return true;
	}

	void  downnewline(Cplace & place,int & yon)							//在下方添加一行
	{
		if(die())  yon=gameover(place);						//是否直接挂了
		int line[10];
		newline(line);
		int i=26,j;
		for(j=1;j<=10;j++)
			base[i][j]=line[j-1];						//先把随机行放于最下方一行（不显示在屏幕上，隐藏的第26行）
		for(i=4;i<=25;i++)
			for(j=1;j<=10;j++)
				base[i][j]=base[i+1][j];					//上一行赋值为下一行 
		for(j=1;j<=10;j++)									//再把隐藏的行清0
			base[i][j]=0;
		for(i=25;i>=4;i--)
			setline(i,BLUE,BLACK);											//显示在屏幕上
	}

	void  overnewline(Cplace&place,int & yon)					//从上方添加一行
	{
		if(die())  yon=gameover(place);		//判断是否加一行直接挂
		int line[10];
		newline(line);
		int yon2,i,j;
		for(i=5;i<=25;i++)
			{
				yon2=0;
				for(j=1;j<=10;j++)
					if(base[i][j]==1)  yon2=1;
				if(yon2==1)		break;
			}
		for(j=1;j<=10;j++)
			base[i-1][j]=line[j-1];
		setline(i-1,BLUE,BLACK);
	}

	int endshape(Cshape & pnow,Cshape & pnext,Cplace place,int &yon)							//方块下落到最后，固定为黑色,把新方块加入游戏区域，并且产生新方块显示在提示栏,并且判断有否消除
	{   
		int c=0;																					//c为一共消除了多少行
		int i=4,j;
		for(j=1;j<=10;j++)
			if(base[i][j]==1)   yon=gameover(place);						//判断是否挂了
		pnow.setcolor(BLACK);
		setshape(pnow);
		for(i=4;i<=25;i++)
			if(candeleline(i))
			{
				deleteline(i);
				++c;
				i=3;
			}
		inshape(pnext);
		movenewshape(pnext);
		pnow=pnext;
		pnext=newshape(GetTickCount());
		setnewshape(pnext);
		return c;
	}

	int gameover(Cplace &place)						//结束游戏  并显示logo,传入赢的一方和游戏的start类
	{
		mciSendString("close MUSIC", NULL, 0, NULL);
		PlaySound("music\\end.wav", NULL, SND_FILENAME | SND_ASYNC); 
		int i,j;
		for(i=4;i<=25;i++)
		{
			for(j=1;j<=10;j++)
			{
				base[i][j]=0;
				place.base[i][j]=0;
			}
		}
		for(i=25;i>3;i--)				
		{
			setline(i,RED,YELLOW);
			place.setline(29-i,RED,BLACK);
			Sleep(100);
		}							//第一轮logo
		
		base[5][4]=1;base[5][5]=1;base[6][3]=1;base[6][6]=1;base[7][2]=1;base[7][7]=1;						//在底盘数组上编绘第二次logo图样(输的一方的)
		base[8][6]=1;base[9][6]=1;base[10][4]=1;base[10][5]=1;base[11][3]=1;
		i=12;
		for(j=2;j<=7;j++)
			base[i][j]=1;
		base[14][4]=1;base[14][5]=1;base[15][6]=1;base[16][7]=1;base[17][7]=1;base[18][5]=1;base[18][6]=1;
		base[19][4]=1;base[20][5]=1;base[20][6]=1;base[21][7]=1;base[22][7]=1;base[24][5]=1;base[23][6]=1;base[24][4]=1;
		j=3;
		for(i=14;i<=24;i++)
			base[i][j]=1;
																									//赢的一方的logo
		place.base[6][7]=1;place.base[11][6]=1;place.base[11][8]=1;place.base[12][5]=1;place.base[12][9]=1;
		i=7;
		for(j=4;j<=10;j++)
			place.base[i][j]=1;
		for(i=8;i<=10;i++)
			for(j=6;j<=8;j++)
				place.base[i][j]=1;
		i=13;
		for(j=5;j<=10;j++)
			place.base[i][j]=1;
		i=18;
		for(j=5;j<=9;j++)
			place.base[i][j]=1;
		i=21;
		for(j=6;j<=8;j++)
			place.base[i][j]=1;
		i=24;
		for(j=3;j<=10;j++)
			place.base[i][j]=1;
		place.base[14][4]=1;place.base[15][4]=1;place.base[16][3]=1;place.base[17][3]=1;place.base[18][3]=1;
		place.base[19][2]=1;place.base[19][7]=1;place.base[20][2]=1;place.base[20][7]=1;place.base[21][2]=1;
		place.base[22][1]=1;place.base[22][7]=1;place.base[23][1]=1;place.base[23][7]=1;place.base[24][1]=1;place.base[25][1]=1;
		
		for(i=4;i<=25;i++)							//第二轮logo
			{
				setline(i,RED,YELLOW);
				place.setline(29-i,RED,BLACK);
				Sleep(150);   
			}
		while(true)
			{
				if(kbhit())
					getch();
				else 
					break;
			}
		HWND wnd = GetHWnd();
		if (MessageBox(wnd, _T("游戏结束。\n您想重新来一局吗？"), _T("游戏结束"), MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			return 1;
		}
		exit(0);
	}
}; 

class start                  //游戏实现过程类
{
private:
	Cshape p1now,p1next;
	Cshape p2now,p2next;				//p1 p2当前和下一个方块
	int gametime;						//游戏开始的时间
	int p1oldtime,p2oldtime;			//p1p2上次操作时间,首次默认为游戏开始时间
public:
	start(){}

	~start (){}

	void myouttextxy(int x, int y, LPCTSTR s)
{
	static IMAGE tmp;						// 用来保存被文字覆盖的区域背景
	if (s == NULL)
	{
		putimage(x, y, &tmp);				// 恢复区域
	}
	else
	{
		int w=textwidth(s);					// 获取字符串占用的宽度
		int h=textheight(s);				// 获取字符串占用的高度
		getimage(&tmp, x, y, w, h);				// 保存区域
		outtextxy(x, y, s);							// 文字输出	
	}
}

	void startshow()								//开场画面
{
	PlaySound("music\\Railgun.wav", NULL, SND_FILENAME | SND_ASYNC);
	TCHAR s[] =_T("火拼俄罗斯方块");			// 定义字符串									
	initgraph(1100, 600);					// 创建绘图窗口
	setfillcolor(RED);						//开场小动画
	bar(0,0,1100-1,600-1);
	setfillcolor(BLACK);
	for(int i=0;i<=55;i++)
	{
		bar(550-(i+1)*10,0,550-i*10,600);
		bar(550+i*10,0,550+(i+1)*10,600);
		Sleep(60);
	}
	int w = textwidth(s);		// 获取字符串占用的宽度
	int h = textheight(s);		// 获取字符串占用的高度
	IMAGE tmp;					// 定义临时对象，保存被文字破坏的背景						// 绘制背景
	for(int i = 0; i < 1100; i++)
	{
		setlinecolor( HSLtoRGB((float)i, 1.0, 0.25) );
		line(i, 0, 1100, 1100);
	}
								// 设置文字效果
	setcolor(YELLOW);			// 设置文字颜色为黄色
	setbkmode(TRANSPARENT);		// 设置文字背景为透明色
	
								// 绘制移动的文字
	for(int j = 0; j < 290; j++)
	{
										// 绘制文字
		setfont(70,0,("楷体"));
		myouttextxy(j, 100, s);
		Sleep(20);
										// 擦掉文字
		myouttextxy(j, 100, NULL);
	}
	while(true)							//清除前面的误操作
	{
		if(kbhit())
			getch();
		else 
			break;
	}
	setfont(70,0,("楷体"));
	myouttextxy(290, 100, s);
	setfont(40,0,("宋体"));
	outtextxy(300,350,_T("按任意键进入游戏"));
	_getch();
}

	void endshow()
	{
		TCHAR s[] =_T("退出游戏   再见");
		int w = textwidth(s);		
		int h = textheight(s);		
		IMAGE tmp;
		setcolor(YELLOW);			
		setbkmode(TRANSPARENT);						
		for(int j = 0; j < 290; j++)
		{								
			setfont(70,0,("楷体"));
			myouttextxy(j, 100, s);
			Sleep(20);							
			myouttextxy(j, 100, NULL);
		}
		while(true)							//清除前面的误操作
		{
			if(kbhit())
				getch();
			else 
				break;
		}
		setfont(70,0,("楷体"));
		myouttextxy(290, 100, s);
		outtextxy(300,450,_T("按任意键退出"));
		_getch();
	}

	void ready(Cplace &place1,Cplace & place2)					//初始化
	{
		initgraph(1100, 600);						//创建窗口
		srand((unsigned)time(NULL));

		setfont(14, 0, _T("宋体"));					//操作说明
		outtextxy(20, 330, _T("1p操作说明"));
		outtextxy(20, 350, _T("W：旋转"));
		outtextxy(20, 370, _T("A：左移"));
		outtextxy(20, 390, _T("R：右移"));
		outtextxy(20, 410, _T("S：下移"));
		outtextxy(20, 430, _T("空格：沉底"));
		outtextxy(20, 450, _T("G：投降"));
		outtextxy(500, 30, _T("ESC：退出游戏"));
		outtextxy(640, 330, _T("2p操作说明"));
		outtextxy(640, 350, _T("上：旋转"));
		outtextxy(640, 370, _T("左：左移"));
		outtextxy(640, 390, _T("右：右移"));
		outtextxy(640, 410, _T("下：下移"));
		outtextxy(640, 430, _T("0：沉底"));
		outtextxy(640, 450, _T("5：投降"));
		setorigin(150, 100);							//定义坐标原点

		rectangle(-1,-1,10*20,22*20);		// 绘制游戏区边界
		rectangle(11*20-1,-1,15*20,4*20);
		rectangle(30*20-1,-1,40*20,22*20);
		rectangle(25*20-1,-1,29*20,4*20);
		
		place1.sethx(-20);						//定义玩家游戏区域
		place1.sethy(-80);
		place1.settipx(11*20);
		place1.settipy(0);
		place1.startbase();
		place2.sethx(580);
		place2.sethy(-80);
		place2.settipx(25*20);
		place2.settipy(0);
		place2.startbase();

		p1now=place1.newshape(GetTickCount());					//产生初始的方块
		p1next=place1.newshape(GetTickCount()+1);
		p2now=place2.newshape(GetTickCount()+2);
		p2next=place2.newshape(GetTickCount()+3);
		gametime=GetTickCount();					//记录游戏开始的时间
		p1oldtime=gametime;
		p1oldtime=gametime;							//p1p2第一次操作时间设置为系统时间
	}

	void esc ()							 //退出游戏时的动画(简陋版)
	{
		mciSendString("close MUSIC", NULL, 0, NULL);
		PlaySound("music\\jieshu.wav", NULL, SND_FILENAME | SND_ASYNC); 
		setorigin(0,0);
		int i,j;
		setfillcolor(RED);
		for(i=0;i<=15;i++)
		{
			bar(0+i*40,0,0+(i+1)*40,600);
			bar(1100-i*40,0,1100-(i+1)*40,600);
			Sleep(150);
		}	
		endshow();
	}	

	int getcmd()						//接收操作指令
	{		
		while(true)
		{
			int newtime=GetTickCount();
			if(newtime-p1oldtime>=500){p1oldtime=newtime;return 11;}			//1p超时，11:1p下落一格
			if(newtime-p2oldtime>=500){p2oldtime=newtime;return 21;}			//2p超时，21:2p下落一格
			if(kbhit())															//如果有指令
			{
				switch(getch())
				{
				case'w':
				case'W':		return 12;									//12:1p变换方块
				case'a':
				case'A':		return 13;									//13:1p方块左移
				case's':
				case'S':		return 11;
				case'd':
				case'D':        return 14;									//14:2p方块右移
				case'g':
				case'G':		return 10;									//1p投降
				case 27:         return 0;									//退出游戏
				case' ':         return 15;									//1p沉底
				case 72:		return 22;									//2p操作指令
				case 75:		return 23;
				case 77:		return 24;
				case 80:		return 21;
				case'0':        return 25;
				case '5':		return 20;
				}
			}
			Sleep(15);
		}
	}

	void cmd(Cplace &p1,Cplace &p2,int i)					//处理操作指令,i为操作指令
	{
		switch (i)
		{
		case 0: 
			{
				esc();
				exit(0);
			}
		case 10: 
			{
				int yon=p1.gameover(p2);
				if(yon==1)
					go();
			}
		case 20:
			{
				int yon=p2.gameover(p1);
				if(yon==1)
					go();
			}
		//1p操作：
		case 11:
			{
				int yon=0;
				if(!p1.candown(p1now))
				{
					int c=p1.endshape(p1now,p1next,p2,yon);
					if(yon==1)
						go();
					if(c==1)								//根据一次性消掉多少行给对手惩罚
						p2.movedownend(p2now);
					if(c==2)
						{
							p2.movedownend(p2now);
							p2.downnewline(p1,yon);
							if(yon==1)
								go();
						}
					if(c==3)
					{
						p2.movedownend(p2now);
						p2.overnewline(p1,yon);
						if(yon==1)
							go();
					}
					if(c==4)
					{
						p2.movedownend(p2now);
						p2.downnewline(p1,yon);
						if(yon==1)
							go();
						p2.overnewline(p1,yon);
						if(yon==1)
							go();
					}
				}
				else 
					p1.movedown(p1now);
				break;
			}
		case 12: p1.shapechange(p1now);		break;
		case 13: p1.moveleft(p1now);		break;
		case 14: p1.moveright(p1now);		break;
		case 15: 
			{
				int yon=0;
				p1.movedownend(p1now);
				int c=p1.endshape(p1now,p1next,p2,yon);
				if(yon==1)
					go();
				if(c==1)								//根据一次性消掉多少行给对手惩罚
					p2.movedownend(p2now);
				if(c==2)
				{
					p2.movedownend(p2now);
					p2.downnewline(p1,yon);
					if(yon==1)
						go();
				}
				if(c==3)
				{
					p2.movedownend(p2now);
					p2.overnewline(p1,yon);
					if(yon==1)
						go();
				}
				if(c==4)
				{
					p2.movedownend(p2now);
					p2.downnewline(p1,yon);
					if(yon==1)
						go();
					p2.overnewline(p1,yon);
					if(yon==1)
						go();
				}
				break;
			}
		//2p操作:
		case 21:
			{
				if(!p2.candown(p2now))
				{
					int yon=0;
					int c=p2.endshape(p2now,p2next,p1,yon);
					if(yon==1)
						go();
					if(c==1)								//根据一次性消掉多少行给对手惩罚
						p1.movedownend(p1now);
					if(c==2)
						{
							p1.movedownend(p1now);
							p1.downnewline(p2,yon);
							if(yon==1)
								go();
						}
					if(c==3)
					{
						p1.movedownend(p1now);
						p1.overnewline(p2,yon);
						if(yon==1)
							go();
					}
					if(c==4)
					{
						p1.movedownend(p1now);
						p1.downnewline(p2,yon);
						if(yon==1)
							go();
						p1.overnewline(p2,yon);
						if(yon==1)
							go();
					}
				}
				else 
					p2.movedown(p2now);
				break;
			}
		case 22: p2.shapechange(p2now);		 break;
		case 23: p2.moveleft(p2now);		break;
		case 24: p2.moveright(p2now);		break;
		case 25: 
			{
				int yon=0;
				p2.movedownend(p2now);
				int c=p2.endshape(p2now,p2next,p1,yon);
				if(yon==1)
					go();
				if(c==1)								//根据一次性消掉多少行给对手惩罚
					p1.movedownend(p1now);
				if(c==2)
					{
						p1.movedownend(p1now);
						p1.downnewline(p2,yon);
						if(yon==1)
							go();
					}
				if(c==3)
				{
					p1.movedownend(p2now);
					p1.overnewline(p2,yon);
					if(yon==1)
						go();
				}
				if(c==4)
				{
					p1.movedownend(p1now);
					p1.downnewline(p2,yon);
					if(yon==1)
						go();
					p1.overnewline(p2,yon);
					if(yon==1)
						go();   
				}
				break;
			}
		}
	}

	void go()							//开始游戏
	{
		char buf[255];
        mciSendString(("open music\\1.mp3 alias MUSIC"),buf,sizeof(buf),0);
        mciSendString("play MUSIC repeat",NULL,0,0); 
		PlaySound("music\\2.wav", NULL, SND_FILENAME | SND_ASYNC); 
		Cplace p1,p2;			//创建玩家12
		ready(p1,p2);    		//初始化
		p1.inshape(p1now);
		p1.movenewshape(p1now);
		p1.setnewshape(p1next);
		p2.inshape(p2now);
		p2.movenewshape(p2now);
		p2.setnewshape(p2next);
		while(true)
			cmd(p1,p2,getcmd());
	}				
};

void main()
{
	start play;
	play.startshow();
	play.go();
}
