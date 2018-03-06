## Cache Simulator
This is a course team project for computer architecture at Duke University.The purpose of this project is to develop a software cache simulator which can
have the similar behavior as real hardware cache. We run a couple of test cases on our own cache simulator and compare the result with DineroIV to
test the correctness of our simulator.

## Implementation Details
This cache simulator can mimic behavior of different combination of cache possiblity, including Unified cache(mix instruction cache and data cache
into one cache), Split Cache(separate instruction cache and data cache) and NONE (no cache at all). You can also specify number of cache levels up to two. For this simulator, we use write back strategy, which basically means dirty bit is involved when decide whether or not to evict an entry. If we have a cache write hit
We are going to set dirty bit to 1 and when that entry is later evicted, it needs to be written into the next level cache, if any.

*** NOTE: There is a policy called whether allocate memory on write miss. This means if we have write miss on level 1 cache, we have two options. One is to write this data into
next level directly(not allocate memory on write miss), or we can bring up the missing block from the lower level, and then modify the data in it, setting the dirty bit
to 1 eventually.***

We implement four common cache eviction policies: FIFO(First in First out), LRU(Least Recently Use), NMRU(Not Most Recently Use) and RND(Random)

## How to Run
To run this simulator, first git clone the repo. to your laptop and then type:
```
make
```
You should be able see generation of an executable file called my_sim. Then you can simply run the simulator by typing:
```
./my_sim
```
follow the instructions appearing on terminal to finish the setup of your cache configuration.

## About DineroIV
TO RUN DineroIV, enter `./dineroIV/d4-7` and then enter the following command:
```
./dineroIV -l1-isize 16384 -l1-iassoc 1 -l1-ibsize 32  -l1-dsize 16384 -l1-dbsize 32 -l1-dassoc 1  -l2-usize 262144 -l2-ubsize 64 -l2-uassoc 4 -informat d < ../../DineroFull.din
```

Hit Enter and wait for a few seconds, you will see the simulation result given by DineroIV, which should be the correct result of the second trace file (750 million)
