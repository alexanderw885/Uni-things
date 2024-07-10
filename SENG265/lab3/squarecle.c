# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>

int pointgen();

int main() {
	srand(time(NULL));
	const double NUM_POINTS = 1000000;
	double a;
	double b;
	double length;

	//double total = 0;
	double correct = 0;

	for(int i = 0; i < NUM_POINTS; i++){
		a = (double)pointgen()/100;
		b = (double)pointgen()/100;
		//printf("%.2f, %.2f\n", a, b);
		length = sqrt((a*a)+(b*b));
		//printf("%.2f\n", length);
		if(length <= 1){
			correct++;
		}
	}
	printf("%.0f in circle\n", correct);
	printf("%.4f\n", (double)((correct*4.0)/NUM_POINTS));
}
