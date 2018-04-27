# include "iGraphics.h"
# include <GLAux.h>
# include <time.h>
# include<stdlib.h>

FILE *fp;
int pad=0,c,color=0,size=0,pic,save=0,p;
int ar[600][700];
void arrays(void)
{
	int i,j;
	for(i=0; i<599; i++){
		for(j=0; j<699; j++){
			ar[i][j]=0;
		}
	}
}
void time()
{
}
void mydelay(int mseconds)
{
	clock_t start, end;
	double elapsed;
	start = clock();
	while(1)
	{
		end = clock();
		elapsed = ((double) (end - start)) / ((double)CLOCKS_PER_SEC/1000.0);
		if(elapsed>mseconds)break;
	}
}
void iDraw()
{
	int r,q,rad,n;
	if(pad==0)iShowBMP(0,0,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\drawing pad\\front.bmp");
	if(pad==1){
		iSetcolor(10,10,10);
		iFilledRectangle(0,0,900,700);

		if(pic==0)iShowBMP(0,0,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\drawing pad\\pic0.bmp");
		else if(pic==1)iShowBMP(0,0,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\drawing pad\\pic1.bmp");
		else if(pic==2)iShowBMP(0,0,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\drawing pad\\pic2.bmp");
		else if(pic==3)iShowBMP(0,0,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\drawing pad\\pic3.bmp");
		else if(pic==4)iShowBMP(0,0,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\drawing pad\\pic4.bmp");

		if(size==0)iShowBMP(700,600,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\drawing pad\\brushsize.bmp");
		else if(size==1)iShowBMP(700,600,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\drawing pad\\big.bmp");
		else if(size==2)iShowBMP(700,600,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\drawing pad\\med.bmp");
		else if(size==3)iShowBMP(700,600,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\drawing pad\\small.bmp");

		if(color==0)iShowBMP(700,0,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\drawing pad\\color.bmp");
		else if(color==1)iShowBMP(700,0,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\drawing pad\\black.bmp");
		else if(color==2)iShowBMP(700,0,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\drawing pad\\red.bmp");
		else if(color==3)iShowBMP(700,0,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\drawing pad\\blue.bmp");
		else if(color==4)iShowBMP(700,0,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\drawing pad\\pink.bmp");
		else if(color==5)iShowBMP(700,0,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\drawing pad\\white.bmp");
		else if(color==6)iShowBMP(700,0,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\drawing pad\\green.bmp");
		else if(color==7)iShowBMP(700,0,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\drawing pad\\yellow.bmp");
		else if(color==8)iShowBMP(700,0,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\drawing pad\\ash.bmp");

		iShowBMP(750,200,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\drawing pad\\arrow.bmp");
		iShowBMP(850,600,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\drawing pad\\cross.bmp");
		iSetcolor(0,0,0);
		iFilledRectangle(600,0,5,700);

		for(r=0; r<599; r++){
			for(q=0; q<699; q++){
				n=ar[r][q];
				if(n!=0){
					if(n%3 == 1)rad=20;
					else if(n%3 == 2)rad=13;
					else if(n%3 == 0)rad=5;

					if(n>=1 && n<=3)iSetcolor(0,0,0);
					else if(n>=4 && n<=6)iSetcolor(50,0,0);
					else if(n>=7 && n<=9)iSetcolor(0,0,50);
					else if(n>=10 && n<=12)iSetcolor(50,0,50);
					else if(n>=13 && n<=15)iSetcolor(50,50,50);
					else if(n>=16 && n<=18)iSetcolor(0,50,0);
					else if(n>=19 && n<=21)iSetcolor(50,50,0);
					else if(n>=22 && n<=24)iSetcolor(0,50,50);

					iFilledCircle(r,q,rad,100);
				}
			}
		}

		if(save==1)iShowBMP(300,300,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\drawing pad\\save.bmp");
	}
}

void iMouse(int button, int state, int mx, int my)
{
	int dec=0,i,j;
	if((fp = fopen("decision","r"))!=NULL){
		dec = getw(fp);
		fclose(fp);
	}
	//else dec=0;
	if(pad==0 && mx>300 && mx<500 && my>150 && my<200){
		if(dec==0){
			pic=0;
			arrays();
		}
		else if(dec==1){
			if((fp = fopen("savep", "r"))!=NULL){
				pic = getw(fp);
				fclose(fp);
			}
			if((fp = fopen("savea", "r"))!=NULL){

				for(i=0; i<599; i++){
					for(j=0; j<699; j++){
						ar[i][j]=getw(fp);
						if(feof(fp)) break;
					}
				}
				fclose(fp);
			}
		}
		pad=1;
	}
	if(pad==1){
		if(mx>750 && mx<900 && my>300 && my<400){
			pic = rand() %5;
			arrays();
		}
		if(mx>850 && mx<900 && my>650 && my<700)save=1;
		if(mx>300 && mx<450 && my>300 && my<400 && save==1){
			if((fp = fopen("decision", "w"))!=NULL){
				putw(1,fp);
				fclose(fp);
			}
			if((fp = fopen("savep", "w"))!=NULL){
				putw(pic, fp);
				fclose(fp);
			}
			if((fp = fopen("savea", "w"))!=NULL){
				for(i=0; i<599; i++){
					for(j=0; j<699; j++){
						putw(ar[i][j],fp);
					}
				}
				fclose(fp);
			}
			exit(0);
		}
		if(mx<600 && mx>450 && my>300 && my<400 && save==1)exit(0);

		if(mx<750 && mx>700 && my>650 && my<700){
			size=1;
			p=1;
		}
		if(mx>750 && mx<800 && my>650 && my<700){
			size=2;
			p=2;
		}
		if(mx<850 && mx>800 && my>650 && my<700){
			size=3;
			p=3;
		}
		if(mx<750 && mx>700 && my>0 && my<50){
			color=1;
			c = 0+p;
		}
		if(mx>750 && mx<800 && my>0 && my<50){
			color=2;
			c = 3+p;
		}

		if(mx<850 && mx>800 && my>0 && my<50){
			color=3;
			c = 6+p;
		}
		if(mx>850 && mx<900 && my>0 && my<50){
			color=4;
			c = 9+p;
		}
		if(mx<750 && mx>700 && my>50 && my<100){
			color=5;
			c = 12+p;
		}
		if(mx>750 && mx<800 && my>50 && my<100){
			color=6;
			c = 15+p;
		}

		if(mx<850 && mx>800 && my>50 && my<100){
			color=7;
			c = 18+p;
		}
		if(mx>850 && mx<900 && my>50 && my<100){
			color=8;
			c = 21+p;
		}

	}
}

void iMouseMove(int mx, int my)
{
	if(mx<599 && my<699){
		ar[mx][my]=c;
	}
}



void iPassiveMouseMove(int mx,int my)
{


}

void iKeyboard(unsigned char key)
{


}

void iSpecialKeyboard(unsigned char key)
{


}

int main()
{
	iSettimer(1000, time);
	iInitialize(900, 700, "drawing pad");
	return 0;
}
