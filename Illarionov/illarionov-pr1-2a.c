
#include <stdio.h>
#include <math.h>
//#include "pch.h"
#include <iostream>

#define pi 3.14159265

// в программе gnuplot можно построить график с помощью команды:
// plot "vector.dat" using 1:2 with lines, "vector.dat" using 1:3 with lines
// 

int main() {
	// вспомогательные переменные 
	int i = 0;
	int count = 140; // количество точек на окружности
	int fate = 0;

	double Xx, Xy; // x- и y- координаты вращающегося вектора Х
	double fi; // угол
	double fig;// угол в градусах
	double fi0 = 0.4363323129986;// начальный угол в 25 градусов
	double Za; // проекция вектора X на ось А
	double Zb; // проекция вектора Х на ось B
	double Zc; // проекция вектора Х на ось C
	double m1, m2, m3;
	// ax,ay — x- и y- координаты единичного вектора направленного по оси A
	double ax = 1.0;
	double ay = 0.0;
	// bx,by — x- и y- координаты единичного вектора направленного по оси B 
	double bx = -0.5;
	double by = sqrt(3) / 2;
	// cx,cy — x- и y- координаты единичного вектора направленного по оси C 
	double cx = -0.5;
	double cy = -sqrt(3) / 2;
	// длина вектора X 
	double XX = 100.0;
	double modV; //модуль вектора
	double checksum; // проверка пр2

	printf("Illarionov 5871 \nPractice 1 \n");

	for (fate = 0; fate < count * 2;)
	{

		fi = fi0 + 2.0*pi / count * i; // угол
		fig = fi * (180 / pi);
		if (fig >= 360)
		{
			fi = fi - 2 * pi;
			fig = fig - 360;
		}
		Xx = XX * cos(fi); // координаты вращающегося вектора в осях X,Y
		Xy = XX * sin(fi);

		Za = Xx * ax + Xy * ay; // проекции на оси A,B,C
		Zb = Xx * bx + Xy * by;
		Zc = Xx * cx + Xy * cy;

		XX = sqrt(2.0 / 3.0*(Za*Za + Zb * Zb + Zc * Zc)); // длина вектора

		m2 = (4.0 / 3.0)*(Za - (Zb / 2.0));
		m3 = (4.0 / 3.0)*(Zb - (Za / 2.0));
		m1 = 1 - m2 - m3;

		modV = sqrt(Xx*Xx + Xy * Xy);

		checksum = modV * (m1 * 0 + m2 * sqrt(ax*ax + ay * ay) + m3 * sqrt(cx*cx + cy * cy));

		if (i < count, fate < count)
		{
			printf("\nstep %3i: Grad %#g\t Rad %f\t Za %f\t Zb %f\t Zc %f\t XX %f\t", i, fig, fi, Za, Zb, Zc, XX);
			 printf("\n\n  CHECKSUM=%f\t\n ",checksum);  // проверка векторной суммы.
		}
		else if (fate == count)
		{
			printf("\nPractice 2 \n");
			printf("step %2i: m1 %f\t m2 %f\t m3 %f\t\n", fate - count, m1, m2, m3);
		}
		else if (fate > count)
		{
			printf("step %2i: m1 %f\t m2 %f\t m3 %f\t %f\t \n", fate - count, m1, m2, m3, m1+m2+m3);
		}
		i++;
		fate++;

	}
}
