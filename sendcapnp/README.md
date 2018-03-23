# Introduction

When complex structures are involved in the communication, the CZMQ message (`zmsg_t`) might not enough. [Cap'n Proto](https://capnproto.org/) is a very fast, platform indepentent serialization format which works smoothly with CZMQ. In this example you can see how to serialize Cap'n proto structures, send through a ZMQ port and deserialize the data.

## Requirements
- ZMQ, CZMQ
- Cap'n Proto

# Recompile the Cap'n Proto schema

If you modify the capnp schema, you have to regenerate the .c++ and .h files.

```bash
cd sendcapnp/capnp
capnp compile -oc++ ./reqtime.capnp
``` 