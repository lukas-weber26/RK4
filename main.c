#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double t, double y) {
	return sin(t)*sin(t)*y;
}

void RK4 (double * t, double * y,int length, double h, double initial_condition) {
	int count = 0;
	t[count] = 0;
	y[count] = initial_condition;
	count ++;
	double h6 = h/6;
	double h2 = h/2;

	while (count < length) {
		t[count] = t[count-1] + h;
		double k1 = f(t[count-1], y[count-1]);
		double k2 = f(t[count-1] + h2, y[count-1] + h2 * k1);
		double k3 = f(t[count-1] + h2, y[count-1] + h2*k2);
		double k4 = f(t[count-1] + h, y[count-1]+ h*k3);
		y[count] = y[count-1] + h6*(k1 + 2*k2 + 2*k3 + k4);
		count ++;
	}
	
}

int main() {
	int length = 100000000;
	double h = (double)5/(double)(length-1);
	double * t = malloc(sizeof(double) * length);
	double * y = malloc(sizeof(double) * length);
	RK4(t, y, length, h, 0.1);
	
	//FILE * f = fopen("RK4Out", "w");
	//fprintf(f, "X,Y\n");
	//for (int i = 0; i < length; i++) {
	//	fprintf(f, "%f,%f\n", t[i] , y[i]);
	//}
	//fclose(f);
}
