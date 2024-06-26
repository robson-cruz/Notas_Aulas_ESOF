library(purrr)
library(ggplot2)


# Bernoulli
# distribuição associada à probabilidade de se obter cara a partir de 100 lançamentos de moedas
dist <- rbernoulli(100, p = .75)

# Resumo da distribuição
summary_dist <- table(dist)
print(summary_dist)


# Converter a distribuição para um data frame
df <- data.frame(Resultado = ifelse(dist, "Cara", "Coroa"))

# Criar um gráfico de barras
ggplot(df, aes(x = Resultado)) +
    geom_bar() +
    labs(title = "Distribuição de Lançamentos de Moeda",
         x = "Resultado",
         y = "Frequência") +
    theme_minimal()
