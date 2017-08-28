TravisCI: [![Build Status](https://travis-ci.org/daixtrose/travisci-demo.svg?branch=master)](https://travis-ci.org/daixtrose/travisci-demo)

# Continuous Integration Demo

This project serves as an example for
- how to use [Google Test](https://github.com/google/googletest) for a C++14 project 
  - This repo makes use of the CMake module [DownloadProject](https://github.com/Crascit/DownloadProject) in order to download and build [Google Test](https://github.com/google/googletest) on the fly 
- how to use the [Catch Unit Test Framework](https://github.com/philsquared/Catch)
- how to configure [Travis CI](https://travis-ci.org/)
  - Hint: TravisCI can additionally be [configured not to run on commits in branches](https://stackoverflow.com/questions/31882306/how-to-configure-travis-ci-to-build-pull-requests-merges-to-master-w-o-redunda) unless those are under a pull request
  - Caveats: [Travis CI](https://travis-ci.org/) only knows the status `build passing` or `build failing`, but this is misleading: A build failure is even reported in case the build succeeds and one single unit test fails. So I consider Travis CI to be a Continuous Deployment environment in the first place - with CI capability, of course. 
  - Comment: IMHO the C++ integration is somewhat tricky. At the time of this writing (August 2017) Travis uses Ubuntu-14.04 (not version 16.04 or higher) which adds extra headache with regard to the available CMake version. See how [others are installing a newer version of CMake before going on with the build](https://github.com/ericniebler/range-v3/blob/ce82f561d7dd7ed7286eee6135ca14ca9ed2375d/.travis.yml#L234). 
- how to configure [Circle CI](https://circleci.com/)

## Make a Duplicate

If you want to use this code in your own project, please follow the advice on [how to make a duplicate](https://help.github.com/articles/duplicating-a-repository/). In short:

```
git clone --bare https://github.com/daixtrose/continuous-integration-demo.git
cd continuous-integration-demo.git
git push --mirror https://github.com/youraccount/new-repository.git
```

## Manual Usage 

Retrieve this repository:

```bash
git clone --recursive https://github.com/daixtrose/continuous-integration-demo
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
