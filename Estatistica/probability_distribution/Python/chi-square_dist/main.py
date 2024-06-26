import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import chi2


# Defining degres of fredom
df = 5

# Cumulative distribution function
quantile = chi2.cdf(0.75, df)
print(f"Cumulative distribution function at 0.75 quantile: {quantile}")

# Quantile function
quantiles = chi2.ppf([0.15, 0.25, 0.75, 0.99], df)
print(f"Quantile function at specified probabilities: {quantiles}")

# Density function
x = np.linspace(0, 16, 5000)
density = chi2.pdf(x, df)

plt.figure(figsize=(8, 5))

# Histogram of random valuees
random_values = chi2.rvs(df, size=50000)
plt.hist(random_values, bins=16, density=True, alpha=0.8, color='darkgrey', edgecolor='black', linewidth=0.5, label='Histogram')

# Overlaying the Density Curve
plt.plot(x, density, 'r-', lw=2, label='Chi-Square Density')

plt.title('Chi-Square Distribution (df=5)')
plt.xlabel('X')
plt.ylabel('Density')
plt.legend()
#plt.grid(True)
plt.xlim(0, 16)
plt.show()
