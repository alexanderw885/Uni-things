import itertools

def f(x):
    print('in f', x)



lst = (f(x) for x in range(1000))
# lst = itertools.islice(lst,4)
# #lst=map(f,lst) # Returns a generator
# print(lst)
# lst = list(lst) # converts this generator into a list
# print(lst)
    