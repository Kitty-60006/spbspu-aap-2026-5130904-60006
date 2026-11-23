#include <cstddef>
#include <iostream>
#include <vector>

void umenshElementov(std::size_t n, std::size_t m, int matrix[])
{
  if (n == 0 || m == 0) {
    return;
  }

  std::size_t top = 0;
  std::size_t bottom = n - 1;
  std::size_t left = 0;
  std::size_t right = m - 1;
  int k = 1;

  while (top <= bottom && left <= right) {
    for (std::size_t i = bottom + 1; i > top; i = i - 1) {
      matrix[(i - 1) * m + left] = matrix[(i - 1) * m + left] - k;
      k++;
    }
    left++;
    if (left > right) {
      break;
    }

    for (std::size_t j = left; j <= right; j++) {
      matrix[top * m + j] = matrix[top * m + j] - k;
      k++;
    }
    top++;
    if (top > bottom) {
      break;
    }

    for (std::size_t i = top; i <= bottom; i++) {
      matrix[i * m + right] = matrix[i * m + right] - k;
      k++;
    }
    right = right - 1;
    if (left > right) {
      break;
    }

    for (std::size_t j = right + 1; j > left; j = j - 1) {
      matrix[bottom * m + j - 1] = matrix[bottom * m + j - 1] - k;
      k++;
    }
    bottom = bottom - 1;
  }
}

std::size_t noOneOdinackStrok(std::size_t n, std::size_t m, const int matrix[])
{
  std::size_t row_count = 0;

  for (std::size_t i = 0; i < n; i++) {
    bool odinack_znach = true;
    for (std::size_t j = 1; j < m; j++) {
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
  std::size_t n = 0;
  std::size_t m = 0;
  if (!(std::cin >> n >> m)) {
    return 1;
  }

  const std::size_t count = n * m;
  std::vector< int > a(count);
  std::vector< int > b(count);

  for (std::size_t i = 0; i < count; i++) {
    if (!(std::cin >> a[i])) {
      return 1;
    }
    b[i] = a[i];
  }

  umenshElementov(n, m, b.data());

  std::cout << n << ' ' << m;
  for (std::size_t i = 0; i < count; i++) {
    std::cout << ' ' << b[i];
  }
  std::cout << '\n';
  if (std::cout.fail()) {
    return 1;
  }

  std::cout << noOneOdinackStrok(n, m, a.data()) << '\n';
  if (std::cout.fail()) {
    return 1;
  }

  return 0;
}
