# 3050A2 yso02
Portability
- #ifdef was used to detec which platform currently working on
- unix, linux, windows all three had different syntax for makefile so script was ran to run correspondin makefiles
- unix and linux used .so dynamic library where Windows used

Memory Management
- Ran valgrind to detec any memory errors and leaks
- Closed opening of directory or opening of dynamic library. Also cleaned up any buffer variable that was used to get functionality working

TESTING

*** I created my own makefile for each platform so it is slightly different than others.
- First, make sure you clean eveything by doing [make clean] and [./mk clean] this will clean any library that is in this directory
- Second, run ./mk to generate all dynamic library!
- Third, run make to run all the source files for the project
- Now you can run test by typing make test
- make test will run all 4 test cases.
- you can physically check the outpued file in test/result/ directory
