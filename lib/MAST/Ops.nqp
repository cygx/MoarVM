# This file is generated from src/core/oplist by tools/update_lib_mast_ops.p6.

class MAST::OpBanks {
    our $primitives := 0;
    our $dev := 1;
    our $string := 2;
    our $math := 3;
    our $object := 4;
    our $io := 5;
    our $processthread := 6;
}
class MAST::Ops {
    our $primitives := nqp::hash(
        'no_op', 0,
        'goto', 1,
        'if_i', 2,
        'unless_i', 3,
        'if_n', 4,
        'unless_n', 5,
        'if_s', 6,
        'unless_s', 7,
        'if_s0', 8,
        'unless_s0', 9,
        'if_o', 10,
        'unless_o', 11,
        'set', 12,
        'extend_u8', 13,
        'extend_u16', 14,
        'extend_u32', 15,
        'extend_i8', 16,
        'extend_i16', 17,
        'extend_i32', 18,
        'trunc_u8', 19,
        'trunc_u16', 20,
        'trunc_u32', 21,
        'trunc_i8', 22,
        'trunc_i16', 23,
        'trunc_i32', 24,
        'extend_n32', 25,
        'trunc_n32', 26,
        'get_lex', 27,
        'bind_lex', 28,
        'get_lex_lo', 29,
        'bind_lex_lo', 30,
        'get_lex_ni', 31,
        'get_lex_nn', 32,
        'get_lex_ns', 33,
        'get_lex_no', 34,
        'bind_lex_ni', 35,
        'bind_lex_nn', 36,
        'bind_lex_ns', 37,
        'bind_lex_no', 38,
        'return_i', 39,
        'return_n', 40,
        'return_s', 41,
        'return_o', 42,
        'return', 43,
        'const_i8', 44,
        'const_i16', 45,
        'const_i32', 46,
        'const_i64', 47,
        'const_n32', 48,
        'const_n64', 49,
        'const_s', 50,
        'add_i', 51,
        'sub_i', 52,
        'mul_i', 53,
        'div_i', 54,
        'div_u', 55,
        'mod_i', 56,
        'mod_u', 57,
        'neg_i', 58,
        'abs_i', 59,
        'inc_i', 60,
        'inc_u', 61,
        'dec_i', 62,
        'dec_u', 63,
        'getcode', 64,
        'prepargs', 65,
        'arg_i', 66,
        'arg_n', 67,
        'arg_s', 68,
        'arg_o', 69,
        'invoke_v', 70,
        'invoke_i', 71,
        'invoke_n', 72,
        'invoke_s', 73,
        'invoke_o', 74,
        'add_n', 75,
        'sub_n', 76,
        'mul_n', 77,
        'div_n', 78,
        'neg_n', 79,
        'abs_n', 80,
        'eq_i', 81,
        'ne_i', 82,
        'lt_i', 83,
        'le_i', 84,
        'gt_i', 85,
        'ge_i', 86,
        'eq_n', 87,
        'ne_n', 88,
        'lt_n', 89,
        'le_n', 90,
        'gt_n', 91,
        'ge_n', 92,
        'argconst_i', 93,
        'argconst_n', 94,
        'argconst_s', 95,
        'checkarity', 96,
        'param_rp_i', 97,
        'param_rp_n', 98,
        'param_rp_s', 99,
        'param_rp_o', 100,
        'param_op_i', 101,
        'param_op_n', 102,
        'param_op_s', 103,
        'param_op_o', 104,
        'param_rn_i', 105,
        'param_rn_n', 106,
        'param_rn_s', 107,
        'param_rn_o', 108,
        'param_on_i', 109,
        'param_on_n', 110,
        'param_on_s', 111,
        'param_on_o', 112
    );
    our $dev := nqp::hash(
        'say_i', 0,
        'say_s', 1,
        'say_n', 2,
        'sleep', 3,
        'anonoshtype', 4
    );
    our $string := nqp::hash(
        'concat_s', 0,
        'repeat_s', 1,
        'substr_s', 2,
        'index_s', 3,
        'graphs_s', 4,
        'codes_s', 5,
        'eq_s', 6,
        'ne_s', 7,
        'eqat_s', 8,
        'haveat_s', 9,
        'getcp_s', 10,
        'setcp_s', 11,
        'indexcp_s', 12
    );
    our $math := nqp::hash(
        'sin_n', 0,
        'asin_n', 1,
        'cos_n', 2,
        'acos_n', 3,
        'tan_n', 4,
        'atan_n', 5,
        'atan2_n', 6,
        'sec_n', 7,
        'asec_n', 8,
        'sinh_n', 9,
        'cosh_n', 10,
        'tanh_n', 11,
        'sech_n', 12
    );
    our $object := nqp::hash(
        'knowhow', 0,
        'findmeth', 1,
        'findmeth_s', 2,
        'can', 3,
        'can_s', 4,
        'create', 5,
        'gethow', 6,
        'getwhat', 7,
        'reprid', 8,
        'concrete', 9
    );
    our $io := nqp::hash(
        'copy_f', 0,
        'append_f', 1,
        'rename_f', 2,
        'delete_f', 3,
        'chmod_f', 4,
        'exists_f', 5,
        'mkdir', 6,
        'rmdir', 7,
        'open_dir', 8,
        'read_dir', 9,
        'close_dir', 10,
        'open_fh', 11,
        'close_fh', 12,
        'read_fhs', 13,
        'read_fhbuf', 14,
        'slurp', 15,
        'spew', 16,
        'write_fhs', 17,
        'write_fhbuf', 18,
        'seek_fh', 19,
        'lock_fh', 20,
        'unlock_fh', 21,
        'flush_fh', 22,
        'sync_fh', 23,
        'pipe_fh', 24,
        'trunc_fh', 25,
        'eof_fh', 26,
        'getstdin', 27,
        'getstdout', 28,
        'getstderr', 29,
        'connect_sk', 30,
        'close_sk', 31,
        'bind_sk', 32,
        'send_sks', 33,
        'send_skbuf', 34,
        'recv_sks', 35,
        'recv_skbuf', 36,
        'getaddr_sk', 37,
        'hostname', 38,
        'nametoaddr', 39,
        'addrtoname', 40,
        'porttosvc', 41
    );
    our $processthread := nqp::hash(
        'getenv', 0,
        'setenv', 1,
        'delenv', 2,
        'nametogid', 3,
        'gidtoname', 4,
        'nametouid', 5,
        'uidtoname', 6,
        'getusername', 7,
        'getuid', 8,
        'getgid', 9,
        'gethomedir', 10,
        'getencoding', 11,
        'procshell', 12,
        'procshellbg', 13,
        'procrun', 14,
        'procrunbg', 15,
        'prockill', 16,
        'procwait', 17,
        'procalive', 18,
        'detach', 19,
        'daemonize', 19
    );
}
