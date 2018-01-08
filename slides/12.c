
typedef struct { int v; } bid_price_t;
typedef struct { int v; } ask_price_t;



int is_crossed(bid_price_t bid, ask_price_t ask) {



	return bid.v >= ask.v;
}



