MVMCompUnit * MVM_cu_from_bytes(MVMThreadContext *tc, MVMuint8 *bytes, MVMuint32 size);
MVMCompUnit * MVM_cu_map_from_file(MVMThreadContext *tc, const char *filename);
MVMCompUnit * MVM_cu_from_virtual_file(MVMThreadContext *tc, MVMString *filename);
MVMuint16 MVM_cu_callsite_add(MVMThreadContext *tc, MVMCompUnit *cu, MVMCallsite *cs);
MVMuint32 MVM_cu_string_add(MVMThreadContext *tc, MVMCompUnit *cu, MVMString *str);
