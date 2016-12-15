/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _HWC2_TEST_BUFFER_H
#define _HWC2_TEST_BUFFER_H

#include <android-base/unique_fd.h>
#include <hardware/hwcomposer2.h>

#include <gui/GraphicBufferAlloc.h>
#include <ui/GraphicBuffer.h>

#include "Hwc2TestProperties.h"

class Hwc2TestFenceGenerator;

class Hwc2TestBuffer {
public:
    Hwc2TestBuffer();
    ~Hwc2TestBuffer();

    void updateBufferArea(const Area& bufferArea);

    int  get(buffer_handle_t* outHandle, int32_t* outFence);

protected:
    int generateBuffer();

    void setColor(int32_t x, int32_t y, android_pixel_format_t format,
            uint32_t stride, uint8_t* img, uint8_t r, uint8_t g, uint8_t b,
            uint8_t a);

    android::GraphicBufferAlloc mGraphicBufferAlloc;
    android::sp<android::GraphicBuffer> mGraphicBuffer;

    std::unique_ptr<Hwc2TestFenceGenerator> mFenceGenerator;

    Area mBufferArea = {-1, -1};
    const android_pixel_format_t mFormat = HAL_PIXEL_FORMAT_RGBA_8888;

    bool mValidBuffer = false;
    buffer_handle_t mHandle = nullptr;
};

#endif /* ifndef _HWC2_TEST_BUFFER_H */
