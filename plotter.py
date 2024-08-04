import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("./RK4Out")
plt.plot(df["X"], df["Y"])
plt.savefig("output.jpg")
