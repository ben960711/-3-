#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	clock_t start, end;
	int arr[80000] = { 0, }; //원소가 1만개인 배열생성
	long long  i, j, n, temp = 0;

	start = clock();
	n = sizeof(arr) / sizeof(int); // n=40000/4=10000개
	srand(time(NULL)); // 난수 재생 함수.

	for (i = 0; i < n; i++) 
		arr[i] = (rand() % 80000)+1; //1부터 1만까지의 수에서 난수 발생시키고 0번주소부터 9999번 주소까지의 배열에 난수 대입.
	
	

	for (j = n - 1; j >= 0; j--) //가장 뒤부터 
	{
		for (i = 0; i < j; i++) //가장 앞자리의 수를 가장뒤의 수 바로 앞까지 검사.
		{
			if (arr[i] > arr[i + 1]) // 만약 i주소에 있는 수가 i+1주소에 있는 수보다 크다면 
			{
				temp = arr[i + 1]; //temp에 i+1주소에 있는 수를 대입.
				arr[i + 1] = arr[i]; //i+1주소에 있는 수에 i주소에 있는 수를 대입
				arr[i] = temp; // i주소에 있는 수에 다시 temp수를 대입.
			}
		}
	}
	end = clock();
	double sec = (end - start) / CLOCKS_PER_SEC;
	
	printf("\n소요시간은 %fms\n", sec);
	system("pause");
	return sec;
}