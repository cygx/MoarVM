#include "moar.h"

#if MVM_PTR_SIZE == 4
typedef MVMuint32 MVMuintptr;
#elif MVM_PTR_SIZE == 8
typedef MVMuint64 MVMuintptr;
#else
#error "unsupported pointer size"
#endif

void MVM_mem_read(MVMThreadContext *tc, MVMObject *buffer,
        MVMuint64 offset, MVMuint64 count, MVMint64 address)
{
    MVMArrayBody *body;

    if (REPR(buffer)->ID != MVM_REPR_ID_VMArray) {
        MVM_exception_throw_adhoc(tc,
                "can only read memory into objects with VMArray REPR");
    }

    if (!IS_CONCRETE(buffer)) {
        MVM_exception_throw_adhoc(tc, "cannot read memory into type objects");
    }

    body = &((MVMArray *)buffer)->body;
    if (offset + count > body->elems) {
        REPR(buffer)->pos_funcs.set_elems(tc,
            STABLE(buffer), buffer, body, offset + count);
    }

    {
        MVMArrayREPRData *data = (MVMArrayREPRData *)STABLE(buffer)->REPR_data;
        size_t elem_size = data->elem_size;
        void *dest = body->slots.u8 + (body->start + offset) * elem_size;
        const void *src = (const void *)(MVMuintptr)(MVMuint64)address;
        memcpy(dest, src, count * elem_size);
    }
}

void MVM_mem_write(MVMThreadContext *tc, MVMObject *buffer,
        MVMuint64 offset, MVMuint64 count, MVMint64 address)
{
    MVMArrayBody *body;

    if (REPR(buffer)->ID != MVM_REPR_ID_VMArray) {
        MVM_exception_throw_adhoc(tc,
                "can only write memory from objects with VMArray REPR");
    }

    if (!IS_CONCRETE(buffer)) {
        MVM_exception_throw_adhoc(tc, "cannot write memory from type objects");
    }

    body = &((MVMArray *)buffer)->body;
    if (offset + count > body->elems) {
        MVM_exception_throw_adhoc(tc,
                "requested %" PRIu64 " elements but only got %" PRIu64,
                offset + count, body->elems);
    }

    {
        MVMArrayREPRData *data = (MVMArrayREPRData *)STABLE(buffer)->REPR_data;
        size_t elem_size = data->elem_size;
        void *dest = (void *)(MVMuintptr)(MVMuint64)address;
        const void *src = body->slots.u8 + (body->start + offset) * elem_size;
        memcpy(dest, src, count * elem_size);
    }
}
