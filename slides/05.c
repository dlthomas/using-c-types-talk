
typedef int bid_price_t;
typedef int ask_price_t;

int make_market(bid_price_t, ask_price_t);


int test(void) {
	bid_price_t bid = 1;
	ask_price_t ask = 3;

	return make_market(ask, bid);


}



