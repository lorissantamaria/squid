/*
 * Copyright (C) 1996-2015 The Squid Software Foundation and contributors
 *
 * Squid software is distributed under GPLv2+ license and includes
 * contributions from numerous individuals and organizations.
 * Please see the COPYING and CONTRIBUTORS files for details.
 */

#include "squid.h"

#if USE_OPENSSL

#include "fatal.h"

/* Stub File for the ssl/libsslsquid.la convenience library */

#define STUB_API "ssl/libsslsquid.la"
#include "tests/STUB.h"

#include "ssl/Config.h"
Ssl::Config::Config():
#if USE_SSL_CRTD
    ssl_crtd(NULL),
#endif
    ssl_crt_validator(NULL)
{
    ssl_crt_validator_Children.concurrency = 1;
    STUB_NOP
}
Ssl::Config::~Config() STUB_NOP
Ssl::Config Ssl::TheConfig;

#include "ssl/context_storage.h"
//Ssl::CertificateStorageAction::CertificateStorageAction(const Mgr::Command::Pointer &cmd) STUB
Ssl::CertificateStorageAction::Pointer Ssl::CertificateStorageAction::Create(const Mgr::Command::Pointer &cmd) STUB_RETSTATREF(Ssl::CertificateStorageAction::Pointer)
void Ssl::CertificateStorageAction::dump(StoreEntry *sentry) STUB
void Ssl::GlobalContextStorage::addLocalStorage(Ip::Address const & address, size_t size_of_store) STUB
Ssl::LocalContextStorage *Ssl::GlobalContextStorage::getLocalStorage(Ip::Address const & address)
{ fatal(STUB_API " required"); static Ssl::LocalContextStorage v(0,0); return &v; }
void Ssl::GlobalContextStorage::reconfigureStart() STUB
//Ssl::GlobalContextStorage Ssl::TheGlobalContextStorage;

#include "ssl/ErrorDetail.h"
Ssl::ssl_error_t parseErrorString(const char *name) STUB_RETVAL(0)
//const char *Ssl::getErrorName(ssl_error_t value) STUB_RETVAL(NULL)
Ssl::ErrorDetail::ErrorDetail(ssl_error_t err_no, X509 *, X509 *, const char *) STUB
Ssl::ErrorDetail::ErrorDetail(ErrorDetail const &) STUB
const String & Ssl::ErrorDetail::toString() const STUB_RETSTATREF(String)

#include "ssl/support.h"
namespace Ssl
{
//CertError::CertError(ssl_error_t anErr, X509 *aCert) STUB
//CertError::CertError(CertError const &err) STUB
CertError & CertError::operator = (const CertError &old) STUB_RETVAL(*this)
bool CertError::operator == (const CertError &ce) const STUB_RETVAL(false)
bool CertError::operator != (const CertError &ce) const STUB_RETVAL(false)
} // namespace Ssl
Security::ContextPtr sslCreateServerContext(AnyP::PortCfg &port) STUB_RETVAL(NULL)
Security::ContextPtr sslCreateClientContext(Security::PeerOptions &, long, const char *) STUB_RETVAL(nullptr)
int ssl_read_method(int, char *, int) STUB_RETVAL(0)
int ssl_write_method(int, const char *, int) STUB_RETVAL(0)
void ssl_shutdown_method(SSL *ssl) STUB
const char *sslGetUserEmail(SSL *ssl) STUB_RETVAL(NULL)
const char *sslGetUserAttribute(SSL *ssl, const char *attribute_name) STUB_RETVAL(NULL)
const char *sslGetCAAttribute(SSL *ssl, const char *attribute_name) STUB_RETVAL(NULL)
const char *sslGetUserCertificatePEM(SSL *ssl) STUB_RETVAL(NULL)
const char *sslGetUserCertificateChainPEM(SSL *ssl) STUB_RETVAL(NULL)
namespace Ssl
{
//GETX509ATTRIBUTE GetX509UserAttribute;
//GETX509ATTRIBUTE GetX509CAAttribute;
//GETX509ATTRIBUTE GetX509Fingerprint;
const char *BumpModeStr[] = {""};
bool generateUntrustedCert(Security::CertPointer & untrustedCert, EVP_PKEY_Pointer & untrustedPkey, Security::CertPointer const & cert, EVP_PKEY_Pointer const & pkey) STUB_RETVAL(false)
Security::ContextPtr generateSslContext(CertificateProperties const &properties, AnyP::PortCfg &port) STUB_RETVAL(NULL)
bool verifySslCertificate(Security::ContextPtr sslContext,  CertificateProperties const &properties) STUB_RETVAL(false)
Security::ContextPtr generateSslContextUsingPkeyAndCertFromMemory(const char * data, AnyP::PortCfg &port) STUB_RETVAL(NULL)
void addChainToSslContext(Security::ContextPtr sslContext, STACK_OF(X509) *certList) STUB
void readCertChainAndPrivateKeyFromFiles(Security::CertPointer & cert, EVP_PKEY_Pointer & pkey, X509_STACK_Pointer & chain, char const * certFilename, char const * keyFilename) STUB
int matchX509CommonNames(X509 *peer_cert, void *check_data, int (*check_func)(void *check_data,  ASN1_STRING *cn_data)) STUB_RETVAL(0)
bool checkX509ServerValidity(X509 *cert, const char *server) STUB_RETVAL(false)
int asn1timeToString(ASN1_TIME *tm, char *buf, int len) STUB_RETVAL(0)
bool setClientSNI(SSL *ssl, const char *fqdn) STUB_RETVAL(false)
void initialize_session_cache() STUB
void destruct_session_cache() STUB
} //namespace Ssl

#endif

