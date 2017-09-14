FROM jenkins/jenkins:lts
#FROM ubuntu:16.04

MAINTAINER daixtrose

LABEL \
    URL="https://github.com/daixtrose/continuous-integration-demo"

# Install packages via apt
USER root


RUN DEBIAN_FRONTEND=noninteractive \
    && apt-get update \
    && apt-get install -y apt-utils curl software-properties-common 

# RUN gpg --export --armor 1E9377A2BA9EF27F | apt-key add - \
#    && gpg --keyserver keyserver.ubuntu.com --recv-keys 1E9377A2BA9EF27F \
#    && add-apt-repository ppa:ubuntu-toolchain-r/test 
    

# RUN apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 1E9377A2BA9EF27F \
#    && add-apt-repository ppa:ubuntu-toolchain-r/test 

RUN gpg --keyserver hkp://keyserver.ubuntu.com:80 --recv 1E9377A2BA9EF27F \
    && gpg --export --armor 1E9377A2BA9EF27F | sudo apt-key add -

RUN curl -sSL https://cmake.org/files/v3.9/cmake-3.9.1-Linux-x86_64.tar.gz | tar -xzC /opt
ENV PATH="/opt/cmake-3.9.1-Linux-x86_64/bin:$PATH"

RUN curl https://apt.llvm.org/llvm-snapshot.gpg.key > /tmp/llvm-snapshot.gpg.key \
    && apt-key add /tmp/llvm-snapshot.gpg.key \
    && add-apt-repository "deb http://apt.llvm.org/xenial/ llvm-toolchain-xenial-5.0 main"

RUN DEBIAN_FRONTEND=noninteractive apt-get update \
    && apt-get install -y \
#        clang-5.0 \
#        clang-tidy-5.0 \
        g++-6 \
        gcc-6 \
        git-core \ 
        libboost-all-dev \
        make \
    && rm -rf /build/* \
    && rm -rf /tmp/* /var/tmp/* \
    && rm -rf /usr/share/doc/* \
    && rm -rf /var/lib/apt/lists/* 

RUN /usr/local/bin/install-plugins.sh github-pullrequest github-oauth 
#    github-branch-source:1.8


# drop back to the regular jenkins user - good practice
USER jenkins