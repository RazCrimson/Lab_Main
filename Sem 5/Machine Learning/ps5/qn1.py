from sklearn import preprocessing
import numpy as np
import pandas as pd
df = pd.read_csv('./datasets/tic-tac-toe.csv')

label_encoder = preprocessing.LabelEncoder()
df["class"] = label_encoder.fit_transform(df["class"])
X = df.drop("class", axis=1)
y = df["class"]
prior = {}
for class_label in y:
    if class_label not in prior:
        prior[class_label] = 0
    else:
        prior[class_label] += 1
for key, value in prior.items():
    prior[key] = prior[key] / y.shape[0]

CPT_list = list()
for (column_name, column_data) in X.iteritems():
    data = []
    for column_type in X[column_name].unique():
        row = {"column_name": column_type}
        for class_label in y.unique():
            row[class_label] = 0
            class_label_count = 0
            for key, value in zip(X[column_name], y):
                if key == column_type and value == class_label:
                    row[class_label] += 1
                if value == class_label:
                    class_label_count += 1
            row[class_label] = row[class_label]/class_label_count
        data.append(row)
    CPT_list.append(pd.DataFrame.from_dict(data))    
CPT_list

def predict(x):
    numerator_list = list()
    for class_label in y.unique():
        numerator = 1
        for value, CPT_table in zip(x, CPT_list):
            for column_type, row_value in zip(CPT_table["column_name"], CPT_table[class_label]):
                if column_type == value:
                    numerator *= row_value
        numerator *= prior[class_label]
        numerator_list.append(numerator)
    denominator = sum(numerator_list)
    return [numerator/denominator for numerator in numerator_list]

print(predict(['x','x','x','b','o','o','b','o','x']))