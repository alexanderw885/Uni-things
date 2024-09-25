# setup

cars<-read.table(file="~/Documents/STAT 359/car-speeds.txt", 
                   sep="",
                 header=TRUE)
speed.up<-cars$speed[cars$direction=='Up']
speed.down<-cars$speed[cars$direction=='Down']

library(knitr)

# -----------------------------------------------

# have a lot of measurements, so we can use confidence interval for large datasets

#H0: same distribution
#H1: up -down > 0

est<-mean(speed.up)-mean(speed.down)
parameter<-0
bottom.bit<-sqrt( (var(speed.up)/length(speed.up)) +  (var(speed.down)/length(speed.down)))
bottom.bit

t.val<-(est)/bottom.bit
t.val

p.val<-2*(1-pnorm(t.val))
p.val

# ---------------------------
stereograms<-read.table(file="~/Documents/STAT 359/stereograms.txt", 
                 sep="", header=TRUE)
#nv - no info ahead of time
# vv - informed of shape ahead of time
#
#H): muNV-muVV=0
#H1: muNV - muVV > 0

time.NV<-stereograms$fusiontime[stereograms$group=='NV']
time.VV<-stereograms$fusiontime[stereograms$group=='VV']
summary(time.NV)
summary(time.VV)
boxplot(time.NV, time.VV, col='green')

# not get t.obs and p-val
T.obs<-(mean(time.NV) - mean(time.VV))/sqrt( (var(time.NV)/length(time.NV)) +  (var(time.VV)/length(time.VV)))
T.obs
#t.obs is much smaller this time
p.val<-1-pnorm(T.obs)
p.val
# given alpha of 0.05, we have evidence against the null hypothesis of muNV=muVV

# --------------------------

# how does friendship affect sales?
# one group was buying from a friend a friend they'll see again, the other from a stranger
# price was offered by the participants

buy.friend<-read.table(file="~/Documents/STAT 359/buy-from-a-friend.txt",
                       sep="",
                       header=TRUE,
                       na.strings="NA")
buy.friend

boxplot(buy.friend$Friend, buy.friend$Stranger, col='green', names=c("Friend","Stranger"))
attach(buy.friend)
Stranger<-Stranger[!is.na(Stranger)]
summary(buy.friend)

# the friend group seems to have much higher prices
# the medians are quite different

# small sample size, have to use bootstrap test, a resampling procedure
# given n elements, let probability of each value in the set be 1/n
# sample from this distribution to get a larger sample
# sources of error: approximating real distribution with this distribution,
# and the error of samepling errors in pulling from a distribution. goes to 0 as you do more

#let alpha = 0.05

theta.hat <- median(Friend) - median(Stranger)
## number of bootstrap replicates
B<-10000
theta.boot<-rep(0,B) # vector of median differences, the est-val when calculation t.obs
for (i in 1:B)
{
  ## resample the Friend data
  Friend.boot<-sample(x=Friend,size=length(Friend),replace=TRUE)
  #sample function samples values from the provided vector
  #replacement=TRUE means that after sampling a value, put it back in the
  #original vector, to allow you to sample that value again
  ## resample the Stranger data
  Stranger.boot<-sample(x=Stranger,size=length(Stranger),replace=TRUE) 
  # it's important that the size of each sample is the same size as the original
  
  ## compute the bootstrap replicate of the estimator
  theta.boot[i]<-median(Friend.boot) - median(Stranger.boot)
}
alpha<-0.05
##lower bound
lower.bound<-quantile(theta.boot,probs=alpha/2)
upper.bound<-quantile(theta.boot,probs=1-alpha/2)
## estimate of the difference in medians
theta.hat
c(lower.bound, upper.bound)

# this bootstrap confidence interval does not contain the value zero.
# this means that given an alpha of 0.05, the difference in expected price is
# approximately between $25 and $120

# is this reliable? surprisingly so, though not as accurate as a regular z-test

# ----------------------------------------------------------------------------

