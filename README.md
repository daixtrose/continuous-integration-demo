TravisCI: [![Build Status](https://travis-ci.org/daixtrose/travisci-demo.svg?branch=master)](https://travis-ci.org/daixtrose/travisci-demo)

# TravisCI Demo

This project serves as an example for
- how to use [Google Test](https://github.com/google/googletest) for a C++ project 
  - This repo makes use of the CMake module [DownloadProject](https://github.com/Crascit/DownloadProject) in order to download [Google Test](https://github.com/google/googletest) on the fly
- how to configure [Travis CI](https://travis-ci.org/)

Hint: TravisCI can additionally be [configured not to run on commits in branches](https://stackoverflow.com/questions/31882306/how-to-configure-travis-ci-to-build-pull-requests-merges-to-master-w-o-redunda) unless those are under a pull request

Caveats: [Travis CI](https://travis-ci.org/) only knows the status **build** passing of failing, but this is misleading: A build failure is even reported in case the build succeeds and one single unit test fails. So I consider Travis CI to rather be a CD environment and not so much one for CI. 

Also the C++ integration is somewhat Tricky and at the time of this writing Travis uses Ubuntu-14.04 and version not 16.04 or higher, which adds extra headache with regard to the CMake version available. See how [others are installing a newer version of CMake before going on with the build](https://github.com/ericniebler/range-v3/blob/ce82f561d7dd7ed7286eee6135ca14ca9ed2375d/.travis.yml#L234). 

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
