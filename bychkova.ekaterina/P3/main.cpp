#include <iostream>
#include <vector>

int main()
{
  int n = 0;
  int m = 0;
  if (!(std::cin >> n >> m) || n < 0 || m < 0) {
    return 0;
  }

  if (n == 0 || m == 0) {
    std::cout << n << ' ' << m << '\n' << 0 << '\n';
    return 0;
  }

  const int count = n * m;
  std::vector<int> a(count);
  std::vector<int> b(count);

  std::cout << n << ' ' << m << ' ';
  for (int i = 0; i < count; i++) {
    if (!(std::cin >> a[i])) {
      return 0;
    }
    b[i] = a[i];
  }

  int top = 0;
  int bottom = n - 1;
  int left = 0;
  int right = m - 1;
  int k = 1;

  while (top <= bottom && left <= right) {
    for (int i = bottom; i >= top; i = i - 1) {
      b[i * m + left] -= k++;
    }
    left++;
    if (left > right) {
      break;
    }

    for (int j = left; j <= right; j++) {
      b[top * m + j] -= k++;
    }
    top++;
    if (top > bottom) {
      break;
    }

    for (int i = top; i <= bottom; i++) {
      b[i * m + right] -= k++;
    }
    right = right - 1;
    if (left > right) {
      break;
    }

    for (int j = right; j >= left; j = j - 1) {
      b[bottom * m + j] -= k++;
    }
    bottom = bottom - 1;
  }

  for (int i = 0; i < count; i++) {
    std::cout << b[i] << ' ';
  }
  std::cout << '\n';

  int row_count = 0;
  for (int i = 0; i < n; i++) {
    bool odinack_znach = true;
    for (int j = 1; j < m; j++) {
      if (a[i * m + j] == a[i * m + j - 1]) {
        odinack_znach = false;
        break;
      }
    }
    if (odinack_znach) {
      row_count++;
    }
  }

  std::cout << row_count << '\n';
  return 0;
}
