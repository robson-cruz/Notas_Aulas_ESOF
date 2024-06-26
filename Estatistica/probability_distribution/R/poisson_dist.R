# Poisson Distribution
#
# Um departamento de polícia recebe 5 solicitações por hora, em média,
# relacionadas a crimes cometidos. Qual a probabilidade de receber:
# --> a. 2 solicitações numa hora selecionada aleatoriamente?

# Parameters
lambda <- 5  # Average number of requests per hour
k <- 2       # Number of requests we are interested in

# Calculate the probability using dpois function
prob <- dpois(k, lambda)

# Print the result
prob


# b. No máximo 2 solicitações numa hora selecionada aleatoriamente?
# Calculate probabilities for k = 0, 1, 2
prob_0 <- dpois(0, lambda)
prob_1 <- dpois(1, lambda)
prob_2 <- dpois(2, lambda)

# Calculate P(X <= 2)
prob_at_most_2 <- prob_0 + prob_1 + prob_2

# Print the result
prob_at_most_2
