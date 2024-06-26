# Normal data distribution with mean 5.0 and the standard deviation 1.0
data <- rnorm(100000, 5, 1)

hist(data, 100)

normal_dist <- tibble::tibble(dist = data)

normal_dist |>
    ggplot() +
        geom_density (aes(x = dist), fill = "steelblue" ) +
        geom_vline(xintercept = 5)
