/**
 * @file: sw.h
 * @brief: header file with rpi2350 firmware/software parameters
 * @author: Kush Jain
 * @date: 10/01/2025
 */

#include <stdint.h>

typedef enum {
    RPM_SUCCESS = 0x0U,
    RPM_FAILURE = 0x1U
} rpm_status_t;

typedef uint8_t             (u8);
typedef uint16_t            (u16);
typedef uint32_t            (u32);
typedef uint64_t            (u64);

typedef uint32_t            (PStatus);