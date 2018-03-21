REQ-ROUTER communication (sync client, async server) 
 * REQ port is synchronous (strict order of send() and recv())
 * ROUTER is asynchronous  (may multiple recv() calls before sending back any results)