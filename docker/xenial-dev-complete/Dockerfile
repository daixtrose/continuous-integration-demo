FROM ubuntu:16.04

MAINTAINER daixtrose

# http(s) and vnc for a noVNC connection
EXPOSE 80 443 5901 6080

ADD startup.sh /startup.sh
COPY ./keyboard /etc/default/keyboard

ENV TZ=Europe/London
RUN echo $TZ | tee /etc/timezone
RUN DEBIAN_FRONTEND=noninteractive apt-get update && apt-get install -y \
    tzdata 
RUN dpkg-reconfigure --frontend noninteractive tzdata

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



RUN DEBIAN_FRONTEND=noninteractive apt-get update && apt-get install -y \
#    build-essential \
#     clang-4.0 \
#     clang-tidy-4.0 \ 
#     gcc-6 \
#     g++-6 \
    git-core \  
#     libboost-all-dev \ 
#     make \
    && rm -rf /build/* \
    && rm -rf /tmp/* /var/tmp/* \
    && rm -rf /usr/share/doc/* \
    && rm -rf /var/lib/apt/lists/* 

RUN DEBIAN_FRONTEND=noninteractive apt-get update && apt-get install -y --no-install-recommends \
    ubuntu-desktop \
    gnome-panel \
    gnome-settings-daemon \
    metacity \
    nautilus \
    gnome-terminal \
    tightvncserver

RUN DEBIAN_FRONTEND=noninteractive apt-get update && apt-get install -y netstat

RUN chmod 0755 /startup.sh \
    && cd /root \
    && git clone https://github.com/novnc/noVNC  

# CMD /startup.sh