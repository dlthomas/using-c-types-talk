

typedef struct { int v; } foo_index_t;
typedef struct { int v; } bar_index_t;
typedef struct { int v; } bid_price_t;

typedef struct foo_s { /* ... */ } foo_t;
typedef struct bar_s { /* ... */ } bar_t;

foo_t *lookup_foo(foo_index_t, foo_t *);
bar_t *lookup_bar(bar_index_t, bar_t *);

int do_the_thing(foo_index_t, bar_index_t, bid_price_t);














                                              /* David L. L. Thomas, Jan 2018 */




















