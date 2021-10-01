## Random Variables

Two Types:
 - Discrete (whole numbers)
   - Bernoulli Random Variable - Booloean
   - Multinomial Random Variable - More then 2 values
   - Gaussian Random variable - ?(for discrete?)
 - Continuous (range)


## Statistics - Sampling
We estimate a parameter for a population by taking a smaller sample and calculate the parameter with that sample.

- Parameter - Anything that needs to be calculated for the population

- Estimator - Any Parameter calulated for a sample. An estimator should be closer to the parameter.


## Data Preprocessing
We clean the data for increasing the accuracy of the model. This can be done by: 
- Normalizing the data 
- Removing outliers.
    - Outlier are data points that deviate too much from the original set of data points.


## Normalization 
We normalize to change the data points to use a common scale. It converts data points to a standard normal deviation. 

- Z Score(Z distribution?) - Formula = (X - Xbar)/Sigma

**Note:** Use n-1 instead of n when calculating the estimators for sample.


## Box Plot
- Objective to detect Outliers.
- First Representation - Quartile(Min, Max, Q1, Q2, Q3)
  - We select 3 points that divide the dataset into 4 equal partition based on the number of datapoints. Incase of quartile being a two even median values, we add those to two groups around the quartile points. 
  

- Second Representation - IQR(Inter-Quarantile Range) (Q1, Q2, Q3, Lb, Ub)
  - IQR = Q3 - Q1
  - Lb = Q1 - 1.5 IQR
  - Ub = Q3 + 1.5 IQR

