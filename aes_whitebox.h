// Copyright 2019 AES WBC Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef AES_WHITEBOX_H_
#define AES_WHITEBOX_H_

#include <cstdint>
#include <cstddef>

class AESImpl;

class AES {
  AESImpl* impl_;

public:
  AES(int Nr,
      const uint8_t Xor[9][96][16][16],
      const uint32_t Tyboxes[9][16][256],
      const uint8_t TboxesLast[16][256],
      const uint32_t MBL[9][16][256]);
  ~AES();

  bool EncodeCBC(const uint8_t iv[16], const uint8_t* m, size_t len, uint8_t* c);
  bool DecodeCBC(const uint8_t iv[16], const uint8_t* c, size_t len, uint8_t* m);
};

#endif  // AES_WHITEBOX_H_
