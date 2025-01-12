#!/bin/bash

# Путь к исходному файлу
SOURCE_FILE="lab4.cpp"
OUTPUT_FILE="lab4.out"

# Очищаем директорию от старых CSV-файлов
echo "Очистка директории от старых CSV-файлов..."
rm -f *.csv

# Компиляция исходного файла
echo "Компиляция $SOURCE_FILE..."
g++ -o $OUTPUT_FILE $SOURCE_FILE -std=c++11

# Проверка успешности компиляции
if [ $? -ne 0 ]; then
  echo "Ошибка компиляции. Выход."
  exit 1
fi

# Запрашиваем шаг h для всех запусков
echo "Введите шаг h для всех запусков:"
read H

# Запрашиваем значения ε для всех запусков
echo "Напишите значения ε для измерений (через пробел):"
read -a EPSILONS

# Запрашиваем количество запусков программы
NUM_RUNS=${#EPSILONS[@]}  # Количество запусков соответствует количеству значений ε

# Запуск программы для каждого значения ε
for ((i = 0; i < NUM_RUNS; i++)); do
  echo "Запуск $((i + 1)):"

  # Получаем значение ε из массива
  EPSILON=${EPSILONS[$i]}

  # Запуск программы с указанными параметрами
  echo "Запуск программы с h=$H и ε=$EPSILON..."
  echo -e "$H\n$EPSILON" | ./$OUTPUT_FILE
done

# Запуск Python-скрипта viz.py
echo "Запуск Python-скрипта viz.py для визуализации..."
python3 viz.py

echo "Все запуски завершены и визуализация завершена."