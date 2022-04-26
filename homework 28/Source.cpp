#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;
//����� ������� �� �����
template <typename T> void showArr(T arr, int length);
//�������� ��������
template <typename T> T addArr(T arr1[], int length1, T arr2[], int length2, T arr3[], int length3);
//���������� �������
template <typename T> T* resizeArr(T arr[], int length, int newLength);


int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

			//������ 1
	cout << "������ 1\n������� ������ ������� A: ";
	unsigned int a;
	cin >> a;
	int* arrA = new int[a];
	cout << "������� ������ ������� B: ";
	unsigned int b;
	cin >> b;
	int* arrB = new int[b];
	for (int i = 0; i < a; i++) {
		arrA[i] = rand() % 10;
	}
	for (int j = 0; j < b; j++) {
		arrB[j] = rand() % (20 - 10) + 10;
	}
	cout << "����������� ������ �:\n";
	showArr(arrA, a);
	cout << "����������� ������ B:\n";
	showArr(arrB, b);
	cout << "������ �:\n";
	
	unsigned int c = a + b;
	int* arrC = new int[c];
	addArr(arrA, a, arrB, b, arrC, c);
	showArr(arrC, c);
	
	delete[] arrA;
	delete[] arrB;
			
			//������ 2
	cout << "������ 2\n������� ������ �������: ";
	cin >> a;
	int* arr = new int[a];
	cout << "������� ����� ������ �������: ";
	cin >> b;
	for (int i = 0; i < a; i++)
		arr[i] = i + 1;
	cout << "����������� ������:\n";
	showArr(arr, a);
	cout << "������ � ����� �������:\n";
	resizeArr(arr, a, b);
	
	return 0;
}
template <typename T> T* resizeArr(T arr[], int length, int newLength) {
	if (newLength <= 0)
		return arr;
	T* tmp = new T[length];
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	delete[] arr;
	
	arr = new T [newLength];
	for (int i = 0; i < newLength; i++) {
		arr[i] = tmp[i];
		if (i >= length)
			arr[i] = 0;
	}
	delete[] tmp;
	showArr(arr, newLength);
}

template <typename T> T addArr(T arr1[], int length1, T arr2[], int length2, T arr3[], int length3) {
	for (int i = 0; i < length1; i++)
		arr3[i] = arr1[i];
	for (int i = length3 - length2; i < length3; i++)
		arr3[i] = arr2[i-length1];
	return arr3[length3];
}

template <typename T> void showArr(T arr, int length) {
	cout << "[";
	for (int i = 0; i < length; i++) {
		cout << arr[i] << ", ";
	}
	cout << "\b\b.]\n\n";
}