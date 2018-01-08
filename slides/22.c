
#define TH(THREAD_NAME) THREAD_NAME##_thread_t th __attribute__((unused))

typedef struct main_thread_s { /* int unused; */ } main_thread_t;
typedef struct other_thread_s { /* int unused; */ } other_thread_t;


int bar(TH(main));

int foo(TH(main)) {
	return bar(th);
}

/*
int qux(TH(other)) {
	return bar(th);
}
*/
