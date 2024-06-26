import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns


# Gerar uma amostra de 100 lançamentos de moedas com probabilidade de cara = 0.75
dist = np.random.binomial(n=1, p=0.75, size=100)

# No exemplo acima, a distribuição é uma distribuição de Bernoulli, não uma binomial.
# A distribuição de Bernoulli é um caso especial da distribuição binomial com n=1.
# Ou seja, cada lançamento de moeda é uma experiência de Bernoulli com uma única tentativa e uma probabilidade
# p de sucesso (cara).

# Converter a distribuição para um Pandas DataFrame
df = pd.DataFrame({'Resultado': np.where(dist == 1, 'Cara', 'Coroa')})

# Criar um gráfico de barras
sns.countplot(x='Resultado', data=df)
plt.title('Distribuição de Lançamentos de Moeda')
plt.xlabel('Resultado')
plt.ylabel('Frequência')
plt.show()
