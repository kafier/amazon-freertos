/*
 * FreeRTOS V202011.00
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef HTTP_DEMO_S3_DOWNLOAD_MULTITHREADED_CONFIG_H
#define HTTP_DEMO_S3_DOWNLOAD_MULTITHREADED_CONFIG_H

/**************************************************/
/******* DO NOT CHANGE the following order ********/
/**************************************************/

/* Logging config definition and header files inclusion are required in the following order:
 * 1. Include the header file "logging_levels.h".
 * 2. Define the LIBRARY_LOG_NAME and LIBRARY_LOG_LEVEL macros depending on
 * the logging configuration for DEMO.
 * 3. Include the header file "logging_stack.h", if logging is enabled for DEMO.
 */

/* Include header that defines log levels. */
#include "logging_levels.h"

/* Logging configuration for the Demo. */
#ifndef LIBRARY_LOG_NAME
    #define LIBRARY_LOG_NAME    "HTTPDemo"
#endif

#ifndef LIBRARY_LOG_LEVEL
    #define LIBRARY_LOG_LEVEL    LOG_INFO
#endif

#include "logging_stack.h"

/************ End of logging configuration ****************/


/**
 * @brief HTTP server port number.
 *
 * In general, port 443 is for TLS HTTP connections.
 */
#ifndef democonfigHTTPS_PORT
    #define democonfigHTTPS_PORT    443
#endif

/**
 * @brief Server's root CA certificate for TLS authentication with S3.
 *
 * The Baltimore Cybertrust Root CA Certificate is defined below.
 *
 * @note This certificate should be PEM-encoded.
 *
 * Must include the PEM header and footer:
 * "-----BEGIN CERTIFICATE-----\n"\
 * "...base64 data...\n"\
 * "-----END CERTIFICATE-----\n"
 *
 */
#ifndef democonfigROOT_CA_PEM
    #define democonfigROOT_CA_PEM                                        \
    "-----BEGIN CERTIFICATE-----\n"                                      \
    "MIIDdzCCAl+gAwIBAgIEAgAAuTANBgkqhkiG9w0BAQUFADBaMQswCQYDVQQGEwJJ\n" \
    "RTESMBAGA1UEChMJQmFsdGltb3JlMRMwEQYDVQQLEwpDeWJlclRydXN0MSIwIAYD\n" \
    "VQQDExlCYWx0aW1vcmUgQ3liZXJUcnVzdCBSb290MB4XDTAwMDUxMjE4NDYwMFoX\n" \
    "DTI1MDUxMjIzNTkwMFowWjELMAkGA1UEBhMCSUUxEjAQBgNVBAoTCUJhbHRpbW9y\n" \
    "ZTETMBEGA1UECxMKQ3liZXJUcnVzdDEiMCAGA1UEAxMZQmFsdGltb3JlIEN5YmVy\n" \
    "VHJ1c3QgUm9vdDCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAKMEuyKr\n" \
    "mD1X6CZymrV51Cni4eiVgLGw41uOKymaZN+hXe2wCQVt2yguzmKiYv60iNoS6zjr\n" \
    "IZ3AQSsBUnuId9Mcj8e6uYi1agnnc+gRQKfRzMpijS3ljwumUNKoUMMo6vWrJYeK\n" \
    "mpYcqWe4PwzV9/lSEy/CG9VwcPCPwBLKBsua4dnKM3p31vjsufFoREJIE9LAwqSu\n" \
    "XmD+tqYF/LTdB1kC1FkYmGP1pWPgkAx9XbIGevOF6uvUA65ehD5f/xXtabz5OTZy\n" \
    "dc93Uk3zyZAsuT3lySNTPx8kmCFcB5kpvcY67Oduhjprl3RjM71oGDHweI12v/ye\n" \
    "jl0qhqdNkNwnGjkCAwEAAaNFMEMwHQYDVR0OBBYEFOWdWTCCR1jMrPoIVDaGezq1\n" \
    "BE3wMBIGA1UdEwEB/wQIMAYBAf8CAQMwDgYDVR0PAQH/BAQDAgEGMA0GCSqGSIb3\n" \
    "DQEBBQUAA4IBAQCFDF2O5G9RaEIFoN27TyclhAO992T9Ldcw46QQF+vaKSm2eT92\n" \
    "9hkTI7gQCvlYpNRhcL0EYWoSihfVCr3FvDB81ukMJY2GQE/szKN+OMY3EU/t3Wgx\n" \
    "jkzSswF07r51XgdIGn9w/xZchMB5hbgF/X++ZRGjD8ACtPhSNzkE1akxehi/oCr0\n" \
    "Epn3o0WC4zxe9Z2etciefC7IpJ5OCBRLbf1wbWsaY71k5h+3zvDyny67G7fyUIhz\n" \
    "ksLi4xaNmjICq44Y3ekQEe5+NauQrz4wlHrQMz2nZQ/1/I6eYs9HRCwBXbsdtTLS\n" \
    "R9I4LtD+gdwyah617jzV/OeBHRnDJELqYzmp\n"                             \
    "-----END CERTIFICATE-----\n"
#endif /* ifndef democonfigROOT_CA_PEM */

/**
 * @brief The pre-signed GET URL generated by the python script located in
 * demos/common/http_demo_helpers/presigned_url_generator/presigned_urls_gen.py
 *
 * @note This script requires AWS CLI to be configured. For instructions, see
 * https://docs.aws.amazon.com/cli/latest/userguide/cli-chap-configure.html
 *
 * Run this script and paste the output democonfigS3_PRESIGNED_GET_URL below.
 *
 * #define democonfigS3_PRESIGNED_GET_URL         "...insert here..."
 */

/**
 * @brief Transport timeout in milliseconds for transport send and receive.
 */
#define democonfigTRANSPORT_SEND_RECV_TIMEOUT_MS    ( 5000 )

/**
 * @brief The length in bytes of the user buffer.
 *
 * @note A portion of the user buffer will be used to store the response header,
 * so the length of the response body returned on any given range request will
 * be less than democonfigUSER_BUFFER_LENGTH. We don't expect S3 to send more
 * than 1024 bytes of headers.
 */
#define democonfigUSER_BUFFER_LENGTH                ( 2048 )

/**
 * @brief The size of the range of the file to download, with each request.
 *
 * @note This should account for the response headers that will also be stored
 * in the user buffer. We don't expect S3 to send more than 1024 bytes of
 * headers.
 */
#define democonfigRANGE_REQUEST_LENGTH              ( 1024 )

/**
 * @brief The number of items that can be held in each queue.
 */
#define democonfigQUEUE_SIZE                        ( 10 )


#endif /* ifndef HTTP_DEMO_S3_DOWNLOAD_MULTITHREADED_CONFIG_H */
