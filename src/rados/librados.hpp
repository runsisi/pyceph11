#ifndef __LIBRADOS_HPP
#define __LIBRADOS_HPP

#include <string>

#include "librados.h"

#define CEPH_RADOS_API

typedef void *config_t;

namespace librados {

  class CEPH_RADOS_API IoCtx
  {
  public:
    IoCtx() {}
    static void from_rados_ioctx_t(rados_ioctx_t p, IoCtx &pool) {}
    IoCtx(const IoCtx& rhs) {}
    IoCtx& operator=(const IoCtx& rhs) {}
    IoCtx(IoCtx&& rhs) noexcept {}
    IoCtx& operator=(IoCtx&& rhs) noexcept {}

    ~IoCtx() {}

    bool is_valid() const {}

    // Close our pool handle
    void close() {}

    void set_namespace(const std::string& nspace) {}
    std::string get_namespace() const {}

    int64_t get_id() {}
    config_t cct() {}
  };

  class CEPH_RADOS_API Rados
  {
  public:
    Rados() {}
    explicit Rados(IoCtx& ioctx) {}
    ~Rados() {}
    static void from_rados_t(rados_t cluster, Rados &rados) {}

    int init(const char * const id) {}
    int init2(const char * const name, const char * const clustername,
	      uint64_t flags) {}
    int init_with_context(config_t cct_) {}

    config_t cct() {}

    int connect() {}
    void shutdown() {}

    int conf_read_file(const char * const path) const {}
    int conf_set(const char *option, const char *value) {}

    int ioctx_create(const char *name, IoCtx &pioctx) {}
    int ioctx_create2(int64_t pool_id, IoCtx &pioctx) {}
  };

} // namespace librados

#endif

