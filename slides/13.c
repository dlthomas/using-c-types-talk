
typedef struct { int v; } bid_price_t;
typedef struct { int v; } ask_price_t;



int is_crossed(bid_price_t bid_price, ask_price_t ask_price) {
	int bid = bid_price.v;
	int ask = ask_price.v;

	return bid >= ask;
}



