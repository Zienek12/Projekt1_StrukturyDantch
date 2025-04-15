import pandas as pd
import matplotlib.pyplot as plt
import os
import numpy as np

fileName = 'Results/benchmark'
structureName = ['DynamicArray', 'LinkedList']
operationName = ['AddBack', 'AddFront', 'AddIndex', 'RemoveBack', 'RemoveFront', 'RemoveIndex', 'Search']
textFile = '.txt'

os.makedirs('plots', exist_ok=True)

plt.style.use('ggplot')
colors = {
    'DynamicArray': '#1f77b4',
    'LinkedList': '#ff7f0e'
}
trendline_color = '#d62728'

for structure in structureName:
    for operation in operationName:
        path = fileName + structure + operation + textFile
        try:
            data = pd.read_csv(path, sep=',', header=0)
            
            x = data['Iterations']
            y = data['AvgTime']
            
            coeffs = np.polyfit(x, y, 1)
            trendline = np.poly1d(coeffs)
            
            plt.figure(figsize=(10, 6))

            plt.plot(x, y, 
                    marker='o', 
                    linestyle='-', 
                    color=colors.get(structure, '#1f77b4'),
                    label='Dane pomiarowe')
            
            plt.plot(x, trendline(x), 
                    '--', 
                    color=trendline_color,
                    linewidth=1.5,
                    label=f'Trend (y={coeffs[0]:.2f}x+{coeffs[1]:.2f})')
            
            plt.xscale('log')
            plt.yscale('log')
            
            plt.title(f'{structure} - {operation}', fontsize=14, pad=20)
            plt.xlabel('Rozmiar danych (n)', fontsize=12)
            plt.ylabel('Średni czas (ns)', fontsize=12)
            
            plt.grid(True, which='both', linestyle='--', alpha=0.7)
            plt.legend(fontsize=10)
            
            y_min = max(0.9 * min(y), 1)  
            y_max = 1.1 * max(y)
            plt.ylim(y_min, y_max)
            
            plt.gca().xaxis.set_major_formatter(plt.ScalarFormatter())
            plt.gca().yaxis.set_major_formatter(plt.ScalarFormatter())
            
            plt.tight_layout()
            plt.savefig(f'plots/{structure}_{operation}.png', dpi=300)
            plt.close()
            
            print(f'Wykres zapisany: plots/{structure}_{operation}.png')
        except FileNotFoundError:
            print(f'Plik nie znaleziony: {path}')
        except pd.errors.EmptyDataError:
            print(f'Plik jest pusty lub ma niepoprawny format: {path}')
        except Exception as e:
            print(f'Nieoczekiwany błąd dla pliku {path}: {e}')
      
print("Generowanie wykresów zakończone.")
