#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
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

bool readMatrix(std::istream & input, std::size_t & n, std::size_t & m, std::vector< int > & matrix)
{
  if (!(input >> n >> m)) {
    return false;
  }

  const std::size_t count = n * m;
  matrix.resize(count);
  for (std::size_t i = 0; i < count; i++) {
    if (!(input >> matrix[i])) {
      return false;
    }
  }

  return true;
}

void writeResult(std::ostream & output, std::size_t n, std::size_t m, const std::vector< int > & source,
                 const std::vector< int > & result)
{
  output << n << ' ' << m;
  for (std::size_t i = 0; i < n * m; i++) {
    output << ' ' << result[i];
  }
  output << '\n';
  output << noOneOdinackStrok(n, m, source.data()) << '\n';
}

int main(int argc, char *argv[])
{
  if (argc != 4) {
    return 1;
  }

  const std::string mode = argv[1];
  if (mode != "1" && mode != "2") {
    return 1;
  }

  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  if (!input || !output) {
    return 1;
  }

  std::size_t n = 0;
  std::size_t m = 0;
  std::vector< int > source;
  std::vector< int > result;

  if (!readMatrix(input, n, m, source)) {
    return 1;
  }

  result = source;
  umenshElementov(n, m, result.data());

  writeResult(output, n, m, source, result);

  return output.good() ? 0 : 1;
}
