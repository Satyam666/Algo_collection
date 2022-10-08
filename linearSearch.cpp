// C code to linearly search x in arr[]. If x
// is present then return its location, otherwise
// return -1

#include <iostream>

using namespace std;

int search(int arr[], int N, int x)
{
	int i;
	for (i = 0; i < N; i++)
		if (arr[i] == x)
			return i;
	return -1;
}

// Driver's code
int main()
{
	int n, x;
	cout << "Enter the size of the Array: ";
	cin >> n;
	int arr[n];

	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	cout << "Enter the number you wanted to search for: ";
	cin >> x;

	// Function call
	int result = search(arr, n, x);
	(result == -1)
		? printf("Element is not present in array")
		: printf("Element is present at index %d", result + 1);
	return 0;
}
