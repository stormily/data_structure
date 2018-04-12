#include <stdio.h>


int distance(char* a, char* b) {
	int sum = 0, i = 0, j = 0;

	while (a[i] != 0 || b[j] != 0) {
		if (a[i] == b[j]) {
			i++;
			j++;
		}
		if (a[i] != b[j]) {
			if (a[i] == b[j + 1]) {
				sum++;
				j++;
			} else if (a[i + 1] == b[j]) {
				sum++;
				i++;
			} else {
				sum++;
				i++;
				j++;
			}
		}
	}

	return sum;
}

int main()
{
	char A[] = "fxpimu";
	char B[] = "xwrs";

	printf("%d\n", distance(A, B));
}