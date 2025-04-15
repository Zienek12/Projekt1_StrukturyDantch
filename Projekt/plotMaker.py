import pandas as pd
import matplotlib.pyplot as plt
import os
fileName = 'Results/benchmark'
structureName = {
    'DynamicArray',
    'LinkedList'
}
operationName = {
    'AddBack',
    'AddFront',
    'AddIndex',
    'RemoveBack',
    'RemoveFront',
    'RemoveIndex',
    'Search'
}
textFile = '.txt'

os.makedirs('plots', exist_ok=True)

for structure in structureName:
    for operation in operationName:
        path = fileName + structure + operation + textFile
        data = pd.read_csv(path, sep=',', header=0)

        plt.figure(figsize=(8, 5))
        plt.plot(data['Iterations'], data['AvgTime'], marker='o', linestyle='-', color='b')
        plt.title(f'{structure} - {operation}')
        plt.xlabel('Iterations')
        plt.ylabel('Average Time (ns)')
        plt.xticks(data['Iterations'])
        plt.xscale('log')
        plt.grid(True)
        plt.savefig(f'plots/{structure}_{operation}.png')
        plt.close()
        print(f'Wykres zapisany: plots/{structure}_{operation}.png')