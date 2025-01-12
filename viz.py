import os
import pandas as pd
import matplotlib.pyplot as plt

# Функция для загрузки и построения графиков
def plot_results():
    # Получаем список всех CSV файлов в текущей папке, начинающихся с "results_"
    files = [f for f in os.listdir() if f.startswith("results_") and f.endswith(".csv")]
    
    plt.figure(figsize=(10, 6))
    
    # Проходим по всем файлам
    for file in files:
        # Загрузка данных
        data = pd.read_csv(file)
        plt.plot(data['t'], data['theta'], label=f'{file}')
    
    # Настройка графика
    plt.title('θ(t) для разных значений ε')
    plt.xlabel('Время (t)')
    plt.ylabel('θ')
    plt.legend()
    plt.grid(True)
    
    # Сохранение графика в файл
    plt.savefig('theta_vs_time.png')  # Сохраняет график в файл в формате PNG
    plt.show()  # Показывает график на экране

# Вызов функции
plot_results()
