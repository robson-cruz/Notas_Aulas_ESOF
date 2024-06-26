# Chi-Square Distribution in R

# Defining the degrees of freedom 
df <- 5 

# Density, distribution function, quantile function and random generation for the 
# chi-squared distribution with df degrees of freedom and optional non-centrality parameter ncp.
dchisq(1, df = 1:3)

pchisq(q = .75, df = df)

qchisq(p = c(0.15, .25, .75, .99), df  = df)

pchisq(1, df = df, ncp = 0:4)

# computing values of 50k random values with 5 degrees of freedom 
x <- rchisq(50000, df = df)

hist(x, freq = FALSE, xlim = c(0, 16))
curve(dchisq(x, df = df),
      from = 0, to = 16, n = 5000,
      col = 'red', lwd = 2,
      add = TRUE)
