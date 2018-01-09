








typedef struct { int v; } bid_price_t;
typedef struct { int v; } ask_price_t;

int make_market(bid_price_t, ask_price_t);


int test(void) {
	
	/* requires C99 or newer */

	return make_market(
		(bid_price_t) { 1 },
		(ask_price_t) { 3 });
}




                                              /* David L. L. Thomas, Jan 2018 */




















