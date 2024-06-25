import numpy as np
import matplotlib.pyplot as plt


# Create an array containing 250 random floats between 0 and 5
data = np.random.uniform(0.0, 5.0, 250)

plt.hist(data, 10)
plt.show()
