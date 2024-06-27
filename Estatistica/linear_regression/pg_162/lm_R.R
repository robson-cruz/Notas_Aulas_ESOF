library(ggplot2)
library(dplyr)


# --> Exemplo Livro Didático - página 162:
# Verifique se existe correlação linear entre o número de nascidos vivos e a
# taxa de mortalidade infantil na região de Maringá-PR.

data <- read.csv("data.txt")


plot(data$nascidos_vivos, data$taxa,
     xlab = "Nascidos Vivos",
     ylab = "Taxa de Mortalidade",
     col = "red")

data |>
    ggplot(aes(nascidos_vivos, taxa)) +
    geom_point() +
    geom_smooth(method = "lm", se = FALSE)

cor(data$nascidos_vivos, data$taxa)

linear_model <- lm(taxa ~ nascidos_vivos, data = data)
summary(linear_model)

data <- data |>
    mutate(predicted_rate = predict(linear_model)) 

data |>
    ggplot(aes(nascidos_vivos, taxa)) +
    geom_point() +
    geom_smooth(method = "lm", se = FALSE) +
    geom_point(aes(nascidos_vivos, predicted_rate), color = "red")
