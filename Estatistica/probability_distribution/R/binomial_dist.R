# Binomial Distribution
# Suppose there are twelve multiple choice questions in an English class quiz.
# Each question has five possible answers, and only one of them is correct.
# Find the probability of having four or less correct answers if a student attempts
# to answer every question at random.
#
dbinom(4, size = 12, prob = 1/5)  # Probability of answer a question
pbinom(4, size = 12, prob = 1/5)  # probability of having four or less correct answers
