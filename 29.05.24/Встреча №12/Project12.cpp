#include <iostream>
#include <random>

template <typename T>
class Matrix {
private:
    int rows;
    int cols;
    T** data;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new T * [rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols];
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    void fillRandom() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<T> dis(1, 100);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = dis(gen);
            }
        }
    }

    void fillFromKeyboard() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << "Enter element [" << i << "][" << j << "]: ";
                std::cin >> data[i][j];
            }
        }
    }

    void display() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    Matrix operator+(const Matrix& other) {
        Matrix sum(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                sum.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return sum;
    }

    Matrix operator-(const Matrix& other) {
        Matrix diff(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                diff.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return diff;
    }

    Matrix operator*(const Matrix& other) {
        Matrix prod(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                prod.data[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    prod.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return prod;
    }

    Matrix operator/(const T scalar) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] / scalar;
            }
        }
        return result;
    }

    T findMax() {
        T max = data[0][0];
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (data[i][j] > max) {
                    max = data[i][j];
                }
            }
        }
        return max;
    }

    T findMin() {
        T min = data[0][0];
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (data[i][j] < min) {
                    min = data[i][j];
                }
            }
        }
        return min;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    Matrix<int> mat1(3, 3);
    Matrix<int> mat2(3, 3);

    // Заполнение матриц случайными значениями
    mat1.fillRandom();
    mat2.fillRandom();

    std::cout << "Matrix 1:" << std::endl;
    mat1.display();

    std::cout << "Matrix 2:" << std::endl;
    mat2.display();

    // Выполнение арифметических операций
    Matrix<int> matSum = mat1 + mat2;
    std::cout << "Сумма матриц:" << std::endl;
    matSum.display();

    Matrix<int> matDiff = mat1 - mat2;
    std::cout << "Разность матриц:" << std::endl;
    matDiff.display();

    Matrix<int> matProd = mat1 * mat2;
    std::cout << "Произведение матриц:" << std::endl;
    matProd.display();

    Matrix<int> matDiv = mat1 / 2;
    std::cout << "Деление одной матрицы:" << std::endl;
    matDiv.display();

    // Поиск максимального и минимального элемента
    std::cout << "Максимум Matrix 1: " << mat1.findMax() << std::endl;
    std::cout << "минимум Matrix 2: " << mat2.findMin() << std::endl;

    return 0;
}