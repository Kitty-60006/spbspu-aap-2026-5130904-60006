#include <iostream>

void umensh_elementov(int n, int m, int matrix[])
{
  int top = 0;
  int bottom = n - 1;
  int left = 0;
  int right = m - 1;
  int k = 1;

  while (top <= bottom && left <= right) {
    for (int i = bottom; i >= top; i = i - 1) {
      matrix[i * m + left] = matrix[i * m + left] - k;
      k++;
    }
    left++;
    if (left > right) {
      break;
    }

    for (int j = left; j <= right; j++) {
      matrix[top * m + j] = matrix[top * m + j] - k;
      k++;
    }
    top++;
    if (top > bottom) {
      break;
    }

    for (int i = top; i <= bottom; i++) {
      matrix[i * m + right] = matrix[i * m + right] - k;
      k++;
    }
    right = right - 1;
    if (left > right) {
      break;
    }

    for (int j = right; j >= left; j = j - 1) {
      matrix[bottom * m + j] = matrix[bottom * m + j] - k;
      k++;
    }
    bottom = bottom - 1;
  }
}

int no_one_odinack_strok(int n, int m, int matrix[])
{
  int row_count = 0;

  for (int i = 0; i < n; i++) {
    bool odinack_znach = true;
    for (int j = 1; j < m; j++) {
      if (matrix[i * m + j] == matrix[i * m + j - 1]) {
        odinack_znach = false;
        break;
      }
    }
    if (odinack_znach) {
      row_count++;
    }
  }

  return row_count;
}

int main()
{
  const int MAX_SIZE = 10000;
  int n = 0;
  int m = 0;
  std::cin >> n >> m;

  const int count = n * m;
  int a[MAX_SIZE] = {};
  int b[MAX_SIZE] = {};

  for (int i = 0; i < count; i++) {
    std::cin >> a[i];
    b[i] = a[i];
  }

  umensh_elementov(n, m, b);

  std::cout << n << ' ' << m;
  for (int i = 0; i < count; i++) {
    std::cout << ' ' << b[i];
  }
  std::cout << std::endl;

  std::cout << no_one_odinack_strok(n, m, a) << std::endl;
  return 0;
}
