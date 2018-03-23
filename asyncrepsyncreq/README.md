# Introduction

REQ-ROUTER communication (sync client, async server) 
 * REQ port is synchronous (strict order of send() and recv())
 * ROUTER is asynchronous  (may multiple recv() calls before sending back any results)

## Requirements
- Installed ZMQ and CZMQ

```bash
sudo apt-get update
sudo apt-get install -y \
    git-all build-essential libtool \
    pkg-config autotools-dev autoconf automake cmake \
    uuid-dev libpcre3-dev valgrind

# only execute this next line if interested in updating the man pages as well (adds to build time):
sudo apt-get install -y asciidoc
```

```
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