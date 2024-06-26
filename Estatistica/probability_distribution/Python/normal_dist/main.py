import numpy as np
import matplotlib.pyplot as plt


# Normal data distribution with mean 5.0 and the standard deviation 1.0
data = np.random.normal(5.0, 1.0, 100000)

plt.hist(data, 100)
plt.show()
