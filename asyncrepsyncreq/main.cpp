/**
 * REQ-ROUTER communication (sync client, async server)
 * 
 * REQ port is synchronous (strict order of send() and recv())
 * ROUTER is asynchronous  (may multiple recv() calls before sending back any results)
 * 
 * In order to send a message back to the client, the ROUTER port must distiungish between the conencted client.
 * ZMQ automatically inserts an IDENTITY frame before the message leaves the client. The ROUTER side must save this identity,
 * and must put back in the response to correctly route the message.
 * 
 * The identity can be set on the REQ side by calling the set_identity() function.
 * If the set_identity is not called on the REQ, a random identity is generated by ZMQ.
 *
 * When a message arrives from a REQ port, the ROUTER gets the following frames:
 *
 * +---+----------+
 * | 0 | IDENTITY |
 * +---+----------+
 * | 1 |   EMPTY  |
 * +---+----------+
 * | 2 | THE LOAD |
 * +---+----------+
 *
 * For the correct routing, the same message structure (with the appropriate identity) must be sent back on the router.
 *
 * @author Istvan Madari
 */

#include <iostream>
#include <czmq.h>

int main(int, char**)
{
    zsock_t* router = zsock_new(ZMQ_ROUTER);
    zsock_t* req    = zsock_new(ZMQ_REQ);

    /**
     * Binding and connect, withou calling the set_identity(). Random id will be generated.
     */
    zsock_bind(router, "tcp://127.0.0.1:1234");
    zsock_connect(req, "tcp://127.0.0.1:1234");

    /**
     * Send a message through the REQ port
     */
    {
        zmsg_t *mOut;
        mOut = zmsg_new();
        zmsg_addstr(mOut, "String from REQ");
        zmsg_send(&mOut, req);
    }

    /**
     * Read the message from the ROUTER and
     * save the identity frame
     */
    zframe_t *reqId = nullptr;
    {
        zmsg_t *msgIn = nullptr;
        msgIn = zmsg_recv(router);
        reqId = zmsg_pop(msgIn);
        char *empty = zmsg_popstr(msgIn);
        char *load = zmsg_popstr(msgIn);

        /**
         * Print the identity frame
         */
        zframe_print(reqId, "");

        zstr_free(&empty);
        zstr_free(&load);
        zmsg_destroy(&msgIn);
    }

    /**
     * Create the response and send back.
     * The response starts with the identity frame followed by an empty string.
     */
    {
        zmsg_t *mOut = zmsg_new();
        zmsg_add(mOut, reqId);
        zmsg_addstr(mOut, "");
        zmsg_addstr(mOut, "String from ROUTER");

        zmsg_send(&mOut, router);
    }

    /**
     * Get the response from the ROUTER.
     */
    {
        zmsg_t* msgIn = zmsg_recv(req);
        zframe_t *frRep = zmsg_pop(msgIn);

        /**
         * Just the load will be seen, the REQ port consumes the first two frames.
         */
        while (frRep != nullptr) {
            zframe_print(frRep, "");
            zframe_destroy(&frRep);
            frRep = zmsg_pop(msgIn);
        }
        zmsg_destroy(&msgIn);
    }

    zsock_destroy(&req);
    zsock_destroy(&router);
}
