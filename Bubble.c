#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	clock_t start, end;
	int arr[80000] = { 0, }; //���Ұ� 1������ �迭����
	long long  i, j, n, temp = 0;

	start = clock();
	n = sizeof(arr) / sizeof(int); // n=40000/4=10000��
	srand(time(NULL)); // ���� ��� �Լ�.

	for (i = 0; i < n; i++) 
		arr[i] = (rand() % 80000)+1; //1���� 1�������� ������ ���� �߻���Ű�� 0���ּҺ��� 9999�� �ּұ����� �迭�� ���� ����.
	
	

	for (j = n - 1; j >= 0; j--) //���� �ں��� 
	{
		for (i = 0; i < j; i++) //���� ���ڸ��� ���� ������� �� �ٷ� �ձ��� �˻�.
		{
			if (arr[i] > arr[i + 1]) // ���� i�ּҿ� �ִ� ���� i+1�ּҿ� �ִ� ������ ũ�ٸ� 
			{
				temp = arr[i + 1]; //temp�� i+1�ּҿ� �ִ� ���� ����.
				arr[i + 1] = arr[i]; //i+1�ּҿ� �ִ� ���� i�ּҿ� �ִ� ���� ����
				arr[i] = temp; // i�ּҿ� �ִ� ���� �ٽ� temp���� ����.
			}
		}
	}
	end = clock();
	double sec = (end - start) / CLOCKS_PER_SEC;
	
	printf("\n�ҿ�ð��� %fms\n", sec);
	system("pause");
	return sec;
}