from scipy.stats import binom


# Binomial Distribution

# Suppose there are twelve multiple choice questions in an English class quiz.
# Each question has five possible answers, and only one of them is correct.
# Find the probability of having four or less correct answers if a student attempts
# to answer every question at random.

# Parameters
n = 12  # number of questions
p = 1/5  # Success probability

# Exact Probability of answer a question
exact_prob = binom.pmf(4, n, p)
print(exact_prob)

# Calculates the probability of having four or less correct answers
# Accumulated probability
probability = binom.cdf(4, n, p)
print(probability)
