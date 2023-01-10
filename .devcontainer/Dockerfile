# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.245.0/containers/cpp/.devcontainer/base.Dockerfile

# [Choice] Debian / Ubuntu version (use Debian 11, Ubuntu 18.04/22.04 on local arm64/Apple Silicon): debian-11, debian-10, ubuntu-22.04, ubuntu-20.04, ubuntu-18.04
ARG VARIANT="bullseye"
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}

# [Optional] Install CMake version different from what base image has already installed. 
# CMake reinstall choices: none, 3.21.5, 3.22.2, or versions from https://cmake.org/download/
ARG REINSTALL_CMAKE_VERSION_FROM_SOURCE="none"

# Optionally install the cmake for vcpkg
COPY ./reinstall-cmake.sh /tmp/
RUN if [ "${REINSTALL_CMAKE_VERSION_FROM_SOURCE}" != "none" ]; then \
        chmod +x /tmp/reinstall-cmake.sh && /tmp/reinstall-cmake.sh ${REINSTALL_CMAKE_VERSION_FROM_SOURCE}; \
    fi \
    && rm -f /tmp/reinstall-cmake.sh

# [Optional] Uncomment this section to install additional vcpkg ports.
# RUN su vscode -c "${VCPKG_ROOT}/vcpkg install <your-port-name-here>"

# [Optional] Uncomment this section to install additional packages.
RUN dpkg --add-architecture i386 && apt-get update && apt-get -y --no-install-recommends install \
    ca-certificates \
    curl \
    python2.7 \
    bison;

RUN ln -s /usr/bin/python2.7 /usr/bin/python; \
    curl -fsSL https://bootstrap.pypa.io/pip/2.7/get-pip.py -o /tmp/get-pip.py && \
    python get-pip.py && \
    pip2 install --no-cache-dir argcomplete==1.12.3; \
    rm -rf /tmp/* /var/tmp/*;

RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends autoconf automake texinfo libgmp-dev libmpfr-dev libmpc-dev libisl-dev flex

WORKDIR /tmp

RUN git clone https://github.com/jca02266/lha.git && \
    mkdir build && \
    cd lha || exit && \
    autoreconf -vfi && \
    cd ../build && \
    ../lha/configure --prefix=/usr && \
    make && \
    make install;