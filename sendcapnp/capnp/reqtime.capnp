@0xf579124c13e046c8;

struct RequestTime {
    timezone @0 : Text;
}

struct ResponseTime {
    sec  @0 : Int32;
    nsec @1 : Int32;
}