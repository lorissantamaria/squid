/*
 * $Id$
 *
 *
 * SQUID Web Proxy Cache          http://www.squid-cache.org/
 * ----------------------------------------------------------
 *
 *  Squid is the result of efforts by numerous individuals from
 *  the Internet community; see the CONTRIBUTORS file for full
 *  details.   Many organizations have provided support for Squid's
 *  development; see the SPONSORS file for full details.  Squid is
 *  Copyrighted (C) 2001 by the Regents of the University of
 *  California; see the COPYRIGHT file for full details.  Squid
 *  incorporates software developed and/or copyrighted by other
 *  sources; see the CREDITS file for full details.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.
 *
 */

#ifndef SQUID_AUTH_BASIC_SCHEME_H
#define SQUID_AUTH_BASIC_SCHEME_H

#include "auth/Scheme.h"
#include "auth/basic/auth_basic.h"

namespace Auth {
namespace Basic {

/// \ingroup AuthAPI
/// \ingroup AuthSchemeAPI
class Scheme : public AuthScheme
{

public:
    static AuthScheme::Pointer GetInstance();
    Scheme() {};
    virtual ~Scheme() {}

    /* per scheme */
    virtual char const *type() const;
    virtual void done();
    virtual AuthConfig *createConfig();
    /* Not implemented */
    Scheme(Scheme const &);
    Scheme &operator=(Scheme const &);

private:
    static AuthScheme::Pointer _instance;
};

} // namespace Basic
} // namespace Auth

#endif /* SQUID_AUTH_BASIC_SCHEME_H */
