'''
A python program to doing basic math operations to solve the question set4 in CA1.

Functions are not used as they will only make the execution time and complexity longer.

Author: Bharath Vignesh J K (19PW08)
'''

# Initializing necessary variables
data = []
sum_of_cases_sold = 0
number_of_days = 0
max_frequency_index = None


# Getting input from user
profit_per_case = int(input('Enter profit per case: '))
start_of_entries = int(input('Enter the starting range : '))
end_of_entries = int(input('Enter the ending range : '))
for i in range(end_of_entries - start_of_entries + 1):
    cases_sold = start_of_entries + i
    frequency = int(
        input(f'Enter the number of days {cases_sold} cases are sold: '))
    data.append((cases_sold, frequency))

    # Calculating sum and number of days and finding max occurance to avoid 
    # recomputing it later on.
    sum_of_cases_sold += cases_sold * frequency
    number_of_days += frequency
    if max_frequency_index is None:
        max_frequency_index = i
    elif data[max_frequency_index][1] < frequency:
        max_frequency_index = i


# The number of days mentioned in question(240) is wrong,
# the value according to the dataset is 241

print('\n\nQUESTION A:')
# Calulating the average
average_cases_sold = sum_of_cases_sold / number_of_days
print(f'Average Number of cases sold per day is: {average_cases_sold}')

# Finding Mode
mode = data[max_frequency_index][0]
print(f'Mode of the given data is: {mode}')

# Calculating standard deviation and Variance
standard_deviation = 0
for cases_sold, frequency in data:
    x = cases_sold - average_cases_sold
    x **= 2
    standard_deviation = x * frequency
standard_deviation /= number_of_days
standard_deviation **= 0.5
print(f'Standard Deviation is: {standard_deviation}\n' 
      f'Variance is : {standard_deviation ** 2}')


print('\n\nQUESTION B:')
# Calculating average profit per day
avg_profit_per_day = average_cases_sold * profit_per_case
print(f'Average Profit per day is: {avg_profit_per_day} euros')

# Calculating average annual profit 
avg_annual_profit = avg_profit_per_day * 365
print(f'Average Annual Profit: {avg_annual_profit} euros')


'''
Here are some functional alternatives for computing average,standard deviation and others
The data in the table must be expanded to individual entries befor using these functions.

from typing import List

def average(data_list: List[int]):
    sum = 0
    for x in data_list:
        sum += x
    if len(data_list) != 0:
        return sum/len(data_list)
    else:
        return 0


def standard_deviation(data_list: List[int]):
    avg = average(data_list)
    sd = 0
    for x in data:
        sd += (x - avg) ** 2
    sd /= len(data_list)
    return sd ** 0.5

'''
