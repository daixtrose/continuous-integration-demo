FROM ubuntu:16.04

MAINTAINER daixtrose

LABEL \
    URL="https://github.com/daixtrose/continuous-integration-demo"

RUN apt-get update && apt-get install -y --no-install-recommends apt-utils

RUN DEBIAN_FRONTEND=noninteractive \
    apt-get install -y apt-utils software-properties-common \
    && add-apt-repository ppa:ubuntu-toolchain-r/test 

RUN DEBIAN_FRONTEND=noninteractive apt-get install -y curl sudo 

RUN curl -sSL https://cmake.org/files/v3.9/cmake-3.9.1-Linux-x86_64.tar.gz | sudo tar -xzC /opt
ENV PATH="/opt/cmake-3.9.1-Linux-x86_64/bin:$PATH"

RUN curl http://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add - \
    && echo "deb http://apt.llvm.org/xenial/ llvm-toolchain-xenial-4.0 main" > /etc/apt/sources.list.d/clang4.list 

RUN DEBIAN_FRONTEND=noninteractive apt-get update 
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y git-core
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y libboost-all-dev 
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y clang-4.0 
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y gcc-6 
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y g++-6 
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y clang-tidy-4.0 
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y make 

RUN rm -rf /build/* \
    && rm -rf /tmp/* /var/tmp/* \
    && rm -rf /usr/share/doc/* \
    && rm -rf /var/lib/apt/lists/* 
