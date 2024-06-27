import pandas as pd
import matplotlib.pyplot as plt
from scipy.stats import linregress


data = pd.read_csv("data.txt")
# print(data.head())

"""
--> Exemplo Livro Didático - página 162:
Verifique se existe correlação linear entre o número de nascidos vivos e a
taxa de mortalidade infantil na região de Maringá-PR.
"""

plt.scatter(data['nascidos_vivos'], data['taxa'])
plt.show()

# Linear Regression
regression = linregress(data['nascidos_vivos'], data['taxa'])
# print(f'Coefficient of Correlation: {regression[2]}')

linear_reg_data = pd.DataFrame({
    'slope': regression[0],
    'intercept': regression[1],
    'r': regression[2],
    'p': regression[3],
    'std_err': regression[4]
}, index=[0])

print(linear_reg_data)

# Predict the infant mortality rate
def predict_data(x):
    return linear_reg_data['slope'] * x + linear_reg_data['intercept']


linear_model = list(map(predict_data, data['nascidos_vivos']))

plt.scatter(data['nascidos_vivos'], data['taxa'])
plt.plot(data['nascidos_vivos'], linear_model)
plt.show()
