



typedef struct main_thread_s { /* int unused; */ } main_thread_t;
typedef struct other_thread_s { /* int unused; */ } other_thread_t;


int bar(main_thread_t);

int foo(main_thread_t th) {
	return bar(th);
}


int qux(other_thread_t th) {
	return bar(th);
}









                                              /* David L. L. Thomas, Jan 2018 */




















