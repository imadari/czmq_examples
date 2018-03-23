# Introduction

[CZMQ](http://czmq.zeromq.org) is an awesome networking library with tons of useful functions. This repository aims to provide non-trivial examples how to squeeze more from the CZMQ API for your projects.

## Requirements

- Installed ZMQ and CZMQ
- Installed Cap'n proto

### Install ZMQ and CZMQ
```bash
sudo apt-get update
sudo apt-get install -y \
    git-all build-essential libtool \
    pkg-config autotools-dev autoconf automake cmake \
    uuid-dev libpcre3-dev valgrind

# only execute this next line if interested in updating the man pages as well (adds to build time):
sudo apt-get install -y asciidoc
```

```bash
git clone git://github.com/zeromq/libzmq.git
cd libzmq
./autogen.sh
# do not specify "--with-libsodium" if you prefer to use internal tweetnacl security implementation (recommended for development)
./configure --with-libsodium
make check
sudo make install
sudo ldconfig
cd ..

git clone git://github.com/zeromq/czmq.git
cd czmq
./autogen.sh && ./configure && make check
sudo make install
sudo ldconfig
cd ..
```

### Install Cap'n Proto

```bash
sudo apt install capnproto libcapnp-dev
```

# Example list
* asyncrepsyncreq: ZMQ_REQ - ZMQ_ROUTER communication example.
* sendcapnp: Serialize/deserialize, send/recv cap'n proto messages using ZMQ ports.

