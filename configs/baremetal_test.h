/**
 * \file baremetal_test.h
 *
 * \brief This file contains minimal modifications to the
 *        baremetal configuration `baremetal.h` which allows
 *        example programs to compile and run.
 *
 *        It should be used as the `MBEDTLS_USER_CONFIG_FILE`
 *        in builds using `baremetal.h`.
 */
/*
 *  Copyright (C) 2006-2018, ARM Limited, All Rights Reserved
 *  SPDX-License-Identifier: Apache-2.0
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may
 *  not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  This file is part of mbed TLS (https://tls.mbed.org)
 */

#ifndef MBEDTLS_BAREMETAL_USER_CONFIG_H
#define MBEDTLS_BAREMETAL_USER_CONFIG_H

/* We need test CRTs to be able to run ssl_client2 and ssl_server2. */
#define MBEDTLS_CERTS_C
/* For the network context used by ssl_client2 and ssl_server2. */
#define MBEDTLS_NET_C
/* Debug output */
#define MBEDTLS_DEBUG_C

/* We don't have DER-encoded test CRTs yet. */
#define MBEDTLS_PEM_PARSE_C
#define MBEDTLS_BASE64_C
/* We don't have Secp256r1 test CRTs at the moment. */
#define MBEDTLS_ECP_DP_SECP384R1_ENABLED

/* Correct ECP configuration values */
#undef MBEDTLS_ECP_MAX_BITS
#undef MBEDTLS_MPI_MAX_SIZE
#define MBEDTLS_ECP_MAX_BITS 384
#define MBEDTLS_MPI_MAX_SIZE 48

/* ssl_client2 and ssl_server2 use CTR-DRBG so far. */
#define MBEDTLS_CTR_DRBG_C
#undef MBEDTLS_SSL_CONF_RNG
#define MBEDTLS_SSL_CONF_RNG mbedtls_ctr_drbg_random

/* The ticket implementation hardcodes AES-GCM */
#define MBEDTLS_GCM_C

/* Use Mbed TLS' timer implementation for Linux. */
#define MBEDTLS_TIMING_C

#undef MBEDTLS_NO_PLATFORM_ENTROPY

#endif /* MBEDTLS_BAREMETAL_USER_CONFIG_H */