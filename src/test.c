#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "test.h"

// declare_vec(Failure);
//
// struct Report {
//   int pass;
//   struct Vec_Failure failures;
// };

// static void exec_test(struct Node *test, struct Report *report) {
static void exec_test(Test *test) {
  TestResult result = test->run();
  if (Result_is_ok(&result)) {
    putchar('.');
    // report->pass++;
  } /*else {
    Failure f = Result_unwrap_err(&result);
    // report->failures[0] = f;
  }*/
}

// static int run(struct List *tests, struct Report *report) {
static int run(Vec_Test *tests) {
  if (!tests->len) {
    printf("No tests found.\n\n");
    return 0;
  }

  Iterable_Test i = tests->vtable->iter(tests);
  Test *test = i.vtable->next(&i);
  while (test) {
    // exec_test(test, report);
    exec_test(test);
    test = i.vtable->next(&i);
  };

  // putchar('\n');
  return 0;
}

// // TODO: define these now so that tests will get registered & their bodies
// will
// // be called by Node->exec()
//
// // replace test w/ function that registers test onto an object
// // struct Node {
// //   struct Node *next;
// //   struct Node *prev;
// //   TestResult (*exec)();
// //   char *file;
// //   char *name;
// // };
// #define TEST(name, fn) \
//   _list_append(&root, { \
//                           .name = name, \
//                           .exec = fn, \
//                           .file = __FILE__, \
//                       })
//
// #define ASSERT(ast) \
//   // TODO: need to somehow give an id to this function? not sure what to
//   do...
// //   do { \
// //     assertion = #ast; \
// //     file = __FILE__; \
// //     line = __LINE__; \
// //     if (ast) { \
// //       putchar('.'); \
// //     } else { \
// //       putchar('F'); \
// //     } \
// //   } while (0)
