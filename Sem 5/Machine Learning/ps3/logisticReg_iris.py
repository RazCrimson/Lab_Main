import pandas as pd
import numpy as np
import matplotlib as plt

df = pd.read_csv('z:/Repos/Lab_Main/Sem 5/Machine Learning/ps3/dataset/iris.data')
df = df[df[4] != "Iris-virginica"]
print(df)