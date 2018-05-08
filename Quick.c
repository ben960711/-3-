#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void QuickSort(int arr[], unsigned long long left, unsigned long long right) {
	unsigned long long L = left, R = right;
	unsigned long long temp;
	unsigned long long pivot = arr[(left + right) / 2]; //�Ǻ� ��ġ(�߾�)�� ���� ����.

	printf("\n"); //������ Ȯ�� �κ�.

																		//�Ʒ��� while���� ���Ͽ� pivot �������� ��, �� ũ�� ���� �� ����. = Partition
	while (L <= R) {

		//pivot�� �߰� ���̰�, �� ��� arr[L], arr[R]�� pivot�� ���ϴ� �߰� ������ �Ѿ�� ����� �� �� ����.
		while (arr[L] < pivot) //left���� �����ϸ� pivot �̻��� ���� ã��.
			L++;
		while (arr[R] > pivot) //right���� �����ϸ� pivot ���� ���� ã��.
			R--;
		//L, R ��� �ִ� pivot ��ġ���� �̵�.

		if (L <= R) { //���� L�� R���ϸ�. (���� : L>R �κ��� �̹� ������ �� ������).
			if (L != R) { //���� ���� ��츸.
				temp = arr[L];
				arr[L] = arr[R];
				arr[R] = temp;
			} //L�� R�� ���ٸ� ��ȯ(SWAP)�� �ʿ� ���� �� ĭ�� ���ุ ���ָ� ��.
			L++; R--; //�׸��� L,R �� ĭ �� ����.
		}
	}
	if (left < R)
		QuickSort(arr, left, R);
	if (L < right)
		QuickSort(arr, L, right);

}

int main(void) 
{
	clock_t start, end;
	start = clock();

	int data[80000];
	int n = sizeof(data) / sizeof(int);
	srand(time(NULL));

	for (int i = 0; i < n; i++)
		data[i] = (rand() % 80000) + 1;

	QuickSort(data, 0, 80000); 
	end = clock();
	double sec = (end - start) / CLOCKS_PER_SEC;
	printf("�ҿ�ð��� %fms\n", sec);
	system("pause");
	return sec;
}