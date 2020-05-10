import pandas as pd

def hadle_company(x):
    return x.replace(' ', '_')

def handle_num(x):
    if x != x:
        return x
    else:
        return int(x.replace('\xa0', ''))
    
def handle_num_2(x):
    return float(x.replace(',', '.'))

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
    if 'Авиакомпания' in data.columns:
        data['Авиакомпания'] = data['Авиакомпания'].apply(hadle_company)
        
    if files[j] == 'types':
        for col in ['DME \n(стоимость 1 дня), руб', 'SVO \n(стоимость 1 дня), руб', 'VKO \n(стоимость 1 дня), руб']:
            data[col] = data[col].apply(handle_num)
        
    data.fillna(-1, inplace=True)
    n = data.shape[0]
    with open(path + files[j] + '.txt', 'w') as f:
        for i in range(n):
            for el in data.iloc[i]:
                f.write(str(el) + ' ')
            f.write('\n')

for j in [2, 3]:
    data = pd.read_csv(path + files[j] + '.csv')
    if 'Авиакомпания' in data.columns:
        data['Авиакомпания'] = data['Авиакомпания'].apply(hadle_company)
    else:
        for col in ['Длина, м', 'Размах крыла, м']:
            data[col] = data[col].apply(handle_num_2)
    n = data.shape[0]
    with open(path + files[j] + '.txt', 'w') as f:
        for i in range(n):
            for el in data.iloc[i]:
                f.write(str(el) + ' ')
            f.write('\n')



