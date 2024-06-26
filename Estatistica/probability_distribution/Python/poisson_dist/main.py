from scipy.stats import poisson


# Poisson Distribution
"""
Um departamento de polícia recebe 5 solicitações por hora, em média,
relacionadas a crimes cometidos. Qual a probabilidade de receber:
--> a. 2 solicitações numa hora selecionada aleatoriamente?
"""

# Parâmetros
lambd = 5  # Número médio de solicitações por hora
k = 2  # solicitações numa hora selecionada aleatoriamente

prob = poisson.pmf(k, lambd)
print(f"A probabilidade de obter 2 solicitações numa hora selecionada aleatoriamente ´de aproximadamente:\
{prob * 100:.2f}%")


# Calcular as probabilidades para k = 0, 1, 2
prob_0 = poisson.pmf(0, lambd)
prob_1 = poisson.pmf(1, lambd)
prob_2 = poisson.pmf(2, lambd)

# Calcular P(X <= 2)
prob_at_most_2 = prob_0 + prob_1 + prob_2

# Imprimir o resultado
print(f"A probabilidade de no máximo 2 solicitações em uma hora é aproximadamente: {prob_at_most_2 * 100:.2f}%")
