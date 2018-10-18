#include <stdio.h>
#include <math.h>

#define pi 3.14159265

void main() {
	double I = 100.0;//Радиус окружности
	int rotFr = 50;	//Частота вращения точки
	int regFr = 10000;//Частота регистрации
	double fi0 = 15.0;//Начальный угол в градусах цельсия
	fi0 = fi0 / 180.0 * pi;//Перевод в радианы
	int count = regFr / rotFr;//Количество регистраций
	double ax = 1.0, ay = 0.0;//ax,ay где x- и y- координаты единичного вектора направленного по оси A
	double bx = -0.5, by = sqrt(3) / 2;//bx,by где x- и y- координаты единичного вектора направленного по оси B 
	double cx = -0.5, cy = -sqrt(3) / 2;//cx,cy где x- и y- координаты единичного вектора направленного по оси C
	printf("=================================================================================\n");
	for (int i = 0; i < count; i++)
	{
		double fi = 2.0*pi / count * i + fi0; //угол в радианах

		//Координаты вращающегося вектора в осях X,Y
		double Xx = I * cos(fi);
		double Xy = I * sin(fi);

		//Проекции на оси A,B,C
		double SA = Xx * ax + Xy * ay;
		double SB = Xx * bx + Xy * by;
		double SC = Xx * cx + Xy * cy;

		I = sqrt(2.0 / 3.0*(SA*SA + SB * SB + SC * SC)); //Длина вектора



		//================================================

		double sumM = I / cos(pi / 6);
		//S1=SB S2=SC S3=SA	
		
		double MC = (SA - SC / 2) * 3 / 4;//SA-SC/2=3/4*MC => MC=(SA-SC/2)/(3/4)
		double MA = (SC - SA / 2) * 3 / 4;//SC-SA/2=3/4*MA => MA=(SC-SA/2)/(3/4)
		double MB = sumM - MC - MA;//MB+MC+MA=sumM  => MB=sumM-MC-MA


		printf("|\tfi = %f\t|\tSA = %f\t|\t MA = %f  \t|\n", fi * 180 / pi, SA, MA);
		printf("|\tI = %f\t|\tSB = %f\t|\t MB = %f  \t|\n", I, SB, MB);
		printf("|\ti = %i\t\t|\tSC = %f\t|\t MC = %f  \t|\n", i, SC, MC);
		printf("=================================================================================\n");
//		system("pause");
	}


//	system("pause");
end.
