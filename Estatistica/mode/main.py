from scipy import stats


data = [2, 4, 5, 5, 8, 11, 14, 21]
modal = stats.mode(data)
print(modal)
