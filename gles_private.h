#ifndef __GLES_PRIVATE_H
#define __GLES_PRIVATE_H

#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <EGL/eglplatform.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#define GL_SURFACE_STATE_NV			0x86EB
#define GL_SURFACE_REGISTERED_NV		0x86FD
#define GL_SURFACE_MAPPED_NV			0x8700
#define GL_WRITE_DISCARD_NV			0x88BE
#define GL_READ_ONLY				0x88B8
#define GL_READ_WRITE				0x88BA

#define VDP_FUNC_ID_Init_NV			(uint32_t)100
#define VDP_FUNC_ID_Fini_NV			(uint32_t)101
#define VDP_FUNC_ID_RegisterVideoSurface_NV	(uint32_t)102
#define VDP_FUNC_ID_RegisterOutputSurface_NV	(uint32_t)103
#define VDP_FUNC_ID_IsSurface_NV		(uint32_t)104
#define VDP_FUNC_ID_UnregisterSurface_NV	(uint32_t)105
#define VDP_FUNC_ID_GetSurfaceiv_NV		(uint32_t)106
#define VDP_FUNC_ID_SurfaceAccess_NV		(uint32_t)107
#define VDP_FUNC_ID_MapSurfaces_NV		(uint32_t)108
#define VDP_FUNC_ID_UnmapSurfaces_NV		(uint32_t)109

#ifdef __cplusplus
extern "C" {
#endif

typedef char GLchar;

typedef GLintptr GLvdpauSurfaceNV;

typedef void (*GLVDPAUInitNV)(const void *vdpDevice,
		   const GLvoid *getProcAddress,
		   EGLContext shared_context,
		   EGLDisplay shared_display);

typedef void (*GLVDPAUFiniNV)(void);

typedef GLvdpauSurfaceNV (*GLVDPAURegisterVideoSurfaceNV)(const void *vdpSurface,
					   GLenum target,
					   GLsizei numTextureNames,
					   const GLuint *textureNames);

typedef GLvdpauSurfaceNV (*GLVDPAURegisterOutputSurfaceNV)(const void *vdpSurface,
					    GLenum target,
					    GLsizei numTextureNames,
					    const GLuint *textureNames);

typedef GLboolean (*GLVDPAUIsSurfaceNV)(GLvdpauSurfaceNV surface);

typedef void (*GLVDPAUUnregisterSurfaceNV)(GLvdpauSurfaceNV surface);

typedef void (*GLVDPAUGetSurfaceivNV)(GLvdpauSurfaceNV surface,
			   GLenum pname,
			   GLsizei bufSize,
			   GLsizei *length,
			   GLint *values);

typedef void (*GLVDPAUSurfaceAccessNV)(GLvdpauSurfaceNV surface,
			    GLenum access);

typedef void (*GLVDPAUMapSurfacesNV)(GLsizei numSurfaces,
			  const GLvdpauSurfaceNV *surfaces);

typedef void (*GLVDPAUUnmapSurfacesNV)(GLsizei numSurfaces,
			   const GLvdpauSurfaceNV *surfaces);

#ifdef __cplusplus
}
#endif

#endif
