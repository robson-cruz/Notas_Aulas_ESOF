library(dplyr, warn.conflicts = FALSE)


ages <- c(7, 31, 43, 48, 50, 41, 7, 11, 15, 39, 80, 82, 32, 4, 8, 6, 25, 36, 27, 61, 31)


summary(ages)


quantile(ages, probs = c(.25, .50, .75))


iris |>
    group_by(Species) |>
    summarize(mean = mean(Sepal.Length),
              `.25` = quantile(Sepal.Length, probs = .25),
              `.50` = quantile(Sepal.Length, probs = .50),
              `.75` = quantile(Sepal.Length, probs = .75))
