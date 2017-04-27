#include <archive.h>
#include <archive_entry.h>
#include "Rcpp.h"

#define class class_name
#define private private_ptr
#include <R_ext/Connections.h>
#undef class
#undef private

#if R_CONNECTIONS_VERSION != 1
#error "Missing or unsupported connection API in R"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef struct {
  char* archive_filename;
  int format;
  int filter[5];
  size_t num_filters;
  char* filename;
  char* buf;
  char* cur;
  archive *ar;
  archive_entry *entry;
  int last_response;
  int has_more;
  size_t limit;
  size_t size;
} rchive;

size_t pop(void *target, size_t max, rchive *r);

void copy_data(rchive *r);

#if ARCHIVE_VERSION_NUMBER < 3001000
int archive_write_add_filter(struct archive *a, int code);
#endif

#ifdef __cplusplus
}
#endif
