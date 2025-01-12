#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>  // Для преобразования числа в строку
#include <vector>

double e = 1.25;  // Параметр ε = ω/ω_c

// Функция, описывающая правую часть уравнения
double derivative(double t) {
  return e - sin(t);  // Уравнение: dθ/dt = ε - sin(θ)
}

int main() {
  // Ввод параметров
  double h;
  std::cout << "Enter step size h: ";
  std::cin >> h;

  std::cout << "Enter epsilon (ε = ω/ω_c): ";
  std::cin >> e;

  // Динамические массивы
  std::vector<double> t, Y;

  // Начальные условия
  t.push_back(0.0);  // Время начинается с 0
  Y.push_back(0.0);  // Начальное значение θ

  // Метод Рунге-Кутты 4-го порядка
  for (int i = 1; i < 100; i++) {
    double k1 = derivative(Y.back());
    double k2 = derivative(Y.back() + h * k1 / 2);
    double k3 = derivative(Y.back() + h * k2 / 2);
    double k4 = derivative(Y.back() + h * k3);

    t.push_back(t.back() + h);
    Y.push_back(Y.back() + h * (k1 + 2 * k2 + 2 * k3 + k4) / 6);

    // Вывод текущих значений
    std::cout << "t: " << t.back() << " theta: " << Y.back() << std::endl;
  }

  // Формирование имени файла с учетом значения ε
  std::ostringstream fileName;
  fileName << "results_" << e
           << ".csv";  // Создаем имя файла, добавляя значение ε

  // Сохранение результатов в файл
  std::ofstream outFile(fileName.str());
  outFile << "t,theta\n";
  for (size_t i = 0; i < t.size(); i++) {
    outFile << t[i] << "," << Y[i] << "\n";
  }
  outFile.close();

  std::cout << "Results saved to " << fileName.str() << "\n";

  return 0;
}
