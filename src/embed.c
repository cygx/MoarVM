#include "moar.h"
#include "moarembed.h"

MVM_PUBLIC int MVM_embed_load_api(void *api, unsigned version) {
    if(version > MVM_EMBED_VERSION)
        version = MVM_EMBED_VERSION;

    switch (version) {
        case 1: {
            struct MVMEmbedAPIv1 *v1 = api;
            v1->create = MVM_vm_create_instance;
            v1->destroy = MVM_vm_destroy_instance;
            v1->exit = MVM_vm_exit;
            v1->set_exec_name = MVM_vm_set_exec_name;
            v1->set_prog_name = MVM_vm_set_prog_name;
            v1->set_clargs = MVM_vm_set_clargs;
            v1->set_lib_path = MVM_vm_set_lib_path;
            v1->run_file = MVM_vm_run_file;
            v1->dump_file = MVM_vm_dump_file;
            /* fallthrough */
        }

        case 0: {
            struct MVMEmbedAPIv1 *v0 = api;
            v0->version = version;
            return 1;
        }

        default:
        return 0;
    }
}
