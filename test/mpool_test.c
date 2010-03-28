#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <inttypes.h>
#include <sys/types.h>
#include <time.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <mpool.h>

static void mpool_test001(void);
static void mpool_test002(void);
static void mpool_test003(void);
static void mpool_test004(void);
static void mpool_test005(void);

static void mpool_test001(void){
  mpool_t *pool = mpool_create(0);
  char *c;
  c = mpool_alloc(&pool, sizeof(*c));
  *c = 'a';
  CU_ASSERT(*c == 'a');
  mpool_destroy(pool);
}

static void mpool_test002(void){
  mpool_t *pool = mpool_create(1);
  char *c1;
  char *c2;
  char *c3;
  char *c4;
  char *c5;
  c1 = mpool_alloc(&pool, sizeof(*c1));
  c2 = mpool_alloc(&pool, sizeof(*c2));
  c3 = mpool_alloc(&pool, sizeof(*c3));
  c4 = mpool_alloc(&pool, sizeof(*c4));
  c5 = mpool_alloc(&pool, sizeof(*c5));
  *c1 = 'a';
  *c2 = 'b';
  *c3 = 'c';
  *c4 = 'd';
  *c5 = 'e';
  CU_ASSERT(*c1 == 'a');
  CU_ASSERT(*c2 == 'b');
  CU_ASSERT(*c3 == 'c');
  CU_ASSERT(*c4 == 'd');
  CU_ASSERT(*c5 == 'e');
  mpool_destroy(pool);
}

static void mpool_test003(void){
  mpool_t *pool = mpool_create(0);
  bool               *b;
  short              *s;
  char               *c;
  unsigned char      *uc;
  int                *n;
  unsigned int       *un;
  long               *l;
  unsigned long      *ul;
  long long          *ll;
  unsigned long long *ull;
  float              *f;
  double             *d;
  long double        *ld;
  time_t             *t;
  off_t              *ot;
  intptr_t           *ipt;
  size_t             *siz;
  ptrdiff_t          *pdt;
  
  b   = mpool_alloc(&pool, sizeof(*b));
  s   = mpool_alloc(&pool, sizeof(*s));
  c   = mpool_alloc(&pool, sizeof(*c));
  uc  = mpool_alloc(&pool, sizeof(*uc));
  n   = mpool_alloc(&pool, sizeof(*n));
  un  = mpool_alloc(&pool, sizeof(*un));
  l   = mpool_alloc(&pool, sizeof(*l));
  ul  = mpool_alloc(&pool, sizeof(*ul));
  ll  = mpool_alloc(&pool, sizeof(*ll));
  ull = mpool_alloc(&pool, sizeof(*ull));
  f   = mpool_alloc(&pool, sizeof(*f));
  d   = mpool_alloc(&pool, sizeof(*d));
  ld  = mpool_alloc(&pool, sizeof(*ld));
  t   = mpool_alloc(&pool, sizeof(*t));
  ot  = mpool_alloc(&pool, sizeof(*ot));
  ipt = mpool_alloc(&pool, sizeof(*ipt));
  siz = mpool_alloc(&pool, sizeof(*siz));
  pdt = mpool_alloc(&pool, sizeof(*pdt));

  *b   = true;
  *s   = 2;
  *c   = 'a';
  *uc  = 'b';
  *n   = 5;
  *un  = 255;
  *l   = 550;
  *ul  = 333;
  *ll  = 950;
  *ull = 111;
  *f   = 113.5;
  *d   = 50.8;
  *ld  = 115.3;
  *t   = 123;
  *ot  = 22;
  *ipt = 33;
  *siz = 55;
  *pdt = 150;
  
  CU_ASSERT(*b   == true);
  CU_ASSERT(*s   == 2);
  CU_ASSERT(*c   == 'a');
  CU_ASSERT(*uc  == 'b');
  CU_ASSERT(*n   == 5);
  CU_ASSERT(*un  == 255);
  CU_ASSERT(*l   == 550);
  CU_ASSERT(*ul  == 333);
  CU_ASSERT(*ll  == 950);
  CU_ASSERT(*ull == 111);
  CU_ASSERT(*f   == 113.5);
  CU_ASSERT(*d   == 50.8);
  CU_ASSERT(*ld  == 115.3);
  CU_ASSERT(*t   == 123);
  CU_ASSERT(*ot  == 22);
  CU_ASSERT(*ipt == 33);
  CU_ASSERT(*siz == 55);
  CU_ASSERT(*pdt == 150);
  
  mpool_destroy(pool);
}

static void mpool_test004(void){
  mpool_t *pool = mpool_create(13);
  const char *cs[] = {"cubicdaiya", "bokko"};
  char *s1;
  char *s2;

  s1 = mpool_alloc(&pool, strlen(cs[0]) + 1);
  s2 = mpool_alloc(&pool, strlen(cs[1]) + 1);
  strcpy(s1, cs[0]);
  strcpy(s2, cs[1]);
  CU_ASSERT(strncmp(s1, cs[0], strlen(s1)) == 0);
  CU_ASSERT(strncmp(s2, cs[1], strlen(s2)) == 0);
  
  mpool_destroy(pool);
}

static void mpool_test005(void){
  mpool_t *pool = mpool_create(2);
  
  typedef struct st_s {
    int  n;
    char c;
  } st_t;
  
  st_t *st;
  int *n;
  st = mpool_alloc(&pool, sizeof(*st));
  n  = mpool_alloc(&pool, sizeof(*n));
  
  st->n = 5;
  st->c = 'a';
  *n     = 10;

  CU_ASSERT(st->n == 5);
  CU_ASSERT(st->c == 'a');
  CU_ASSERT(*n     == 10);
  
  mpool_destroy(pool);
}

int main (int argc, char *argv[]) {
  CU_pSuite suite_mpool;
  CU_initialize_registry();
  suite_mpool = CU_add_suite("mpool", NULL, NULL);
  CU_add_test(suite_mpool, "mpool_test001", mpool_test001);
  CU_add_test(suite_mpool, "mpool_test002", mpool_test002);
  CU_add_test(suite_mpool, "mpool_test003", mpool_test003);
  CU_add_test(suite_mpool, "mpool_test004", mpool_test004);
  CU_add_test(suite_mpool, "mpool_test005", mpool_test005);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return 0;
}