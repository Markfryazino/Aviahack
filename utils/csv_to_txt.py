import pandas as pd

path = '../data/'
files = ['hangars', 'orders', 'companies', 'airplanes', 'types']

data = pd.read_csv(path + files[0] + '.csv')
with open(path + files[0] + '.txt', 'w') as f:
    for i in range(data.shape[0]):
        row = data.iloc[i]
        f.write(row[0].split()[0] + ' ' + str(row[1]) + ' ' + str(row[2]) + '\n')

for j in [1, 4]:
    data = pd.read_csv(path + files[j] + '.csv')
    data.drop('Примечание', axis=1, inplace=True)
    data.fillna(-1, inplace=True)
    n = data.shape[0]
    with open(path + files[j] + '.txt', 'w') as f:
        for i in range(n):
            for el in data.iloc[i]:
                f.write(str(el) + ' ')
            f.write('\n')

for j in [2, 3]:
    data = pd.read_csv(path + files[j] + '.csv')
    n = data.shape[0]
    with open(path + files[j] + '.txt', 'w') as f:
        for i in range(n):
            for el in data.iloc[i]:
                f.write(str(el) + ' ')
            f.write('\n')



