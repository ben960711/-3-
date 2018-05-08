#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void QuickSort(int arr[], unsigned long long left, unsigned long long right) {
	unsigned long long L = left, R = right;
	unsigned long long temp;
	unsigned long long pivot = arr[(left + right) / 2]; //피봇 위치(중앙)의 값을 받음.

	printf("\n"); //데이터 확인 부분.

																		//아래의 while문을 통하여 pivot 기준으로 좌, 우 크고 작은 값 나열. = Partition
	while (L <= R) {

		//pivot이 중간 값이고, 비교 대상 arr[L], arr[R]은 pivot과 비교하니 중간 지점을 넘어가면 종료로 볼 수 있음.
		while (arr[L] < pivot) //left부터 증가하며 pivot 이상의 값을 찾음.
			L++;
		while (arr[R] > pivot) //right부터 감소하며 pivot 이하 값을 찾음.
			R--;
		//L, R 모두 최대 pivot 위치까지 이동.

		if (L <= R) { //현재 L이 R이하면. (이유 : L>R 부분은 이미 정리가 된 상태임).
			if (L != R) { //같지 않은 경우만.
				temp = arr[L];
				arr[L] = arr[R];
				arr[R] = temp;
			} //L과 R이 같다면 교환(SWAP)은 필요 없고 한 칸씩 진행만 해주면 됨.
			L++; R--; //그리고 L,R 한 칸 더 진행.
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
	printf("소요시간은 %fms\n", sec);
	system("pause");
	return sec;
}