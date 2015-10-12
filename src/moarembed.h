#ifndef MOAREMBED_H_
#define MOAREMBED_H_

#define MVM_EMBED_VERSION 1

#ifdef MVM_STATIC_INLINE
#define MVM_EMBED_STATIC_INLINE MVM_STATIC_INLINE
#elif defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L
#define MVM_EMBED_STATIC_INLINE static inline
#elif defined __GNUC__
#define MVM_EMBED_STATIC_INLINE static __inline__
#elif defined _MSC_VER
#define MVM_EMBED_STATIC_INLINE static __inline
#else
#define MVM_EMBED_STATIC_INLINE static
#endif

#ifdef _WIN32
#include <windows.h>
#define MVM_embed_dlopen(PATH) LoadLibraryExA(PATH, NULL, \
    LOAD_WITH_ALTERED_SEARCH_PATH)
#define MVM_embed_dlclose(LIB) !FreeLibrary((HMODULE)(LIB))
#define MVM_embed_dlsym(LIB, SYM) (void *)GetProcAddress((HMODULE)(LIB), SYM)
#else
#include <dlfcn.h>
#define MVM_embed_dlopen(PATH) dlopen(PATH, RTLD_LAZY)
#define MVM_embed_dlclose(LIB) dlclose(LIB)
#define MVM_embed_dlsym(LIB, SYM) dlsym(LIB, SYM)
#endif

typedef struct MVMInstance MoarVM;
typedef struct MVMEmbedAPIv1 MoarAPI;

struct MVMEmbedAPIv0 {
    void *lib;
    unsigned version;
};

struct MVMEmbedAPIv1 {
    void *lib;
    unsigned version;
    MoarVM *(*create)(void);
    void (*destroy)(MoarVM *vm);
    void (*exit)(MoarVM *vm);
    void (*set_exec_name)(MoarVM *vm, const char *name);
    void (*set_prog_name)(MoarVM *vm, const char *name);
    void (*set_clargs)(MoarVM *vm, int argc, char **argv);
    void (*set_lib_path)(MoarVM *vm, int count, const char **paths);
    void (*run_file)(MoarVM *vm, const char *filename);
    void (*dump_file)(MoarVM *vm, const char *filename);
    void (*add_virtual_file)(MoarVM *cm, const char *filename,
        const unsigned char *bytes, size_t size);
};

MVM_EMBED_STATIC_INLINE int MoarAPI_load(MoarAPI *api, const char *path) {
    static const MoarAPI NULLAPI = { 0 };
    int (*load)(void *, unsigned);

    *api = NULLAPI;

    api->lib = MVM_embed_dlopen(path);
    if (!api->lib)
        return 0;

    load = (int (*)(void *, unsigned))MVM_embed_dlsym(
        api->lib, "MVM_embed_load_api");

    return load && load(api, MVM_EMBED_VERSION);
}

MVM_EMBED_STATIC_INLINE int MoarAPI_unload(MoarAPI *api) {
    static const MoarAPI NULLAPI = { 0 };

    if (!api->lib)
        return 1;

    if (MVM_embed_dlclose(api->lib))
        return 0;

    *api = NULLAPI;
    return 1;
}

#endif
