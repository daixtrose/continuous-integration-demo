TravisCI: [![Build Status](https://travis-ci.org/daixtrose/travisci-demo.svg?branch=master)](https://travis-ci.org/daixtrose/travisci-demo)

# travisci-demo
A demo project using TravisCI with C++ projects

## Manual Usage 

Retrieve this repository:

```bash
git clone --recursive https://github.com/daixtrose/travisci-demo
cd travisci-demo/
``` 
Then prepare it for a build:

```bash
mkdir build
cd build
cmake ..
```
Build it 

```bash
make
```
and test it:

```bash
make test
```
or
```bash
ctest -VV
```
for some detailed information.