# lets test with n = 5, 10, 15, ...
## sample size over which to run the simulation study
start.time <- Sys.time()
sample.size<-seq(5,40,5)
cov.prob<-rep(0,length(sample.size))
## for each sample size we will generate n.sim replicate datasets to estimate 
#  coverage probability
n.sim<-10 # n.sim<-5000 #use 5000 simulations for greater stability in actual results
## for each replicate data set we will based the bootstrap interval on
#  B bootstrap samples
B<-1000
n<-5
coverage.indicator<-rep(0,n.sim) # create a vector of length n.sim, fill with 0
n.iter<-1
for(n in sample.size)
{
  for (j in 1:n.sim)
  {
    ## generate data from a standard exponential distribution where the median is   log(2)
    x<-rexp(n=n,rate=1) ## the median of this distribution is log(2)
    median.boot<-rep(0,B)
    for (b in 1:B)
    {
      x.boot<-sample(x=x,size=length(x),replace=TRUE) 
      median.boot[b]<-median(x.boot)
    }
    lower.median<-quantile(median.boot,probs=0.025)
    upper.median<-quantile(median.boot,probs=0.975)
    coverage.indicator[j]<-as.numeric((lower.median<=log(2))&&(log(2)<=upper.median)) 
  }
  cat('Completed iteration for n =',n,'\n')
  cov.prob[n.iter]<-mean(coverage.indicator)  
  n.iter<-n.iter+1
}
end.time <- Sys.time()
time.taken1 <- end.time - start.time
cov.prob
# data from 1000 simulations
#[1] 0.930 0.926 0.919 0.944 0.939 0.937 0.949 0.944
time.taken1
#Time difference of 4.793314 mins

## What did we just do?
## we used a known distribution, and pulled 5, 10, 15, ..., 40 values from it to make
# a sample dataset
## We then used this dataset for a bootstrap simulation. We did this n.sim times
# for each dataset to get the upper and lower bounds. If the true median is
# in the bounds we stave that in coverage.indicator
## once we've finished the simulation, we use coverage.indicator to find the
# % of time that the true median was in the bounds, and save that in cov.prob

## In general, coverage probability gets higher and higher as the number of 
# samples increases, all reasonably close to expected coverage of .95,
# though slightly under. This is due to the inaccuracies of bootstrap sampling

## That took forever, due to the three nested loops. We can do way better by
# vectorizing the inner loop.
## This is the process of replacing nested loops by using vectors and matrices 
# to do the work of all the loops in a single batch
## you can also compile R into C++ code to make it far faster

start.time<- Sys.time()
library(robustbase)

sample.size<-seq(5, 40, 5) # 5, 10, 15, ..., 40
n.sim<-1000 # number of sims, used 1000 for previous time
B<-1000 # times to bootstrap
coverage.indicator<-rep(0, n.sim)
n.iter<-1

for (n in sample.size)
{
  for (j in 1:n.sim)
  {
    x<-rexp(n=n, rate=1)
    
    # instead of sampling B times, sample every dataset at once
    # this means making a 2d matrix, instead of a large number of 1d vectors
    x.boot<-matrix(data=sample(x=x, size=B*length(x), replace=TRUE),
                   nrow=length(x),
                   ncol=B)
    boot.interval<-quantile(colMedians(x.boot),
                             probs=c(0.025, 0.975))
    lower.median<-boot.interval[1]
    upper.median<-boot.interval[2]
    coverage.indicator[j]<-as.numeric((lower.median<=log(2))&&(log(2)<=upper.median))
  }
  cat('Completed for n = ', n, '\n')
  cov.prob[n.iter]<-mean(coverage.indicator)
  n.iter<-n.iter+1
}
end.time<-Sys.time()
time.taken2<-end.time - start.time

cov.prob
# [1] 0.939 0.935 0.917 0.942 0.938 0.937 0.947 0.940
time.taken2
# Time difference of 22.12879 secs

## By vectorizing, we got the same results but in 22 seconds instead of 5 minutes