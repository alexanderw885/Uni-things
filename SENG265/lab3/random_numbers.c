# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int main(int argc, char* argv[]) {

	
	srand(time(NULL));
	for (int i = 1; i <= 50; i++) {
		int
		n = rand() % 20 + 1;
		printf("%d\n", n);
	}
}
