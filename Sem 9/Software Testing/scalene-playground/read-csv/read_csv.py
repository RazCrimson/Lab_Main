import csv
import pandas as pd


def manual_read_csv(file_name: str) -> list[dict]:
    data_list = []

    with open(file_name, mode='r') as file:
        csv_reader = csv.DictReader(file)
        
        for row in csv_reader:
            data_list.append(row)

    return data_list


def pd_read_csv(file_name: str):
    return pd.read_csv(file_name)



if __name__ == "__main__":
    file = "repositories.csv"
    manual_read_csv(file)
    pd_read_csv(file)