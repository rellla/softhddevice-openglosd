#ifndef __GLES_PRIVATE_H
#define __GLES_PRIVATE_H

#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <EGL/eglplatform.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <gbm.h>
#include <drm_fourcc.h>

/* Hack:
 * xlib.h via eglplatform.h: #define Status int
 * X.h via eglplatform.h: #define CurrentTime 0L
 *
 * revert it, because it conflicts with vdr variables.
 */
#undef Status
#undef CurrentTime

#ifdef __cplusplus
extern "C" {
#endif

//typedef char GLchar;

struct gbm {
    struct gbm_device *dev;
    struct gbm_bo *bo;
    struct gbm_surface *surface;
    uint32_t format;
    uint32_t flags;
    int width, height;
    EGLImage img;
    uint32_t gem_handle;
    uint32_t pitch;
    uint32_t offset;
    int dma_buf_fd;
};

#ifdef __cplusplus
}
#endif

#endif
