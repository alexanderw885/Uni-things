import pandas as pd # used for handling populated data sets
import numpy as np # used for handling matrices and arrays
import matplotlib.pyplot as plt # visualization package
import seaborn as sns # visualization, built on matplotlib

# Machine learning imports
from sklearn.model_selection import train_test_split
from sklearn.impute import SimpleImputer
from sklearn.preprocessing import OneHotEncoder
from sklearn.preprocessing import MinMaxScaler



def main():
    housing = pd.read_csv('https://raw.githubusercontent.com/thomouvic/SENG474/main/data/housing.csv')
    housing.head()
    
    # create training and testing sets
    train_set, test_set = train_test_split(housing, 
                                           test_size=0.2, #percent in test_set
                                           random_state=42)

    # we separate the predictors and the labels
    # drop() creates a copy of the data and does not affect the original data
    housing = train_set.drop("median_house_value", axis=1)
                             
    housing_labels = train_set["median_house_value"].copy()
    housing_test = test_set.drop("median_house_value", axis=1)
    housing_labels_test = test_set["median_house_value"].copy()


    # We do here data imputation for the missing values
    imputer = SimpleImputer(strategy="median")
    housing_num = housing.select_dtypes(include=[np.number])
    imputer.fit(housing_num)
    # the fit function "fits" the imputer to the data
    # in this case, the imputer computes the median of each attribute
    # and stores it in its statistics_ instance variable


    # the transform function applies the imputer to the data
    X = imputer.transform(housing_num)
    #print(X)
    # the result is a plain NumPy array containing the transformed features
    # There are other ways to impute missing values,
    # such as using the mean or the most frequent value
    # for example,
    # SimpleImputer(strategy="mean") or
    # SimpleImputer(strategy="most_frequent")

    housing_cat = housing[["ocean_proximity"]]
    # print(housing_cat.head(10))

    # machine learning needs to be done on numerical values, so we need to convert strings to int somehow
    # OneHotEncoder is used to convert categorical values to one-hot vectors
    # for example, '<1H OCEAN' can be converted to [1, 0, 0, 0, 0]
    # 'INLAND' can be converted to [0, 1, 0, 0, 0],
    # 'NEAR OCEAN' can be converted to [0, 0, 0, 0, 1], and so on.
    cat_encoder = OneHotEncoder()
    housing_cat_1hot = cat_encoder.fit_transform(housing_cat)
    # print(housing_cat_1hot)
    # the result is a SciPy sparse matrix
    # a sparse matrix only stores the location of non-zero elements
    # instead of storing all the elements of the matrix
    # for example, (0,4) 1.0 means that the element at row 0 and column 4 is 1.0.


    # Now we will scale the numerical features
    # We scale the features so that they have the same scale, e.g. [0, 1]
    # This is important for some machine learning algorithms
    # Imagine you have two features, 
    # one ranging from 0 to 100 (e.g. age) and 
    # the other from 0 to 100000 (e.g. income)
    # The algorithm might give more importance to the second feature

    # The formula to scale a feature x is:
    # x_scaled = (x - x_min) / (x_max - x_min)
    # where x is the original value, 
    # x_min is the minimum value of x, and 
    # x_max is the maximum value of x

    min_max_scaler = MinMaxScaler()
    housing_minmax = min_max_scaler.fit_transform(housing_num)
    print(housing_minmax)

    # Recall: fit_transform() calls fit() and then transform(). 
    # It's a convenience method.


    # import FunctionTransformer
    from sklearn.preprocessing import FunctionTransformer

    log_transformer = FunctionTransformer(np.log, inverse_func=np.exp)

    log_pop = log_transformer.fit_transform(housing[["population"]])
    log_pop


    from sklearn.preprocessing import StandardScaler
    standard_scaler = StandardScaler()
    housing_standard = standard_scaler.fit_transform(housing_num)
    housing_standard



    from sklearn.pipeline import make_pipeline
    from sklearn.compose import ColumnTransformer

    # extract numerical and categorical attributes
    # into separate dataframes
    housing_num = housing.select_dtypes(include=[np.number])
    housing_cat = housing.select_dtypes(include=['object'])

    # obtain the column names of the numerical and categorical attributes
    num_attribs = list(housing_num)
    cat_attribs = list(housing_cat)

    # create a pipeline for numerical attributes
    num_pipeline = make_pipeline(SimpleImputer(strategy="median"), StandardScaler())

    # create a pipeline for categorical attributes
    cat_pipeline = make_pipeline(SimpleImputer(strategy="most_frequent"), 
                                OneHotEncoder(handle_unknown='ignore'))

    # Combine the numerical and categorical pipelines using 'ColumnTransformer'
    # Here, 'ColumnTransformer' takes a list of tuples,
    # each tuple contains a name, a pipeline, and a list of columns 
    # that the pipeline should be applied to.
    # The output matrices of the pipelines are concatenated side-by-side
    # into a single feature matrix.
    preprocess_pipeline = ColumnTransformer(
        [('num', num_pipeline, num_attribs), 
        ('cat', cat_pipeline, cat_attribs)])

    housing_prepared = preprocess_pipeline.fit_transform(housing)
    print(housing_prepared)



    # If we want to obtain a dataframe from the output of ColumnTransformer,
    # we can use the get_feature_names_out() method to obtain the column names
    # of the transformed data, and then create a dataframe using those names.

    df_housing_num_tr = pd.DataFrame(housing_prepared, 
                                    columns=preprocess_pipeline.get_feature_names_out())
    print(df_housing_num_tr)

if __name__ == "__main__":
    main()