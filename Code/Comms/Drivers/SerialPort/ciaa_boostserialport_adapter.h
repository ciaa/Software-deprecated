//Sun Apr 27 23:20:13 CDT 2014

#include "Code/Comms/Drivers/ciaa_comm_adapter_interface.h"

class ciaaBoostSerialPortAdapter : public ciaaCommAdapterInterface {
 public:
  explicit ciaaBoostSerialPortAdapter(std::string device);
  ~ciaaBoostSerialPortAdapter() = default;

  ciaaBoostSerialPortAdapter(const ciaaBoostSerialPortAdapter&) = delete;
  ciaaBoostSerialPortAdapter& operator=(const ciaaBoostSerialPortAdapter&) = delete;

  ciaaBoostSerialPortAdapter(const ciaaBoostSerialPortAdapter&&) = delete;
  ciaaBoostSerialPortAdapter& operator=(
      const ciaaBoostSerialPortAdapter&&) = delete;

  CommDriverErrorCode connect(std::int32_t timeout) override {
    CIAA_UNUSED_PARAM(timeout);
    return CommDriverErrorCode::OK;
  }

  CommDriverErrorCode disconnect(std::int32_t timeout) override {
    CIAA_UNUSED_PARAM(timeout);
    return CommDriverErrorCode::OK;
  }
  CommDriverErrorCode read(std::int32_t timeout,
                           char *data,
                           ciaa_size_t *n_bytes) override {
    CIAA_UNUSED_PARAM(timeout);
    CIAA_UNUSED_PARAM(n_bytes);
    CIAA_UNUSED_PARAM(data);
    return CommDriverErrorCode::OK;
  }

  CommDriverErrorCode write(std::int32_t timeout,
                            const char *data,
                            ciaa_size_t *n_bytes) override {
    CIAA_UNUSED_PARAM(timeout);
    CIAA_UNUSED_PARAM(n_bytes);
    CIAA_UNUSED_PARAM(data);
    return CommDriverErrorCode::OK;
  }

 // boost::asio::io_service serial_;
};
