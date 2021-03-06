/*
 * Copyright (c) 2019 - 2021 Elastos Foundation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef __DID_H__
#define __DID_H__

#include "ela_did.h"
#include "didmeta.h"
#include "credmeta.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_ID_SPECIFIC_STRING          48
#define MAX_FRAGMENT                    48

struct DID {
    char idstring[MAX_ID_SPECIFIC_STRING];
    DIDMetadata metadata;
};

struct  DIDURL {
    DID did;
    char fragment[MAX_FRAGMENT];
    CredentialMetadata metadata;
};

int DID_Parse(DID *did, const char *idstring);
int DID_Init (DID *did, const char *idstring);
DID *DID_Copy(DID *dest, DID *src);

int DIDURL_Parse(DIDURL *id, const char *idstring, DID *base);
//caller provide DIDURL object
int DIDURL_Init(DIDURL *id, DID *did, const char *fragment);
int DIDURL_InitFromString(DIDURL *id, const char *idstring, const char *fragment);
DIDURL *DIDURL_Copy(DIDURL *dest, DIDURL *src);

bool Contains_DID(DID **dids, size_t size, DID *did);

#ifdef __cplusplus
}
#endif

#endif //__DID_H__