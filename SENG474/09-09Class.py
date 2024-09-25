import pandas as pd # used for handling populated data sets
import numpy as np # used for handling matrices and arrays
import matplotlib.pyplot as plt # visualization package
import seaborn as sns # visualization, built on matplotlib
from sklearn.model_selection import train_test_split

def main():

    housing = pd.read_csv('https://raw.githubusercontent.com/thomouvic/SENG474/main/data/housing.csv')
    # now housing is a dataframe, housing.head() prints first 5 values
    print(housing.head(), "\n---\n") 
    # housing.info gives description of the columns
    print(housing.info())
    # housing.describe gives info such as mean/median, all those stats things
    print(housing.describe())
    # generates histograms of all data points
    #housing.hist(bins=50, figsize=(20,8))
    plt.show() # needed to actually show any plots\graphs
    #makes scatterplot
    #housing.plot(kind="scatter", x="longitude",y="latitude",alpha=0.1)
    plt.show()

    # Generates correlation values for every pair of values
    # 1 means positive correlation, -1 means negative correlation, 0 means no correlation
    housing_num = housing.select_dtypes(include=[np.number])
    housing_num.corr ()
    # we might notice here that median income and median house value have a close positive correlation

    housing.plot(kind="scatter", x="longitude", y="latitude", alpha=0.4,
        s=housing["population"]/100, #size of dots
        label="population",
        figsize=(10,7),
        c="median_house_value",
        colorbar=True)
    plt.show()

    # create sets for maching learning, using scikit_learn
    train_set, test_set = train_test_split(housing, test_size=0.2, random_state=42)

    

if __name__ == "__main__":
    main()